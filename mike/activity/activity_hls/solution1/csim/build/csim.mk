# ==============================================================
# Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
# Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
# ==============================================================
CSIM_DESIGN = 1

__SIM_FPO__ = 1

__SIM_MATHHLS__ = 1

__SIM_FFT__ = 1

__SIM_FIR__ = 1

__SIM_DDS__ = 1

__USE_CLANG__ = 1

ObjDir = obj

HLS_SOURCES = ../../../../activity.c ../../../../activity_kernel.c

override TARGET := csim.exe

AUTOPILOT_ROOT := /tools/Xilinx/Vitis_HLS/2020.2
AUTOPILOT_MACH := lnx64
ifdef AP_GCC_M32
  AUTOPILOT_MACH := Linux_x86
  IFLAG += -m32
endif
IFLAG += -fPIC
ifndef AP_GCC_PATH
  AP_GCC_PATH := /tools/Xilinx/Vitis_HLS/2020.2/tps/lnx64/gcc-6.2.0/bin
endif
AUTOPILOT_TOOL := ${AUTOPILOT_ROOT}/${AUTOPILOT_MACH}/tools
AP_CLANG_PATH := ${AUTOPILOT_TOOL}/clang-3.9-csynth/bin
AUTOPILOT_TECH := ${AUTOPILOT_ROOT}/common/technology


IFLAG += -I "${AUTOPILOT_TOOL}/systemc/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include/ap_sysc"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_FP_comp"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_comp"
IFLAG += -I "${AUTOPILOT_TOOL}/auto_cc/include"
IFLAG += -I "/usr/include/x86_64-linux-gnu"
IFLAG += -D__VITIS_HLS__

IFLAG += -D__SIM_FPO__

IFLAG += -D__SIM_FFT__

IFLAG += -D__SIM_FIR__

IFLAG += -D__SIM_DDS__

IFLAG += -D__DSP48E1__
IFLAG += -Wno-unknown-pragmas 
IFLAG += -g
DFLAG += -DAUTOCC
DFLAG += -D__xilinx_ip_top= -DAESL_TB
CCFLAG += -Werror=return-type
TOOLCHAIN += 
CCFLAG += -gcc-toolchain /tools/Xilinx/Vitis_HLS/2020.2/tps/lnx64/gcc-6.2.0
LFLAG += -gcc-toolchain /tools/Xilinx/Vitis_HLS/2020.2/tps/lnx64/gcc-6.2.0
CCFLAG += -fno-exceptions
LFLAG += -fno-exceptions
CCFLAG += -fprofile-instr-generate="code-%m.profraw"
LFLAG += -fprofile-instr-generate="code-%m.profraw"
CCFLAG += -Wno-c++11-narrowing
CCFLAG += -Werror=uninitialized
CCFLAG += -std=c++11
LFLAG += -std=c++11



include ./Makefile.rules

all: $(TARGET)



AUTOCC := apcc  

$(ObjDir)/activity.o: ../../../../activity.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../activity.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/activity.d

$(ObjDir)/activity_kernel.o: ../../../../activity_kernel.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../../activity_kernel.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/activity_kernel.d
pObjDir=pobj
POBJECTS := $(basename $(notdir $(HLS_SOURCES)))
POBJECTS := $(POBJECTS:%=$(pObjDir)/%.bc)

$(pObjDir)/activity.bc: ../../../../activity.c $(pObjDir)/.dir
	$(Echo) $(CC)  -gcc-toolchain /tools/Xilinx/Vitis_HLS/2020.2/tps/lnx64/gcc-6.2.0 -fno-exceptions -fprofile-instr-use=code.profdata -emit-llvm -c -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ;
	$(Verb) $(CC)  -gcc-toolchain /tools/Xilinx/Vitis_HLS/2020.2/tps/lnx64/gcc-6.2.0 -fno-exceptions -fprofile-instr-use=code.profdata -emit-llvm -c -Wno-unknown-pragmas -Wno-unknown-pragmas  $(IFLAG) $(DFLAG) $< -o $@ ;

$(pObjDir)/activity_kernel.bc: ../../../../activity_kernel.c $(pObjDir)/.dir
	$(Echo) $(CC)  -gcc-toolchain /tools/Xilinx/Vitis_HLS/2020.2/tps/lnx64/gcc-6.2.0 -fno-exceptions -fprofile-instr-use=code.profdata -emit-llvm -c  $(IFLAG) $(DFLAG) $< -o $@ ;
	$(Verb) $(CC)  -gcc-toolchain /tools/Xilinx/Vitis_HLS/2020.2/tps/lnx64/gcc-6.2.0 -fno-exceptions -fprofile-instr-use=code.profdata -emit-llvm -c  $(IFLAG) $(DFLAG) $< -o $@ ;

profile_data: *.profraw
	${AP_CLANG_PATH}/llvm-profdata merge -output=code.profdata *.profraw

profile_all: profile_data $(POBJECTS)
	${AP_CLANG_PATH}/llvm-link -o LinkFile.bc ${POBJECTS} -f; \
	${MKDIR} /home/mikesinouye/ECE576b/mike/activity/activity_hls/solution1/.autopilot/db/dot ; \
	${CP} -r ${pObjDir} /home/mikesinouye/ECE576b/mike/activity/activity_hls/solution1/.autopilot/db/dot ; \
	${CP} LinkFile.bc /home/mikesinouye/ECE576b/mike/activity/activity_hls/solution1/.autopilot/db/dot ; \
	${CD} /home/mikesinouye/ECE576b/mike/activity/activity_hls/solution1/.autopilot/db/dot ; \
	${AP_CLANG_PATH}/opt -dot-callgraph-hls -cfg-hier-userfilelist "/home/mikesinouye/ECE576b/mike/activity/test-activity-out-golden /home/mikesinouye/ECE576b/mike/activity/test-100.ts /home/mikesinouye/ECE576b/mike/activity/activity.c /home/mikesinouye/ECE576b/mike/activity/activity_kernel.c" -csim-top-function-name=activity_kernel LinkFile.bc -o LinkFile_fid.bc ; \
	${AP_CLANG_PATH}/opt -dot-cfg-hier-only -cfg-hier-userfilelist "/home/mikesinouye/ECE576b/mike/activity/test-activity-out-golden /home/mikesinouye/ECE576b/mike/activity/test-100.ts /home/mikesinouye/ECE576b/mike/activity/activity.c /home/mikesinouye/ECE576b/mike/activity/activity_kernel.c" -cfg-hier-type csim LinkFile_fid.bc -o LinkFile_pp.bc ; 
