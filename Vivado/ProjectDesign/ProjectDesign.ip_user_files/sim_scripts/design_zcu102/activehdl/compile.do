vlib work
vlib activehdl

vlib activehdl/xilinx_vip
vlib activehdl/xpm
vlib activehdl/axi_infrastructure_v1_1_0
vlib activehdl/axi_vip_v1_1_8
vlib activehdl/zynq_ultra_ps_e_vip_v1_0_8
vlib activehdl/xil_defaultlib
vlib activehdl/xbip_utils_v3_0_10
vlib activehdl/axi_utils_v2_0_6
vlib activehdl/xbip_pipe_v3_0_6
vlib activehdl/xbip_dsp48_wrapper_v3_0_4
vlib activehdl/xbip_dsp48_addsub_v3_0_6
vlib activehdl/xbip_dsp48_multadd_v3_0_6
vlib activehdl/xbip_bram18k_v3_0_6
vlib activehdl/mult_gen_v12_0_16
vlib activehdl/floating_point_v7_1_11
vlib activehdl/generic_baseblocks_v2_1_0
vlib activehdl/axi_register_slice_v2_1_22
vlib activehdl/fifo_generator_v13_2_5
vlib activehdl/axi_data_fifo_v2_1_21
vlib activehdl/axi_crossbar_v2_1_23
vlib activehdl/lib_cdc_v1_0_2
vlib activehdl/proc_sys_reset_v5_0_13
vlib activehdl/axi_protocol_converter_v2_1_22
vlib activehdl/axi_clock_converter_v2_1_21
vlib activehdl/blk_mem_gen_v8_4_4
vlib activehdl/axi_dwidth_converter_v2_1_22

vmap xilinx_vip activehdl/xilinx_vip
vmap xpm activehdl/xpm
vmap axi_infrastructure_v1_1_0 activehdl/axi_infrastructure_v1_1_0
vmap axi_vip_v1_1_8 activehdl/axi_vip_v1_1_8
vmap zynq_ultra_ps_e_vip_v1_0_8 activehdl/zynq_ultra_ps_e_vip_v1_0_8
vmap xil_defaultlib activehdl/xil_defaultlib
vmap xbip_utils_v3_0_10 activehdl/xbip_utils_v3_0_10
vmap axi_utils_v2_0_6 activehdl/axi_utils_v2_0_6
vmap xbip_pipe_v3_0_6 activehdl/xbip_pipe_v3_0_6
vmap xbip_dsp48_wrapper_v3_0_4 activehdl/xbip_dsp48_wrapper_v3_0_4
vmap xbip_dsp48_addsub_v3_0_6 activehdl/xbip_dsp48_addsub_v3_0_6
vmap xbip_dsp48_multadd_v3_0_6 activehdl/xbip_dsp48_multadd_v3_0_6
vmap xbip_bram18k_v3_0_6 activehdl/xbip_bram18k_v3_0_6
vmap mult_gen_v12_0_16 activehdl/mult_gen_v12_0_16
vmap floating_point_v7_1_11 activehdl/floating_point_v7_1_11
vmap generic_baseblocks_v2_1_0 activehdl/generic_baseblocks_v2_1_0
vmap axi_register_slice_v2_1_22 activehdl/axi_register_slice_v2_1_22
vmap fifo_generator_v13_2_5 activehdl/fifo_generator_v13_2_5
vmap axi_data_fifo_v2_1_21 activehdl/axi_data_fifo_v2_1_21
vmap axi_crossbar_v2_1_23 activehdl/axi_crossbar_v2_1_23
vmap lib_cdc_v1_0_2 activehdl/lib_cdc_v1_0_2
vmap proc_sys_reset_v5_0_13 activehdl/proc_sys_reset_v5_0_13
vmap axi_protocol_converter_v2_1_22 activehdl/axi_protocol_converter_v2_1_22
vmap axi_clock_converter_v2_1_21 activehdl/axi_clock_converter_v2_1_21
vmap blk_mem_gen_v8_4_4 activehdl/blk_mem_gen_v8_4_4
vmap axi_dwidth_converter_v2_1_22 activehdl/axi_dwidth_converter_v2_1_22

vlog -work xilinx_vip  -sv2k12 "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/axi_vip_if.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/clk_vip_if.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work xpm  -sv2k12 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \

vcom -work xpm -93 \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work axi_infrastructure_v1_1_0  -v2k5 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work axi_vip_v1_1_8  -sv2k12 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/94c3/hdl/axi_vip_v1_1_vl_rfs.sv" \

vlog -work zynq_ultra_ps_e_vip_v1_0_8  -sv2k12 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl/zynq_ultra_ps_e_vip_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../bd/design_zcu102/ip/design_zcu102_zynq_ultra_ps_e_0_0/sim/design_zcu102_zynq_ultra_ps_e_0_0_vip_wrapper.v" \

vcom -work xbip_utils_v3_0_10 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/d117/hdl/xbip_utils_v3_0_vh_rfs.vhd" \

vcom -work axi_utils_v2_0_6 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/1971/hdl/axi_utils_v2_0_vh_rfs.vhd" \

vcom -work xbip_pipe_v3_0_6 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/7468/hdl/xbip_pipe_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_wrapper_v3_0_4 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/cdbf/hdl/xbip_dsp48_wrapper_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_addsub_v3_0_6 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/910d/hdl/xbip_dsp48_addsub_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_multadd_v3_0_6 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/b0ac/hdl/xbip_dsp48_multadd_v3_0_vh_rfs.vhd" \

vcom -work xbip_bram18k_v3_0_6 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/d367/hdl/xbip_bram18k_v3_0_vh_rfs.vhd" \

vcom -work mult_gen_v12_0_16 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ce84/hdl/mult_gen_v12_0_vh_rfs.vhd" \

vcom -work floating_point_v7_1_11 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/b0c0/hdl/floating_point_v7_1_rfs.vhd" \

vlog -work floating_point_v7_1_11  -v2k5 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/b0c0/hdl/floating_point_v7_1_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/7e23/hdl/verilog/compute_statistics_BUS_A_s_axi.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/7e23/hdl/verilog/compute_statistics_dadddsub_64ns_64ns_64_14_no_dsp_1.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/7e23/hdl/verilog/compute_statistics_dcmp_64ns_64ns_1_4_no_dsp_1.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/7e23/hdl/verilog/compute_statistics_ddiv_64ns_64ns_64_59_no_dsp_1.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/7e23/hdl/verilog/compute_statistics_dmul_64ns_64ns_64_14_full_dsp_1.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/7e23/hdl/verilog/compute_statistics_dsqrt_64ns_64ns_64_59_no_dsp_1.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/7e23/hdl/verilog/compute_statistics_sitodp_32ns_64_7_no_dsp_1.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/7e23/hdl/verilog/compute_statistics.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/7e23/hdl/ip/compute_statistics_ap_dcmp_2_no_dsp_64.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/7e23/hdl/ip/compute_statistics_ap_ddiv_57_no_dsp_64.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/7e23/hdl/ip/compute_statistics_ap_dadddsub_12_no_dsp_64.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/7e23/hdl/ip/compute_statistics_ap_sitodp_5_no_dsp_32.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/7e23/hdl/ip/compute_statistics_ap_dsqrt_57_no_dsp_64.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/7e23/hdl/ip/compute_statistics_ap_dmul_12_full_dsp_64.v" \
"../../../bd/design_zcu102/ip/design_zcu102_compute_statistics_0_0/sim/design_zcu102_compute_statistics_0_0.v" \

vlog -work generic_baseblocks_v2_1_0  -v2k5 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \

vlog -work axi_register_slice_v2_1_22  -v2k5 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/af2c/hdl/axi_register_slice_v2_1_vl_rfs.v" \

vlog -work fifo_generator_v13_2_5  -v2k5 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/276e/simulation/fifo_generator_vlog_beh.v" \

vcom -work fifo_generator_v13_2_5 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/276e/hdl/fifo_generator_v13_2_rfs.vhd" \

vlog -work fifo_generator_v13_2_5  -v2k5 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/276e/hdl/fifo_generator_v13_2_rfs.v" \

vlog -work axi_data_fifo_v2_1_21  -v2k5 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/54c0/hdl/axi_data_fifo_v2_1_vl_rfs.v" \

vlog -work axi_crossbar_v2_1_23  -v2k5 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/bc0a/hdl/axi_crossbar_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../bd/design_zcu102/ip/design_zcu102_xbar_0/sim/design_zcu102_xbar_0.v" \

vcom -work lib_cdc_v1_0_2 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \

vcom -work proc_sys_reset_v5_0_13 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \

vcom -work xil_defaultlib -93 \
"../../../bd/design_zcu102/ip/design_zcu102_rst_ps8_0_99M_0/sim/design_zcu102_rst_ps8_0_99M_0.vhd" \

vlog -work axi_protocol_converter_v2_1_22  -v2k5 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/5cee/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \

vlog -work axi_clock_converter_v2_1_21  -v2k5 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/1304/hdl/axi_clock_converter_v2_1_vl_rfs.v" \

vlog -work blk_mem_gen_v8_4_4  -v2k5 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/2985/simulation/blk_mem_gen_v8_4.v" \

vlog -work axi_dwidth_converter_v2_1_22  -v2k5 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/2394/hdl/axi_dwidth_converter_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../bd/design_zcu102/ip/design_zcu102_auto_ds_0/sim/design_zcu102_auto_ds_0.v" \
"../../../bd/design_zcu102/ip/design_zcu102_auto_pc_0/sim/design_zcu102_auto_pc_0.v" \
"../../../bd/design_zcu102/ip/design_zcu102_auto_ds_1/sim/design_zcu102_auto_ds_1.v" \
"../../../bd/design_zcu102/ip/design_zcu102_auto_pc_1/sim/design_zcu102_auto_pc_1.v" \
"../../../bd/design_zcu102/sim/design_zcu102.v" \

vlog -work xil_defaultlib \
"glbl.v"

