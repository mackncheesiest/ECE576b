#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

// wrapc file define:
#define AUTOTB_TVIN_len "../tv/cdatafile/c.activity_kernel.autotvin_len.dat"
#define AUTOTB_TVOUT_len "../tv/cdatafile/c.activity_kernel.autotvout_len.dat"
// wrapc file define:
#define AUTOTB_TVIN_hr "../tv/cdatafile/c.activity_kernel.autotvin_hr.dat"
#define AUTOTB_TVOUT_hr "../tv/cdatafile/c.activity_kernel.autotvout_hr.dat"
// wrapc file define:
#define AUTOTB_TVIN_t "../tv/cdatafile/c.activity_kernel.autotvin_t.dat"
#define AUTOTB_TVOUT_t "../tv/cdatafile/c.activity_kernel.autotvout_t.dat"
// wrapc file define:
#define AUTOTB_TVIN_meanhr "../tv/cdatafile/c.activity_kernel.autotvin_meanhr.dat"
#define AUTOTB_TVOUT_meanhr "../tv/cdatafile/c.activity_kernel.autotvout_meanhr.dat"
// wrapc file define:
#define AUTOTB_TVIN_tpower "../tv/cdatafile/c.activity_kernel.autotvin_tpower.dat"
#define AUTOTB_TVOUT_tpower "../tv/cdatafile/c.activity_kernel.autotvout_tpower.dat"
// wrapc file define:
#define AUTOTB_TVIN_stationarity "../tv/cdatafile/c.activity_kernel.autotvin_stationarity.dat"
#define AUTOTB_TVOUT_stationarity "../tv/cdatafile/c.activity_kernel.autotvout_stationarity.dat"
// wrapc file define:
#define AUTOTB_TVIN_activity "../tv/cdatafile/c.activity_kernel.autotvin_activity.dat"
#define AUTOTB_TVOUT_activity "../tv/cdatafile/c.activity_kernel.autotvout_activity.dat"
// wrapc file define:
#define AUTOTB_TVIN_acmin "../tv/cdatafile/c.activity_kernel.autotvin_acmin.dat"
#define AUTOTB_TVOUT_acmin "../tv/cdatafile/c.activity_kernel.autotvout_acmin.dat"
// wrapc file define:
#define AUTOTB_TVIN_hrmin "../tv/cdatafile/c.activity_kernel.autotvin_hrmin.dat"
#define AUTOTB_TVOUT_hrmin "../tv/cdatafile/c.activity_kernel.autotvout_hrmin.dat"
// wrapc file define:
#define AUTOTB_TVIN_stmin "../tv/cdatafile/c.activity_kernel.autotvin_stmin.dat"
#define AUTOTB_TVOUT_stmin "../tv/cdatafile/c.activity_kernel.autotvout_stmin.dat"
// wrapc file define:
#define AUTOTB_TVIN_tpmin "../tv/cdatafile/c.activity_kernel.autotvin_tpmin.dat"
#define AUTOTB_TVOUT_tpmin "../tv/cdatafile/c.activity_kernel.autotvout_tpmin.dat"
// wrapc file define:
#define AUTOTB_TVIN_tmin0 "../tv/cdatafile/c.activity_kernel.autotvin_tmin0.dat"
#define AUTOTB_TVOUT_tmin0 "../tv/cdatafile/c.activity_kernel.autotvout_tmin0.dat"
// wrapc file define:
#define AUTOTB_TVIN_tmin1 "../tv/cdatafile/c.activity_kernel.autotvin_tmin1.dat"
#define AUTOTB_TVOUT_tmin1 "../tv/cdatafile/c.activity_kernel.autotvout_tmin1.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_len "../tv/rtldatafile/rtl.activity_kernel.autotvout_len.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_hr "../tv/rtldatafile/rtl.activity_kernel.autotvout_hr.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_t "../tv/rtldatafile/rtl.activity_kernel.autotvout_t.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_meanhr "../tv/rtldatafile/rtl.activity_kernel.autotvout_meanhr.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_tpower "../tv/rtldatafile/rtl.activity_kernel.autotvout_tpower.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_stationarity "../tv/rtldatafile/rtl.activity_kernel.autotvout_stationarity.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_activity "../tv/rtldatafile/rtl.activity_kernel.autotvout_activity.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_acmin "../tv/rtldatafile/rtl.activity_kernel.autotvout_acmin.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_hrmin "../tv/rtldatafile/rtl.activity_kernel.autotvout_hrmin.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_stmin "../tv/rtldatafile/rtl.activity_kernel.autotvout_stmin.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_tpmin "../tv/rtldatafile/rtl.activity_kernel.autotvout_tpmin.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_tmin0 "../tv/rtldatafile/rtl.activity_kernel.autotvout_tmin0.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_tmin1 "../tv/rtldatafile/rtl.activity_kernel.autotvout_tmin1.dat"

class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  len_depth = 0;
  hr_depth = 0;
  t_depth = 0;
  meanhr_depth = 0;
  tpower_depth = 0;
  stationarity_depth = 0;
  activity_depth = 0;
  acmin_depth = 0;
  hrmin_depth = 0;
  stmin_depth = 0;
  tpmin_depth = 0;
  tmin0_depth = 0;
  tmin1_depth = 0;
  trans_num =0;
}
~INTER_TCL_FILE() {
  mFile.open(mName);
  if (!mFile.good()) {
    cout << "Failed to open file ref.tcl" << endl;
    exit (1); 
  }
  string total_list = get_depth_list();
  mFile << "set depth_list {\n";
  mFile << total_list;
  mFile << "}\n";
  mFile << "set trans_num "<<trans_num<<endl;
  mFile.close();
}
string get_depth_list () {
  stringstream total_list;
  total_list << "{len " << len_depth << "}\n";
  total_list << "{hr " << hr_depth << "}\n";
  total_list << "{t " << t_depth << "}\n";
  total_list << "{meanhr " << meanhr_depth << "}\n";
  total_list << "{tpower " << tpower_depth << "}\n";
  total_list << "{stationarity " << stationarity_depth << "}\n";
  total_list << "{activity " << activity_depth << "}\n";
  total_list << "{acmin " << acmin_depth << "}\n";
  total_list << "{hrmin " << hrmin_depth << "}\n";
  total_list << "{stmin " << stmin_depth << "}\n";
  total_list << "{tpmin " << tpmin_depth << "}\n";
  total_list << "{tmin0 " << tmin0_depth << "}\n";
  total_list << "{tmin1 " << tmin1_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int len_depth;
    int hr_depth;
    int t_depth;
    int meanhr_depth;
    int tpower_depth;
    int stationarity_depth;
    int activity_depth;
    int acmin_depth;
    int hrmin_depth;
    int stmin_depth;
    int tpmin_depth;
    int tmin0_depth;
    int tmin1_depth;
    int trans_num;
  private:
    ofstream mFile;
    const char* mName;
};

static void RTLOutputCheckAndReplacement(std::string &AESL_token, std::string PortName) {
  bool no_x = false;
  bool err = false;

  no_x = false;
  // search and replace 'X' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('X', 0);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
  no_x = false;
  // search and replace 'x' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('x', 2);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
}
extern "C" void activity_kernel_hw_stub_wrapper(int, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *);

extern "C" void apatb_activity_kernel_hw(int __xlx_apatb_param_len, volatile void * __xlx_apatb_param_hr, volatile void * __xlx_apatb_param_t, volatile void * __xlx_apatb_param_meanhr, volatile void * __xlx_apatb_param_tpower, volatile void * __xlx_apatb_param_stationarity, volatile void * __xlx_apatb_param_activity, volatile void * __xlx_apatb_param_acmin, volatile void * __xlx_apatb_param_hrmin, volatile void * __xlx_apatb_param_stmin, volatile void * __xlx_apatb_param_tpmin, volatile void * __xlx_apatb_param_tmin0, volatile void * __xlx_apatb_param_tmin1) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_meanhr);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > meanhr_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "meanhr");
  
            // push token into output port buffer
            if (AESL_token != "") {
              meanhr_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {
            ((long long*)__xlx_apatb_param_meanhr)[0] = meanhr_pc_buffer[0].to_int64();
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_tpower);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > tpower_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "tpower");
  
            // push token into output port buffer
            if (AESL_token != "") {
              tpower_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {
            ((long long*)__xlx_apatb_param_tpower)[0] = tpower_pc_buffer[0].to_int64();
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_stationarity);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > stationarity_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "stationarity");
  
            // push token into output port buffer
            if (AESL_token != "") {
              stationarity_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {
            ((long long*)__xlx_apatb_param_stationarity)[0] = stationarity_pc_buffer[0].to_int64();
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_activity);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > activity_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "activity");
  
            // push token into output port buffer
            if (AESL_token != "") {
              activity_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {
            ((long long*)__xlx_apatb_param_activity)[0] = activity_pc_buffer[0].to_int64();
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_acmin);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > acmin_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "acmin");
  
            // push token into output port buffer
            if (AESL_token != "") {
              acmin_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {
            ((long long*)__xlx_apatb_param_acmin)[0] = acmin_pc_buffer[0].to_int64();
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_hrmin);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > hrmin_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "hrmin");
  
            // push token into output port buffer
            if (AESL_token != "") {
              hrmin_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {
            ((long long*)__xlx_apatb_param_hrmin)[0] = hrmin_pc_buffer[0].to_int64();
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_stmin);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > stmin_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "stmin");
  
            // push token into output port buffer
            if (AESL_token != "") {
              stmin_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {
            ((long long*)__xlx_apatb_param_stmin)[0] = stmin_pc_buffer[0].to_int64();
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_tpmin);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > tpmin_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "tpmin");
  
            // push token into output port buffer
            if (AESL_token != "") {
              tpmin_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {
            ((long long*)__xlx_apatb_param_tpmin)[0] = tpmin_pc_buffer[0].to_int64();
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_tmin0);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > tmin0_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "tmin0");
  
            // push token into output port buffer
            if (AESL_token != "") {
              tmin0_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {
            ((long long*)__xlx_apatb_param_tmin0)[0] = tmin0_pc_buffer[0].to_int64();
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_tmin1);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<64> > tmin1_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "tmin1");
  
            // push token into output port buffer
            if (AESL_token != "") {
              tmin1_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {
            ((long long*)__xlx_apatb_param_tmin1)[0] = tmin1_pc_buffer[0].to_int64();
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
    AESL_transaction_pc++;
    return ;
  }
static unsigned AESL_transaction;
static AESL_FILE_HANDLER aesl_fh;
static INTER_TCL_FILE tcl_file(INTER_TCL);
std::vector<char> __xlx_sprintf_buffer(1024);
CodeState = ENTER_WRAPC;
//len
aesl_fh.touch(AUTOTB_TVIN_len);
aesl_fh.touch(AUTOTB_TVOUT_len);
//hr
aesl_fh.touch(AUTOTB_TVIN_hr);
aesl_fh.touch(AUTOTB_TVOUT_hr);
//t
aesl_fh.touch(AUTOTB_TVIN_t);
aesl_fh.touch(AUTOTB_TVOUT_t);
//meanhr
aesl_fh.touch(AUTOTB_TVIN_meanhr);
aesl_fh.touch(AUTOTB_TVOUT_meanhr);
//tpower
aesl_fh.touch(AUTOTB_TVIN_tpower);
aesl_fh.touch(AUTOTB_TVOUT_tpower);
//stationarity
aesl_fh.touch(AUTOTB_TVIN_stationarity);
aesl_fh.touch(AUTOTB_TVOUT_stationarity);
//activity
aesl_fh.touch(AUTOTB_TVIN_activity);
aesl_fh.touch(AUTOTB_TVOUT_activity);
//acmin
aesl_fh.touch(AUTOTB_TVIN_acmin);
aesl_fh.touch(AUTOTB_TVOUT_acmin);
//hrmin
aesl_fh.touch(AUTOTB_TVIN_hrmin);
aesl_fh.touch(AUTOTB_TVOUT_hrmin);
//stmin
aesl_fh.touch(AUTOTB_TVIN_stmin);
aesl_fh.touch(AUTOTB_TVOUT_stmin);
//tpmin
aesl_fh.touch(AUTOTB_TVIN_tpmin);
aesl_fh.touch(AUTOTB_TVOUT_tpmin);
//tmin0
aesl_fh.touch(AUTOTB_TVIN_tmin0);
aesl_fh.touch(AUTOTB_TVOUT_tmin0);
//tmin1
aesl_fh.touch(AUTOTB_TVIN_tmin1);
aesl_fh.touch(AUTOTB_TVOUT_tmin1);
CodeState = DUMP_INPUTS;
// print len Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_len, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)&__xlx_apatb_param_len);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_len, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.len_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_len, __xlx_sprintf_buffer.data());
}
// print hr Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_hr, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_hr);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_hr, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.hr_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_hr, __xlx_sprintf_buffer.data());
}
// print t Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_t, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_t);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_t, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.t_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_t, __xlx_sprintf_buffer.data());
}
// print meanhr Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_meanhr, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_meanhr);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_meanhr, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.meanhr_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_meanhr, __xlx_sprintf_buffer.data());
}
// print tpower Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_tpower, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_tpower);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_tpower, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.tpower_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_tpower, __xlx_sprintf_buffer.data());
}
// print stationarity Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_stationarity, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_stationarity);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_stationarity, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.stationarity_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_stationarity, __xlx_sprintf_buffer.data());
}
// print activity Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_activity, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_activity);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_activity, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.activity_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_activity, __xlx_sprintf_buffer.data());
}
// print acmin Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_acmin, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_acmin);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_acmin, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.acmin_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_acmin, __xlx_sprintf_buffer.data());
}
// print hrmin Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_hrmin, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_hrmin);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_hrmin, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.hrmin_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_hrmin, __xlx_sprintf_buffer.data());
}
// print stmin Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_stmin, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_stmin);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_stmin, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.stmin_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_stmin, __xlx_sprintf_buffer.data());
}
// print tpmin Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_tpmin, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_tpmin);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_tpmin, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.tpmin_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_tpmin, __xlx_sprintf_buffer.data());
}
// print tmin0 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_tmin0, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_tmin0);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_tmin0, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.tmin0_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_tmin0, __xlx_sprintf_buffer.data());
}
// print tmin1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_tmin1, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_tmin1);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_tmin1, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.tmin1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_tmin1, __xlx_sprintf_buffer.data());
}
CodeState = CALL_C_DUT;
activity_kernel_hw_stub_wrapper(__xlx_apatb_param_len, __xlx_apatb_param_hr, __xlx_apatb_param_t, __xlx_apatb_param_meanhr, __xlx_apatb_param_tpower, __xlx_apatb_param_stationarity, __xlx_apatb_param_activity, __xlx_apatb_param_acmin, __xlx_apatb_param_hrmin, __xlx_apatb_param_stmin, __xlx_apatb_param_tpmin, __xlx_apatb_param_tmin0, __xlx_apatb_param_tmin1);
CodeState = DUMP_OUTPUTS;
// print meanhr Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_meanhr, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_meanhr);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_meanhr, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.meanhr_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_meanhr, __xlx_sprintf_buffer.data());
}
// print tpower Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_tpower, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_tpower);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_tpower, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.tpower_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_tpower, __xlx_sprintf_buffer.data());
}
// print stationarity Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_stationarity, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_stationarity);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_stationarity, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.stationarity_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_stationarity, __xlx_sprintf_buffer.data());
}
// print activity Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_activity, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_activity);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_activity, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.activity_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_activity, __xlx_sprintf_buffer.data());
}
// print acmin Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_acmin, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_acmin);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_acmin, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.acmin_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_acmin, __xlx_sprintf_buffer.data());
}
// print hrmin Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_hrmin, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_hrmin);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_hrmin, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.hrmin_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_hrmin, __xlx_sprintf_buffer.data());
}
// print stmin Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_stmin, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_stmin);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_stmin, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.stmin_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_stmin, __xlx_sprintf_buffer.data());
}
// print tpmin Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_tpmin, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_tpmin);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_tpmin, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.tpmin_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_tpmin, __xlx_sprintf_buffer.data());
}
// print tmin0 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_tmin0, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_tmin0);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_tmin0, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.tmin0_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_tmin0, __xlx_sprintf_buffer.data());
}
// print tmin1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_tmin1, __xlx_sprintf_buffer.data());
  {
    sc_bv<64> __xlx_tmp_lv = *((long long*)__xlx_apatb_param_tmin1);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_tmin1, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.tmin1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_tmin1, __xlx_sprintf_buffer.data());
}
CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
