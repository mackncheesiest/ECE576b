#include <systemc.h>

SC_MODULE(hello_world) {
  SC_CTOR(hello_world) {
    SC_THREAD(main_thread); // register the process
  }

  void main_thread() {
    cout << "Hello SystemC!\n";
  }
};

int sc_main(int argc, char** argv) {
  hello_world hello("asdlf");

  sc_start();
  return(0);
}
