############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project activity_hls
set_top activity_kernel
add_files activity_kernel.c
add_files -tb activity.c
add_files -tb test-100.ts
add_files -tb test-activity-out-golden
open_solution "solution1" -flow_target vivado
set_part {xc7z100iffv900-2L}
create_clock -period 60 -name default
set_clock_uncertainty 0
#source "./activity_hls/solution1/directives.tcl"
csim_design -clean -profile
csynth_design
cosim_design
export_design -format ip_catalog
