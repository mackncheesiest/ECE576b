// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// BUS
// 0x000 : Control signals
//         bit 0  - ap_start (Read/Write/COH)
//         bit 1  - ap_done (Read/COR)
//         bit 2  - ap_idle (Read)
//         bit 3  - ap_ready (Read)
//         bit 7  - auto_restart (Read/Write)
//         others - reserved
// 0x004 : Global Interrupt Enable Register
//         bit 0  - Global Interrupt Enable (Read/Write)
//         others - reserved
// 0x008 : IP Interrupt Enable Register (Read/Write)
//         bit 0  - enable ap_done interrupt (Read/Write)
//         bit 1  - enable ap_ready interrupt (Read/Write)
//         others - reserved
// 0x00c : IP Interrupt Status Register (Read/TOW)
//         bit 0  - ap_done (COR/TOW)
//         bit 1  - ap_ready (COR/TOW)
//         others - reserved
// 0x010 ~
// 0x01f : Memory 'ct' (16 * 8b)
//         Word n : bit [ 7: 0] - ct[4n]
//                  bit [15: 8] - ct[4n+1]
//                  bit [23:16] - ct[4n+2]
//                  bit [31:24] - ct[4n+3]
// 0x020 ~
// 0x02f : Memory 'pt' (16 * 8b)
//         Word n : bit [ 7: 0] - pt[4n]
//                  bit [15: 8] - pt[4n+1]
//                  bit [23:16] - pt[4n+2]
//                  bit [31:24] - pt[4n+3]
// 0x100 ~
// 0x1ff : Memory 'rk' (44 * 32b)
//         Word n : bit [31:0] - rk[n]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XRIJNDAELDECRYPT_HLS_BUS_ADDR_AP_CTRL 0x000
#define XRIJNDAELDECRYPT_HLS_BUS_ADDR_GIE     0x004
#define XRIJNDAELDECRYPT_HLS_BUS_ADDR_IER     0x008
#define XRIJNDAELDECRYPT_HLS_BUS_ADDR_ISR     0x00c
#define XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_BASE 0x010
#define XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_HIGH 0x01f
#define XRIJNDAELDECRYPT_HLS_BUS_WIDTH_CT     8
#define XRIJNDAELDECRYPT_HLS_BUS_DEPTH_CT     16
#define XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_BASE 0x020
#define XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_HIGH 0x02f
#define XRIJNDAELDECRYPT_HLS_BUS_WIDTH_PT     8
#define XRIJNDAELDECRYPT_HLS_BUS_DEPTH_PT     16
#define XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_BASE 0x100
#define XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_HIGH 0x1ff
#define XRIJNDAELDECRYPT_HLS_BUS_WIDTH_RK     32
#define XRIJNDAELDECRYPT_HLS_BUS_DEPTH_RK     44

