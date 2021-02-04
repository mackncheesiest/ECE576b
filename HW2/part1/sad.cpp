#include <systemc.h>

#define NUM_BLOCKS 64
#define BLOCK_SIZE 64
#define INPUT1_ADDR 0
#define INPUT2_ADDR 16384
#define SAD_OUTPUT_ADDR 32768

#define MEM_SIZE 65536

struct simple_mem_if : virtual public sc_interface {
  public:
    virtual bool Write(unsigned int addr, unsigned int data) = 0;
    virtual bool Read(unsigned int addr, unsigned int& data) = 0;
};

struct sad : virtual public sc_module {
  int i, v;
  unsigned int block;
  unsigned int sad_val;
  unsigned int offset;

  SC_CTOR(sad) {
    SC_THREAD(sad_main);
  }

  void sad_main() {
    for (block = 0; block < NUM_BLOCKS; block++) {
      sad_val = 0;
      for (i = 0; i < BLOCK_SIZE; i++) {
        offset = (block * BLOCK_SIZE) + i;
        // so is MEM an instance of the simple_mem_if???
        v = MEM[INPUT1_ADDR + offset] - MEM[INPUT2_ADDR + offset];
        if (v < 0) {
          v = -v;
        }
        sad_value += v;
      }
      MEM[SAD_OUTPUT_ADDR + block] = sad;
    }
  }
};

struct memory : virtual public sc_module {
  unsigned int memory[MEM_SIZE];

  SC_CTOR(memory) {
    SC_THREAD(memory_main);
  }

  // do memory things
  void memory_main() {

  }
};

