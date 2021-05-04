############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project activity_hls
set_top compute_statistics
add_files activity_hls.cpp
add_files bytestrm_util.h
add_files myfile.cpp
add_files -tb activity_test.cpp
open_solution "activity_soln" -flow_target vivado
set_part {xczu9eg-ffvb1156-2-e}
create_clock -period 2 -name default
config_export -format ip_catalog -rtl verilog
source "./activity_hls/activity_soln/directives.tcl"
csim_design -argv {-r ../../../../test-100.ts}
csynth_design
cosim_design -argv {-r ../../../../test-100.ts}
export_design -rtl verilog -format ip_catalog
