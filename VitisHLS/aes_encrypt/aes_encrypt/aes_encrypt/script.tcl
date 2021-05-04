############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project aes_encrypt
set_top rijndaelEncrypt_hls
add_files ../../../../../home/jmack2545/Downloads/rijndaelEncrypt_hls.cpp
add_files -tb ../../../../../home/jmack2545/Downloads/aes_tb_1.cpp
open_solution "aes_encrypt" -flow_target vivado
set_part {xczu9eg-ffvb1156-2-e}
create_clock -period 2 -name default
source "./aes_encrypt/aes_encrypt/directives.tcl"
csim_design -clean
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog
