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
extern "C" void activity_kernel(int, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *);
extern "C" void apatb_activity_kernel_hw(int __xlx_apatb_param_len, volatile void * __xlx_apatb_param_hr, volatile void * __xlx_apatb_param_t, volatile void * __xlx_apatb_param_meanhr, volatile void * __xlx_apatb_param_tpower, volatile void * __xlx_apatb_param_stationarity, volatile void * __xlx_apatb_param_activity, volatile void * __xlx_apatb_param_acmin, volatile void * __xlx_apatb_param_hrmin, volatile void * __xlx_apatb_param_stmin, volatile void * __xlx_apatb_param_tpmin, volatile void * __xlx_apatb_param_tmin0, volatile void * __xlx_apatb_param_tmin1) {
  // DUT call
  activity_kernel(__xlx_apatb_param_len, __xlx_apatb_param_hr, __xlx_apatb_param_t, __xlx_apatb_param_meanhr, __xlx_apatb_param_tpower, __xlx_apatb_param_stationarity, __xlx_apatb_param_activity, __xlx_apatb_param_acmin, __xlx_apatb_param_hrmin, __xlx_apatb_param_stmin, __xlx_apatb_param_tpmin, __xlx_apatb_param_tmin0, __xlx_apatb_param_tmin1);
}
