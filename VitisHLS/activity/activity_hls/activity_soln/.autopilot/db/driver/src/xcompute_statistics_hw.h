// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// BUS_A
// 0x0000 : Control signals
//          bit 0  - ap_start (Read/Write/COH)
//          bit 1  - ap_done (Read/COR)
//          bit 2  - ap_idle (Read)
//          bit 3  - ap_ready (Read)
//          bit 7  - auto_restart (Read/Write)
//          others - reserved
// 0x0004 : Global Interrupt Enable Register
//          bit 0  - Global Interrupt Enable (Read/Write)
//          others - reserved
// 0x0008 : IP Interrupt Enable Register (Read/Write)
//          bit 0  - enable ap_done interrupt (Read/Write)
//          bit 1  - enable ap_ready interrupt (Read/Write)
//          others - reserved
// 0x000c : IP Interrupt Status Register (Read/TOW)
//          bit 0  - ap_done (COR/TOW)
//          bit 1  - ap_ready (COR/TOW)
//          others - reserved
// 0x0040 : Data signal of vals_i
//          bit 31~0 - vals_i[31:0] (Read/Write)
// 0x0044 : Data signal of vals_i
//          bit 31~0 - vals_i[63:32] (Read/Write)
// 0x0048 : Data signal of vals_i
//          bit 31~0 - vals_i[95:64] (Read/Write)
// 0x004c : Data signal of vals_i
//          bit 31~0 - vals_i[127:96] (Read/Write)
// 0x0050 : Data signal of vals_i
//          bit 31~0 - vals_i[159:128] (Read/Write)
// 0x0054 : Data signal of vals_i
//          bit 31~0 - vals_i[191:160] (Read/Write)
// 0x0058 : Data signal of vals_i
//          bit 31~0 - vals_i[223:192] (Read/Write)
// 0x005c : Data signal of vals_i
//          bit 31~0 - vals_i[255:224] (Read/Write)
// 0x0060 : Data signal of vals_i
//          bit 31~0 - vals_i[287:256] (Read/Write)
// 0x0064 : Data signal of vals_i
//          bit 31~0 - vals_i[319:288] (Read/Write)
// 0x0068 : Data signal of vals_i
//          bit 31~0 - vals_i[351:320] (Read/Write)
// 0x006c : Data signal of vals_i
//          bit 31~0 - vals_i[383:352] (Read/Write)
// 0x0070 : Data signal of vals_i
//          bit 31~0 - vals_i[415:384] (Read/Write)
// 0x0074 : Data signal of vals_i
//          bit 31~0 - vals_i[447:416] (Read/Write)
// 0x0078 : Data signal of vals_i
//          bit 31~0 - vals_i[479:448] (Read/Write)
// 0x007c : Data signal of vals_i
//          bit 31~0 - vals_i[511:480] (Read/Write)
// 0x0080 : reserved
// 0x0084 : Data signal of vals_o
//          bit 31~0 - vals_o[31:0] (Read)
// 0x0088 : Data signal of vals_o
//          bit 31~0 - vals_o[63:32] (Read)
// 0x008c : Data signal of vals_o
//          bit 31~0 - vals_o[95:64] (Read)
// 0x0090 : Data signal of vals_o
//          bit 31~0 - vals_o[127:96] (Read)
// 0x0094 : Data signal of vals_o
//          bit 31~0 - vals_o[159:128] (Read)
// 0x0098 : Data signal of vals_o
//          bit 31~0 - vals_o[191:160] (Read)
// 0x009c : Data signal of vals_o
//          bit 31~0 - vals_o[223:192] (Read)
// 0x00a0 : Data signal of vals_o
//          bit 31~0 - vals_o[255:224] (Read)
// 0x00a4 : Data signal of vals_o
//          bit 31~0 - vals_o[287:256] (Read)
// 0x00a8 : Data signal of vals_o
//          bit 31~0 - vals_o[319:288] (Read)
// 0x00ac : Data signal of vals_o
//          bit 31~0 - vals_o[351:320] (Read)
// 0x00b0 : Data signal of vals_o
//          bit 31~0 - vals_o[383:352] (Read)
// 0x00b4 : Data signal of vals_o
//          bit 31~0 - vals_o[415:384] (Read)
// 0x00b8 : Data signal of vals_o
//          bit 31~0 - vals_o[447:416] (Read)
// 0x00bc : Data signal of vals_o
//          bit 31~0 - vals_o[479:448] (Read)
// 0x00c0 : Data signal of vals_o
//          bit 31~0 - vals_o[511:480] (Read)
// 0x00c4 : Control signal of vals_o
//          bit 0  - vals_o_ap_vld (Read/COR)
//          others - reserved
// 0x2000 ~
// 0x3fff : Memory 'hr' (600 * 64b)
//          Word 2n   : bit [31:0] - hr[n][31: 0]
//          Word 2n+1 : bit [31:0] - hr[n][63:32]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XCOMPUTE_STATISTICS_BUS_A_ADDR_AP_CTRL      0x0000
#define XCOMPUTE_STATISTICS_BUS_A_ADDR_GIE          0x0004
#define XCOMPUTE_STATISTICS_BUS_A_ADDR_IER          0x0008
#define XCOMPUTE_STATISTICS_BUS_A_ADDR_ISR          0x000c
#define XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA  0x0040
#define XCOMPUTE_STATISTICS_BUS_A_BITS_VALS_I_DATA  512
#define XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA_ 0x0068
#define XCOMPUTE_STATISTICS_BUS_A_BITS_VALS_I_DATA  512
#define XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA  0x0084
#define XCOMPUTE_STATISTICS_BUS_A_BITS_VALS_O_DATA  512
#define XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA_ 0x00ac
#define XCOMPUTE_STATISTICS_BUS_A_BITS_VALS_O_DATA  512
#define XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_CTRL  0x00c4
#define XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_BASE      0x2000
#define XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_HIGH      0x3fff
#define XCOMPUTE_STATISTICS_BUS_A_WIDTH_HR          64
#define XCOMPUTE_STATISTICS_BUS_A_DEPTH_HR          600

