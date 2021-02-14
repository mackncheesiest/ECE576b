#include <systemc.h>
#include "iomanip"

//Compile: g++ -I. -I$SYSTEMC/include -L. -L$SYSTEMC/lib-linux64 -lsystemc alu.cpp
//or just "make" (assuming the sample Makefile is also downloaded
//after compiling, test with: "./alu_withMem dataFile.txt <number>
//dataFile.txt is an input file with whitespace separated integer numbers and <number> is 0, 1, or 2 to represent +, -, or *



//--------------------------------------------------------------------------//


#define NUM_BLOCKS 64
#define BLOCK_SIZE 64
#define INPUT1_ADDR 0
#define INPUT2_ADDR 4096
#define OUTPUT_ADDR 8192

#define MEM_SIZE 65789

// simple memory interface
class simple_mem_if : virtual public sc_interface
{
public:
    virtual bool Write(unsigned int addr, unsigned int data) = 0;
    virtual bool Read(unsigned int addr, unsigned int& data) = 0;
};

//--------------------------------------------------------------------------//

// Untimed memory implementation that reads whitespace-separated integer data from a file



class MEMORY_RTL: public sc_module
{
public:
	sc_in<sc_logic> clk;
	sc_in<sc_logic> Ren, Wen;
	sc_in<int> Addr;
	sc_in<int> DataIn;
	sc_out<int> DataOut;
	sc_out<sc_logic> Ack;
	
	unsigned int  memData[MEM_SIZE];
	
	SC_HAS_PROCESS(MEMORY_RTL);

	MEMORY_RTL(sc_module_name name, char* memInitFilename) :sc_module(name)
	{	
		SC_METHOD(rtl);
		//sensitive << clk.pos();
		
		char* memFilename = memInitFilename;
        
		unsigned int initData;
		unsigned int initLocation;
		
		// initiliaze memory to 0
		for(int i=0; i<MEM_SIZE; i++) { memData[i] = 0; }
		
		// initialize memory contents from file
		ifstream ifs(memFilename, ifstream::in);
		
		//check if able to read memory file
		if(!ifs.good()) { 
			cout << "Warning: Could not open memory initialization file: " << memFilename << "." << endl;
			cout << "Memory contents initialized to all 0s." << endl << endl; 
			cout << flush;
		}

		initLocation = 0;
		
		//read memory file into memData memory array.
		while((ifs >> initData) && initLocation < MEM_SIZE) {			
				memData[initLocation] = initData;
				initLocation++;
		}
		ifs.close();
		
	}
	void rtl()
	{ 
		//memory behaviors here}
		if(Ren == SC_LOGIC_1)
		{
			DataOut = memData[Addr];
		}
		if(Wen == SC_LOGIC_1)
		{
			memData[Addr] = DataIn;
		}
		if( Addr < MEM_SIZE ) { 
			Ack = SC_LOGIC_1;
		}
		else{
			Ack = SC_LOGIC_0;
		}
	}
		
};

class Memory : public sc_channel, public simple_mem_if
{
private:
    int memData[MEM_SIZE];
	//char* memFilename;
public:
	sc_signal<sc_logic> clk;
	//sc_clock clk("my_clock",1,0.5);
	sc_signal<sc_logic> Ack;
	sc_signal<sc_logic> Ren;
	sc_signal<sc_logic> Wen;
	sc_signal<int> Addr;
	sc_signal<int> DataIn;
	sc_signal<int> DataOut;
	
	SC_HAS_PROCESS(Memory);
	
    Memory(sc_module_name name, char* memInitFilename) : sc_module(name) 
    {
		MEMORY_RTL mem_rtl("NewMemory1", memInitFilename);
		mem_rtl.clk (clk);
		mem_rtl.Ren (Ren);
		mem_rtl.Wen (Wen);
		mem_rtl.Ack (Ack);
		mem_rtl.Addr (Addr);
		mem_rtl.DataIn (DataIn);
		mem_rtl.DataOut (DataOut);
		SC_THREAD(oscillator);

    }
	void oscillator(){

		while(true) {
			clk.write(SC_LOGIC_0);
			wait(2, SC_NS);
			clk.write(SC_LOGIC_1);
			wait(2, SC_NS);
		}
	}
	
//using the interface	
public:
	bool Write(unsigned int addr, unsigned int data)  //write interface
	{
		Ren=SC_LOGIC_0;
		Wen=SC_LOGIC_1;
		Addr=addr;
		DataIn=data;
		if(Ack==SC_LOGIC_1)
		{
		return true;
		}
		else{
			return false;
		}
		//mem_rtl.rtl();
		//return Ack;
		/*mem_rtl->Wen (Wen);
		mem_rtl->Ren (Wen);
		mem_rtl->Addr (addr);
		mem_rtl->DataIn =data;*/
		//if( addr >= MEM_SIZE ) { return false; } //make sure the address is valid  
        //memData[addr] = data;
		
		//This is totally unnecessary, but writes the memory data written to the memory from the ALU to an output file
		/*ofstream outputFile;
		outputFile.open ("output.txt");
		outputFile << memData[addr];
		outputFile.close();*/
		
	
    }
	
    bool Read(unsigned int addr, unsigned int& data)  //read interface
	{
		Ren=SC_LOGIC_1;
		Wen=SC_LOGIC_0;

		Addr=addr;
		//mem_rtl.rtl();
		
		data=DataOut;
		if(Ack==SC_LOGIC_1)
		{
		return true;
		}
		else{
			return false;
		}
		
		/*if( addr >= MEM_SIZE ) { return false; }
        data = memData[addr];*/

		//return true;
    }
	

	
};

//--------------------------------------------------------------------------//

class sad : public sc_module {

public:
	int i, v;
	int addr1, addr2;
	unsigned int dataA, dataB;
	unsigned int block;
	unsigned int sad_value;
	unsigned int offset;

public:
	SC_HAS_PROCESS(sad); //alternative constructor to SC_CTOR

public:
	sad(sc_module_name name) : sc_module(name) { //constructor definition; name: instance name
		SC_THREAD(sad_main);//Changed this to a thread to run through just once
	}

public:
	void sad_main() {
		for (block = 0; block < NUM_BLOCKS; block++) {
			sad_value = 0;
			for (i = 0; i < BLOCK_SIZE; i++) {
				offset = (block * BLOCK_SIZE) + i;
				// so is MEM an instance of the simple_mem_if???
				addr1 = INPUT1_ADDR + offset;
				wait(10, SC_NS);
				//cout << " ADDR 1 for the ALU is: " << addr1 << endl;
				addr2 = INPUT2_ADDR + offset;
				wait(10, SC_NS);
				//cout << " ADDR 2 for the ALU is: " << addr2 << endl;
				if(!bus->Read(addr1, dataA)) { //read the data in INPUT1_ADDR via the Read port of the interface
					cout << "Error: Invalid input 1 data!! " << endl;
					sc_stop();
				}
				//cout << " DataA for the ALU is: " << dataA<< endl;
		//cout << " INPUT 1 for the ALU is: " << dataA << endl;

				if(!bus->Read(addr2, dataB)) {
					cout << "Error: Invalid input 2 data!! " << endl;
					sc_stop();
				}
				//cout << " DataB for the ALU is: " << dataB << endl;
				v = dataA - dataB;
				if (block == 0) {
					//cout << "For block 0, our addr1 is " << addr1 << endl;
					//cout << "For block 0, our addr2 is " << addr2 << endl;
				}
				wait(10, SC_NS);
				//v = MEM[INPUT1_ADDR + offset] - MEM[INPUT2_ADDR + offset];
				if (v < 0) {
				v = -v;
				wait(10, SC_NS);
				}
				sad_value += v;
				wait(10, SC_NS);
			}
			cout << " SAD value is: " << sad_value<< endl;
			if(!bus->Write(OUTPUT_ADDR, sad_value)) {
				cout << "Invalid write address for the ALU result!!" << endl;
				cout << "Stop the f*cking simulation!!!" << endl;
				sc_stop();
		} 
	}
	//sc_stop();
	//outputFile.close();
}
public:
	sc_port<simple_mem_if> bus; //instantiate and use the interface on the ALU
};



class Top : public sc_module
{
public:
	Memory memory_0;
    sad sad_0;
	   
public:
    Top(sc_module_name name, char* memInitFilename) : sc_module(name), sad_0("sad"), memory_0("Memory_0", memInitFilename) {	

		sad_0.bus(memory_0);
    }
};



//main function
/*This is equivalent to the top module in Verilog, where the main components and signals are
connected together. This main program also includes a testbench to generate test data for execution.
Here, we assemble the system components, bind the system ports, and drive data in and out of the modules.*/

int sc_main(int argc, char* argv[]) {
		
	Top* top_0;
	
	top_0 = new Top("Top_0", argv[1]);
		
	
	sc_start();
	return 0;
}