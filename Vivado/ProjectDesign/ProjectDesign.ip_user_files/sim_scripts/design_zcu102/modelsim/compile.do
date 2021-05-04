vlib modelsim_lib/work
vlib modelsim_lib/msim

vlib modelsim_lib/msim/xilinx_vip
vlib modelsim_lib/msim/xpm
vlib modelsim_lib/msim/axi_infrastructure_v1_1_0
vlib modelsim_lib/msim/axi_vip_v1_1_8
vlib modelsim_lib/msim/zynq_ultra_ps_e_vip_v1_0_8
vlib modelsim_lib/msim/xil_defaultlib
vlib modelsim_lib/msim/generic_baseblocks_v2_1_0
vlib modelsim_lib/msim/axi_register_slice_v2_1_22
vlib modelsim_lib/msim/fifo_generator_v13_2_5
vlib modelsim_lib/msim/axi_data_fifo_v2_1_21
vlib modelsim_lib/msim/axi_crossbar_v2_1_23
vlib modelsim_lib/msim/lib_cdc_v1_0_2
vlib modelsim_lib/msim/proc_sys_reset_v5_0_13
vlib modelsim_lib/msim/xbip_utils_v3_0_10
vlib modelsim_lib/msim/axi_utils_v2_0_6
vlib modelsim_lib/msim/xbip_pipe_v3_0_6
vlib modelsim_lib/msim/xbip_dsp48_wrapper_v3_0_4
vlib modelsim_lib/msim/xbip_dsp48_addsub_v3_0_6
vlib modelsim_lib/msim/xbip_dsp48_multadd_v3_0_6
vlib modelsim_lib/msim/xbip_bram18k_v3_0_6
vlib modelsim_lib/msim/mult_gen_v12_0_16
vlib modelsim_lib/msim/floating_point_v7_1_11
vlib modelsim_lib/msim/axi_protocol_converter_v2_1_22
vlib modelsim_lib/msim/axi_clock_converter_v2_1_21
vlib modelsim_lib/msim/blk_mem_gen_v8_4_4
vlib modelsim_lib/msim/axi_dwidth_converter_v2_1_22

vmap xilinx_vip modelsim_lib/msim/xilinx_vip
vmap xpm modelsim_lib/msim/xpm
vmap axi_infrastructure_v1_1_0 modelsim_lib/msim/axi_infrastructure_v1_1_0
vmap axi_vip_v1_1_8 modelsim_lib/msim/axi_vip_v1_1_8
vmap zynq_ultra_ps_e_vip_v1_0_8 modelsim_lib/msim/zynq_ultra_ps_e_vip_v1_0_8
vmap xil_defaultlib modelsim_lib/msim/xil_defaultlib
vmap generic_baseblocks_v2_1_0 modelsim_lib/msim/generic_baseblocks_v2_1_0
vmap axi_register_slice_v2_1_22 modelsim_lib/msim/axi_register_slice_v2_1_22
vmap fifo_generator_v13_2_5 modelsim_lib/msim/fifo_generator_v13_2_5
vmap axi_data_fifo_v2_1_21 modelsim_lib/msim/axi_data_fifo_v2_1_21
vmap axi_crossbar_v2_1_23 modelsim_lib/msim/axi_crossbar_v2_1_23
vmap lib_cdc_v1_0_2 modelsim_lib/msim/lib_cdc_v1_0_2
vmap proc_sys_reset_v5_0_13 modelsim_lib/msim/proc_sys_reset_v5_0_13
vmap xbip_utils_v3_0_10 modelsim_lib/msim/xbip_utils_v3_0_10
vmap axi_utils_v2_0_6 modelsim_lib/msim/axi_utils_v2_0_6
vmap xbip_pipe_v3_0_6 modelsim_lib/msim/xbip_pipe_v3_0_6
vmap xbip_dsp48_wrapper_v3_0_4 modelsim_lib/msim/xbip_dsp48_wrapper_v3_0_4
vmap xbip_dsp48_addsub_v3_0_6 modelsim_lib/msim/xbip_dsp48_addsub_v3_0_6
vmap xbip_dsp48_multadd_v3_0_6 modelsim_lib/msim/xbip_dsp48_multadd_v3_0_6
vmap xbip_bram18k_v3_0_6 modelsim_lib/msim/xbip_bram18k_v3_0_6
vmap mult_gen_v12_0_16 modelsim_lib/msim/mult_gen_v12_0_16
vmap floating_point_v7_1_11 modelsim_lib/msim/floating_point_v7_1_11
vmap axi_protocol_converter_v2_1_22 modelsim_lib/msim/axi_protocol_converter_v2_1_22
vmap axi_clock_converter_v2_1_21 modelsim_lib/msim/axi_clock_converter_v2_1_21
vmap blk_mem_gen_v8_4_4 modelsim_lib/msim/blk_mem_gen_v8_4_4
vmap axi_dwidth_converter_v2_1_22 modelsim_lib/msim/axi_dwidth_converter_v2_1_22

vlog -work xilinx_vip -64 -incr -sv -L axi_vip_v1_1_8 -L zynq_ultra_ps_e_vip_v1_0_8 -L xilinx_vip "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/axi_vip_if.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/clk_vip_if.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work xpm -64 -incr -sv -L axi_vip_v1_1_8 -L zynq_ultra_ps_e_vip_v1_0_8 -L xilinx_vip "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \

vcom -work xpm -64 -93 \
"/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work axi_infrastructure_v1_1_0 -64 -incr "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work axi_vip_v1_1_8 -64 -incr -sv -L axi_vip_v1_1_8 -L zynq_ultra_ps_e_vip_v1_0_8 -L xilinx_vip "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/94c3/hdl/axi_vip_v1_1_vl_rfs.sv" \

vlog -work zynq_ultra_ps_e_vip_v1_0_8 -64 -incr -sv -L axi_vip_v1_1_8 -L zynq_ultra_ps_e_vip_v1_0_8 -L xilinx_vip "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl/zynq_ultra_ps_e_vip_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -incr "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../bd/design_zcu102/ip/design_zcu102_zynq_ultra_ps_e_0_0/sim/design_zcu102_zynq_ultra_ps_e_0_0_vip_wrapper.v" \

vlog -work generic_baseblocks_v2_1_0 -64 -incr "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \

vlog -work axi_register_slice_v2_1_22 -64 -incr "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/af2c/hdl/axi_register_slice_v2_1_vl_rfs.v" \

vlog -work fifo_generator_v13_2_5 -64 -incr "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/276e/simulation/fifo_generator_vlog_beh.v" \

vcom -work fifo_generator_v13_2_5 -64 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/276e/hdl/fifo_generator_v13_2_rfs.vhd" \

vlog -work fifo_generator_v13_2_5 -64 -incr "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/276e/hdl/fifo_generator_v13_2_rfs.v" \

vlog -work axi_data_fifo_v2_1_21 -64 -incr "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/54c0/hdl/axi_data_fifo_v2_1_vl_rfs.v" \

vlog -work axi_crossbar_v2_1_23 -64 -incr "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/bc0a/hdl/axi_crossbar_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib -64 -incr "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../bd/design_zcu102/ip/design_zcu102_xbar_0/sim/design_zcu102_xbar_0.v" \

vcom -work lib_cdc_v1_0_2 -64 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \

vcom -work proc_sys_reset_v5_0_13 -64 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \

vcom -work xil_defaultlib -64 -93 \
"../../../bd/design_zcu102/ip/design_zcu102_rst_ps8_0_99M_0/sim/design_zcu102_rst_ps8_0_99M_0.vhd" \

vcom -work xbip_utils_v3_0_10 -64 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/d117/hdl/xbip_utils_v3_0_vh_rfs.vhd" \

vcom -work axi_utils_v2_0_6 -64 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/1971/hdl/axi_utils_v2_0_vh_rfs.vhd" \

vcom -work xbip_pipe_v3_0_6 -64 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/7468/hdl/xbip_pipe_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_wrapper_v3_0_4 -64 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/cdbf/hdl/xbip_dsp48_wrapper_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_addsub_v3_0_6 -64 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/910d/hdl/xbip_dsp48_addsub_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_multadd_v3_0_6 -64 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/b0ac/hdl/xbip_dsp48_multadd_v3_0_vh_rfs.vhd" \

vcom -work xbip_bram18k_v3_0_6 -64 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/d367/hdl/xbip_bram18k_v3_0_vh_rfs.vhd" \

vcom -work mult_gen_v12_0_16 -64 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ce84/hdl/mult_gen_v12_0_vh_rfs.vhd" \

vcom -work floating_point_v7_1_11 -64 -93 \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/b0c0/hdl/floating_point_v7_1_rfs.vhd" \

vlog -work floating_point_v7_1_11 -64 -incr "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/b0c0/hdl/floating_point_v7_1_rfs.v" \

vlog -work xil_defaultlib -64 -incr "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/efdf/hdl/verilog/compute_statistics_BUS_A_s_axi.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/efdf/hdl/verilog/compute_statistics_dadddsub_64ns_64ns_64_14_no_dsp_1.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/efdf/hdl/verilog/compute_statistics_dcmp_64ns_64ns_1_4_no_dsp_1.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/efdf/hdl/verilog/compute_statistics_ddiv_64ns_64ns_64_59_no_dsp_1.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/efdf/hdl/verilog/compute_statistics_dmul_64ns_64ns_64_14_full_dsp_1.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/efdf/hdl/verilog/compute_statistics_dsqrt_64ns_64ns_64_59_no_dsp_1.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/efdf/hdl/verilog/compute_statistics_sitodp_32ns_64_7_no_dsp_1.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/efdf/hdl/verilog/compute_statistics.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/efdf/hdl/ip/compute_statistics_ap_dcmp_2_no_dsp_64.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/efdf/hdl/ip/compute_statistics_ap_ddiv_57_no_dsp_64.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/efdf/hdl/ip/compute_statistics_ap_dadddsub_12_no_dsp_64.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/efdf/hdl/ip/compute_statistics_ap_sitodp_5_no_dsp_32.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/efdf/hdl/ip/compute_statistics_ap_dsqrt_57_no_dsp_64.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/efdf/hdl/ip/compute_statistics_ap_dmul_12_full_dsp_64.v" \
"../../../bd/design_zcu102/ip/design_zcu102_compute_statistics_0_0/sim/design_zcu102_compute_statistics_0_0.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/e996/hdl/verilog/rijndaelEncrypt_hls_BUS_A_s_axi.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/e996/hdl/verilog/rijndaelEncrypt_hls_rotr.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/e996/hdl/verilog/rijndaelEncrypt_hls_Te0.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/e996/hdl/verilog/rijndaelEncrypt_hls.v" \
"../../../bd/design_zcu102/ip/design_zcu102_rijndaelEncrypt_hls_0_0/sim/design_zcu102_rijndaelEncrypt_hls_0_0.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/2471/hdl/verilog/rijndaelDecrypt_hls_BUS_s_axi.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/2471/hdl/verilog/rijndaelDecrypt_hls_rotr.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/2471/hdl/verilog/rijndaelDecrypt_hls_Td0.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/2471/hdl/verilog/rijndaelDecrypt_hls_Td4s.v" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/2471/hdl/verilog/rijndaelDecrypt_hls.v" \
"../../../bd/design_zcu102/ip/design_zcu102_rijndaelDecrypt_hls_0_0/sim/design_zcu102_rijndaelDecrypt_hls_0_0.v" \

vlog -work axi_protocol_converter_v2_1_22 -64 -incr "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/5cee/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \

vlog -work axi_clock_converter_v2_1_21 -64 -incr "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/1304/hdl/axi_clock_converter_v2_1_vl_rfs.v" \

vlog -work blk_mem_gen_v8_4_4 -64 -incr "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/2985/simulation/blk_mem_gen_v8_4.v" \

vlog -work axi_dwidth_converter_v2_1_22 -64 -incr "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/2394/hdl/axi_dwidth_converter_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib -64 -incr "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/ec67/hdl" "+incdir+../../../../ProjectDesign.gen/sources_1/bd/design_zcu102/ipshared/da1e/hdl" "+incdir+/media/jmack2545/data_drive/Xilinx/Vivado/2020.2/data/xilinx_vip/include" \
"../../../bd/design_zcu102/ip/design_zcu102_auto_ds_0/sim/design_zcu102_auto_ds_0.v" \
"../../../bd/design_zcu102/ip/design_zcu102_auto_pc_0/sim/design_zcu102_auto_pc_0.v" \
"../../../bd/design_zcu102/ip/design_zcu102_auto_ds_1/sim/design_zcu102_auto_ds_1.v" \
"../../../bd/design_zcu102/ip/design_zcu102_auto_pc_1/sim/design_zcu102_auto_pc_1.v" \
"../../../bd/design_zcu102/sim/design_zcu102.v" \

vlog -work xil_defaultlib \
"glbl.v"

