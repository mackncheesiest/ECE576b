#include <systemc.h>
#include "iomanip"

//Compile: g++ -I. -I$SYSTEMC/include -L. -L$SYSTEMC/lib-linux64 -lsystemc alu.cpp
//or just "make" (assuming the sample Makefile is also downloaded
//after compiling, test with: "./alu_withMem dataFile.txt <number>
//dataFile.txt is an input file with whitespace separated integer numbers and <number> is 0, 1, or 2 to represent +, -, or *

//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//

// Toggle each of these to enable or disable debug printing for the Memory RTL, Memory, and SAD components respectively

//#define RTL_DEBUG(STR) (cout << "[Memory RTL] " << STR << endl)
#define RTL_DEBUG(STR) 

//#define MEMORY_DEBUG(STR) (cout << "[Memory Bus] " << STR << endl)
#define MEMORY_DEBUG(STR)

//#define SAD_DEBUG(STR) (cout << "[SAD] " << STR << endl)
#define SAD_DEBUG(STR) 

//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//

// Define the main parameters to be used in the SAD execution

#define NUM_BLOCKS 64
#define BLOCK_SIZE 64
#define INPUT1_ADDR 0
#define INPUT2_ADDR 4096
#define OUTPUT_ADDR 8192

#define MEM_SIZE 65789

// Define the memory interface used by the SAD component. This will be bound to the Memory module later
class simple_mem_if : virtual public sc_interface
{
public:
    virtual bool Write(unsigned int addr, unsigned int data) = 0;
    virtual bool Read(unsigned int addr, unsigned int& data) = 0;
};

//--------------------------------------------------------------------------//

// "RTL" model of the memory component as a standalone SystemC module that can integrate into the wrapper "Memory" bus component
class MEMORY_RTL : public sc_module
{
public:
	// TODO: Figure out how to make these work as sc_in and sc_out again and simplify that terribly ugly MEMORY_RTL constructor
	//  For future reference, though, the main reason these were all converted to "&" references and passed in via the constructor is that it seemed to be the case that
	//  the signals defined in the Memory component were being passed by value rather than by reference, and as such, events on signals in the Memory module weren't causing events in the Memory RTL (like the clock oscillating)
	sc_signal<sc_logic> &clk;
	sc_signal<sc_logic> &Ren, &Wen;
	sc_signal<int> &Addr;
	sc_signal<int> &DataIn;
	sc_signal<int> &DataOut;
	sc_signal<sc_logic> &Ack;
	
	unsigned int memData[MEM_SIZE];
	
	SC_HAS_PROCESS(MEMORY_RTL);

	MEMORY_RTL(sc_module_name name, char* memInitFilename, 
			   sc_signal<sc_logic> &clk, sc_signal<sc_logic> &Ren, sc_signal<sc_logic> &Wen, 
			   sc_signal<int> &Addr, sc_signal<int> &DataIn, sc_signal<int> &DataOut, sc_signal<sc_logic> &Ack) : 
		sc_module(name), clk(clk), Ren(Ren), Wen(Wen), Addr(Addr), DataIn(DataIn), DataOut(DataOut), Ack(Ack) 
	{	
		// Spawn a "thread" to run the RTL functionality, and make it sensitive to only the posedge of the clock 
		SC_THREAD(rtl);
		sensitive << clk.posedge_event();

		char* memFilename = memInitFilename;
        
		unsigned int initData;
		unsigned int initLocation;
		
		// initialize memory contents from file
		ifstream ifs(memFilename, ifstream::in);
		
		//check if able to read memory file
		if(!ifs.good()) { 
			cout << "[Memory RTL - Error] Could not open memory initialization file: " << memFilename << "." << endl;
			cout << flush;
			sc_stop();
		}

		initLocation = 0;
		
		//read memory file into memData memory array.
		while((ifs >> initData) && initLocation < MEM_SIZE) {		
				MEMORY_DEBUG("Initializing address " << initLocation << " with value " << initData);	
				memData[initLocation] = initData;
				initLocation++;
		}
		ifs.close();
		
	}

	void rtl() {
		while (true) {
			// Wait for the posedge of the clock
			wait();
			
			RTL_DEBUG("Memory RTL triggered. The inputs I currently have are...");
			RTL_DEBUG("Addr: " << Addr << ", Ren: " << Ren << ", Wen: " << Wen << ", DataIn: " << DataIn);

			if (Addr < MEM_SIZE) { 	
				Ack = SC_LOGIC_1;

				if (Ren == SC_LOGIC_1) {
					RTL_DEBUG("Reading data from memData");
					DataOut = memData[Addr];
				}
				if (Wen == SC_LOGIC_1) {
					RTL_DEBUG("Writing data to memData");
					memData[Addr] = DataIn;
				} else {
					RTL_DEBUG("Both Ren and Wen were disabled");
				}
			} else {
				Ack = SC_LOGIC_0;
			}

			// Cause a SystemC "delta-cycle" timestep such that the value modifications here are committed
			// https://learnsystemc.com/basic/delta_cycle
			wait(SC_ZERO_TIME);
			RTL_DEBUG("By the end of execution, my outputs are - Ack: " << Ack << ", DataOut: " << DataOut);
		}
	}
};

// Wrapper "Memory" bus component that provides an interface for the SAD module to access the MEMORY_RTL module
class Memory : public sc_channel, public simple_mem_if {
public:
	sc_signal<sc_logic> clk;
	sc_signal<sc_logic> Ack;
	sc_signal<sc_logic> Ren;
	sc_signal<sc_logic> Wen;
	sc_signal<int> Addr;
	sc_signal<int> DataIn;
	sc_signal<int> DataOut;
	
	SC_HAS_PROCESS(Memory);
	
    Memory(sc_module_name name, char* memInitFilename) : sc_module(name) {
		// TODO: Fix ugly constructor :(
		// See the more detailed comment on the corresponding MEMORY_RTL module
		MEMORY_RTL mem_rtl("Memory_RTL", memInitFilename, clk, Ren, Wen, Addr, DataIn, DataOut, Ack);

		// Spawn the clock "thread" that drives operation of the MEMORY_RTL
		SC_THREAD(oscillator);
    }

	void oscillator() {
		while(true) {
			clk.write(SC_LOGIC_0);
			wait(2, SC_NS);
			clk.write(SC_LOGIC_1);
			wait(2, SC_NS);
		}
	}
	
	// Provide the write interface implementation that binds to the virtual "Write" function on simple_mem_if
	bool Write(unsigned int addr, unsigned int data) {
		MEMORY_DEBUG("Beginning a write event, setting the input signals and waiting for memory RTL response");

		Ren=SC_LOGIC_0;
		Wen=SC_LOGIC_1;
		Addr=addr;
		DataIn=data;

		wait(clk.posedge_event());
		wait(clk.negedge_event());

		MEMORY_DEBUG("Wait complete, de-asserting write-enable and checking if the write was successful");

		Wen = SC_LOGIC_0;

		if (Ack == SC_LOGIC_1) {
			MEMORY_DEBUG("Write was successful!");
			return true;
		}
		else {
			MEMORY_DEBUG("Write failed!");
			return false;
		}
    }
	
	// Provide the read interface implementation that binds to the virtual "Read" function on simple_mem_if
    bool Read(unsigned int addr, unsigned int& data) {
		MEMORY_DEBUG("Beginning a read event, setting the input signals and waiting for memory RTL response");

		Ren = SC_LOGIC_1;
		Wen = SC_LOGIC_0;
		Addr = addr;

		wait(clk.posedge_event());
		wait(clk.negedge_event());

		MEMORY_DEBUG("Wait complete, de-asserting read-enable and checking if the write was successful");

		Ren = SC_LOGIC_0;

		if (Ack == SC_LOGIC_1) {
			data = DataOut;
			MEMORY_DEBUG("Read was successful!");
			return true;
		}
		else {
			data = 0;
			MEMORY_DEBUG("Read failed!");
			return false;
		}
    }
};

//--------------------------------------------------------------------------//


// Top level "SAD" module that drives the actual computations and memory accesses being performed
class sad : public sc_module {
public:
	int i, v;
	int addr1, addr2;
	unsigned int dataA, dataB;
	unsigned int block;
	unsigned int sad_value;
	unsigned int offset;

	sc_port<simple_mem_if> bus; // Instantiate the bus interface that will connect our SAD with the Memory

	SC_HAS_PROCESS(sad); // Because we're using a custom constructor rather than SC_CTOR, SC_HAS_PROCESS must be used instead

	sad(sc_module_name name) : sc_module(name) {
		// As an SC_THREAD, this will only run once, but that's fine for our needs
		// However, it is still important that this thread call sc_stop when it completes, as otherwise
		// SystemC doesn't know that it needs to kill the clock process running as a part of the Memory module
		SC_THREAD(sad_main);
	}

	void sad_main() {
		for (block = 0; block < NUM_BLOCKS; block++) {
			sad_value = 0;
			for (i = 0; i < BLOCK_SIZE; i++) {
				// TODO: Does this computation need delay?
				offset = (block * BLOCK_SIZE) + i;

				addr1 = INPUT1_ADDR + offset;
				wait(10, SC_NS);
				addr2 = INPUT2_ADDR + offset;
				wait(10, SC_NS);
				
				SAD_DEBUG("Triggering read for addr1: " << addr1);
				if (!bus->Read(addr1, dataA)) {
					cout << "Error: Invalid input 1 data!! " << endl;
					sc_stop();
				}
				SAD_DEBUG("Read the value: " << dataA << " from address " << addr1 << " of the Memory interface");

				SAD_DEBUG("Triggering read for addr2: " << addr2);
				if(!bus->Read(addr2, dataB)) {
					cout << "Error: Invalid input 2 data!! " << endl;
					sc_stop();
				}
				SAD_DEBUG("Read the value: " << dataB << " from address " << addr2 << " of the Memory interface");

				v = dataA - dataB;

				SAD_DEBUG("Their difference is " << v);

				wait(10, SC_NS);
				
				if (v < 0) {
					v = -v;
					wait(10, SC_NS);
				}
				
				SAD_DEBUG("Their absolute difference is " << v);

				SAD_DEBUG("Updating sad_value from " << sad_value << " to " << (sad_value + v));
				sad_value += v;
				wait(10, SC_NS);
			}

			cout << " SAD value is: " << sad_value<< endl;
			
			SAD_DEBUG("Attempting to write output value " << sad_value << " to address " << OUTPUT_ADDR);
			if (!bus->Write(OUTPUT_ADDR, sad_value)) {

				cout << "Invalid write address for the ALU result!!" << endl;
				cout << "Stop the f*cking simulation!!!" << endl;
				sc_stop();
			} 
		}
		cout << "SAD computation complete! Halting SystemC simulation..." << endl;
		sc_stop();
	}
};

class Top : public sc_module {
public:
	Memory memory_0;
    sad sad_0;
	   
    Top(sc_module_name name, char* memInitFilename) : sc_module(name), sad_0("SAD"), memory_0("Memory_Bus", memInitFilename) {	
		sad_0.bus(memory_0);
    }
};

int sc_main(int argc, char* argv[]) {
	Top* top_0;

	if (argc < 2) {
		cout << endl;
		cout << "Usage: " << std::string(argv[0]) << " memfile" << endl;
		cout << endl;
		return -1;
	}

	top_0 = new Top("Top_0", argv[1]);

	sc_start();
	return 0;
}