############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project aes_decrypt
set_top rijndaelDecrypt_hls
add_files aes_dec_hls.cpp
add_files -tb aes_dec_tb.cpp
open_solution "solution1" -flow_target vivado
set_part {xczu9eg-ffvb1156-2-e}
create_clock -period 2 -name default
config_export -format ip_catalog -rtl verilog
source "./aes_decrypt/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog
