#include <systemc>
#include <vector>
#include <iostream>
#include "hls_stream.h"
#include "ap_int.h"
#include "ap_fixed.h"
using namespace std;
using namespace sc_dt;
class AESL_RUNTIME_BC {
  public:
    AESL_RUNTIME_BC(const char* name) {
      file_token.open( name);
      if (!file_token.good()) {
        cout << "Failed to open tv file " << name << endl;
        exit (1);
      }
      file_token >> mName;//[[[runtime]]]
    }
    ~AESL_RUNTIME_BC() {
      file_token.close();
    }
    int read_size () {
      int size = 0;
      file_token >> mName;//[[transaction]]
      file_token >> mName;//transaction number
      file_token >> mName;//pop_size
      size = atoi(mName.c_str());
      file_token >> mName;//[[/transaction]]
      return size;
    }
  public:
    fstream file_token;
    string mName;
};
extern "C" void rijndaelDecrypt_hls(int*, char*, char*);
extern "C" void apatb_rijndaelDecrypt_hls_hw(volatile void * __xlx_apatb_param_rk, volatile void * __xlx_apatb_param_ct, volatile void * __xlx_apatb_param_pt) {
  // Collect __xlx_rk__tmp_vec
  vector<sc_bv<32> >__xlx_rk__tmp_vec;
  for (int j = 0, e = 44; j != e; ++j) {
    __xlx_rk__tmp_vec.push_back(((int*)__xlx_apatb_param_rk)[j]);
  }
  int __xlx_size_param_rk = 44;
  int __xlx_offset_param_rk = 0;
  int __xlx_offset_byte_param_rk = 0*4;
  int* __xlx_rk__input_buffer= new int[__xlx_rk__tmp_vec.size()];
  for (int i = 0; i < __xlx_rk__tmp_vec.size(); ++i) {
    __xlx_rk__input_buffer[i] = __xlx_rk__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_ct__tmp_vec
  vector<sc_bv<8> >__xlx_ct__tmp_vec;
  for (int j = 0, e = 16; j != e; ++j) {
    __xlx_ct__tmp_vec.push_back(((char*)__xlx_apatb_param_ct)[j]);
  }
  int __xlx_size_param_ct = 16;
  int __xlx_offset_param_ct = 0;
  int __xlx_offset_byte_param_ct = 0*1;
  char* __xlx_ct__input_buffer= new char[__xlx_ct__tmp_vec.size()];
  for (int i = 0; i < __xlx_ct__tmp_vec.size(); ++i) {
    __xlx_ct__input_buffer[i] = __xlx_ct__tmp_vec[i].range(7, 0).to_uint64();
  }
  // Collect __xlx_pt__tmp_vec
  vector<sc_bv<8> >__xlx_pt__tmp_vec;
  for (int j = 0, e = 16; j != e; ++j) {
    __xlx_pt__tmp_vec.push_back(((char*)__xlx_apatb_param_pt)[j]);
  }
  int __xlx_size_param_pt = 16;
  int __xlx_offset_param_pt = 0;
  int __xlx_offset_byte_param_pt = 0*1;
  char* __xlx_pt__input_buffer= new char[__xlx_pt__tmp_vec.size()];
  for (int i = 0; i < __xlx_pt__tmp_vec.size(); ++i) {
    __xlx_pt__input_buffer[i] = __xlx_pt__tmp_vec[i].range(7, 0).to_uint64();
  }
  // DUT call
  rijndaelDecrypt_hls(__xlx_rk__input_buffer, __xlx_ct__input_buffer, __xlx_pt__input_buffer);
// print __xlx_apatb_param_rk
  sc_bv<32>*__xlx_rk_output_buffer = new sc_bv<32>[__xlx_size_param_rk];
  for (int i = 0; i < __xlx_size_param_rk; ++i) {
    __xlx_rk_output_buffer[i] = __xlx_rk__input_buffer[i+__xlx_offset_param_rk];
  }
  for (int i = 0; i < __xlx_size_param_rk; ++i) {
    ((int*)__xlx_apatb_param_rk)[i] = __xlx_rk_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_ct
  sc_bv<8>*__xlx_ct_output_buffer = new sc_bv<8>[__xlx_size_param_ct];
  for (int i = 0; i < __xlx_size_param_ct; ++i) {
    __xlx_ct_output_buffer[i] = __xlx_ct__input_buffer[i+__xlx_offset_param_ct];
  }
  for (int i = 0; i < __xlx_size_param_ct; ++i) {
    ((char*)__xlx_apatb_param_ct)[i] = __xlx_ct_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_pt
  sc_bv<8>*__xlx_pt_output_buffer = new sc_bv<8>[__xlx_size_param_pt];
  for (int i = 0; i < __xlx_size_param_pt; ++i) {
    __xlx_pt_output_buffer[i] = __xlx_pt__input_buffer[i+__xlx_offset_param_pt];
  }
  for (int i = 0; i < __xlx_size_param_pt; ++i) {
    ((char*)__xlx_apatb_param_pt)[i] = __xlx_pt_output_buffer[i].to_uint64();
  }
}
