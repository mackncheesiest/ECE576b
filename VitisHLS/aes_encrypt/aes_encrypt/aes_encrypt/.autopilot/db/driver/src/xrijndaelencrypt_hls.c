// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xrijndaelencrypt_hls.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XRijndaelencrypt_hls_CfgInitialize(XRijndaelencrypt_hls *InstancePtr, XRijndaelencrypt_hls_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Bus_a_BaseAddress = ConfigPtr->Bus_a_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XRijndaelencrypt_hls_Start(XRijndaelencrypt_hls *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRijndaelencrypt_hls_ReadReg(InstancePtr->Bus_a_BaseAddress, XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_AP_CTRL) & 0x80;
    XRijndaelencrypt_hls_WriteReg(InstancePtr->Bus_a_BaseAddress, XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_AP_CTRL, Data | 0x01);
}

u32 XRijndaelencrypt_hls_IsDone(XRijndaelencrypt_hls *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRijndaelencrypt_hls_ReadReg(InstancePtr->Bus_a_BaseAddress, XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XRijndaelencrypt_hls_IsIdle(XRijndaelencrypt_hls *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRijndaelencrypt_hls_ReadReg(InstancePtr->Bus_a_BaseAddress, XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XRijndaelencrypt_hls_IsReady(XRijndaelencrypt_hls *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRijndaelencrypt_hls_ReadReg(InstancePtr->Bus_a_BaseAddress, XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XRijndaelencrypt_hls_EnableAutoRestart(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRijndaelencrypt_hls_WriteReg(InstancePtr->Bus_a_BaseAddress, XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_AP_CTRL, 0x80);
}

void XRijndaelencrypt_hls_DisableAutoRestart(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRijndaelencrypt_hls_WriteReg(InstancePtr->Bus_a_BaseAddress, XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_AP_CTRL, 0);
}

u32 XRijndaelencrypt_hls_Get_pt_BaseAddress(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_PT_BASE);
}

u32 XRijndaelencrypt_hls_Get_pt_HighAddress(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_PT_HIGH);
}

u32 XRijndaelencrypt_hls_Get_pt_TotalBytes(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_PT_HIGH - XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_PT_BASE + 1);
}

u32 XRijndaelencrypt_hls_Get_pt_BitWidth(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRIJNDAELENCRYPT_HLS_BUS_A_WIDTH_PT;
}

u32 XRijndaelencrypt_hls_Get_pt_Depth(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRIJNDAELENCRYPT_HLS_BUS_A_DEPTH_PT;
}

u32 XRijndaelencrypt_hls_Write_pt_Words(XRijndaelencrypt_hls *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_PT_HIGH - XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_PT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_PT_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XRijndaelencrypt_hls_Read_pt_Words(XRijndaelencrypt_hls *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_PT_HIGH - XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_PT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_PT_BASE + (offset + i)*4);
    }
    return length;
}

u32 XRijndaelencrypt_hls_Write_pt_Bytes(XRijndaelencrypt_hls *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_PT_HIGH - XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_PT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_PT_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XRijndaelencrypt_hls_Read_pt_Bytes(XRijndaelencrypt_hls *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_PT_HIGH - XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_PT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_PT_BASE + offset + i);
    }
    return length;
}

u32 XRijndaelencrypt_hls_Get_ct_BaseAddress(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_CT_BASE);
}

u32 XRijndaelencrypt_hls_Get_ct_HighAddress(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_CT_HIGH);
}

u32 XRijndaelencrypt_hls_Get_ct_TotalBytes(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_CT_HIGH - XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_CT_BASE + 1);
}

u32 XRijndaelencrypt_hls_Get_ct_BitWidth(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRIJNDAELENCRYPT_HLS_BUS_A_WIDTH_CT;
}

u32 XRijndaelencrypt_hls_Get_ct_Depth(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRIJNDAELENCRYPT_HLS_BUS_A_DEPTH_CT;
}

u32 XRijndaelencrypt_hls_Write_ct_Words(XRijndaelencrypt_hls *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_CT_HIGH - XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_CT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_CT_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XRijndaelencrypt_hls_Read_ct_Words(XRijndaelencrypt_hls *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_CT_HIGH - XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_CT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_CT_BASE + (offset + i)*4);
    }
    return length;
}

u32 XRijndaelencrypt_hls_Write_ct_Bytes(XRijndaelencrypt_hls *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_CT_HIGH - XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_CT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_CT_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XRijndaelencrypt_hls_Read_ct_Bytes(XRijndaelencrypt_hls *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_CT_HIGH - XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_CT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_CT_BASE + offset + i);
    }
    return length;
}

u32 XRijndaelencrypt_hls_Get_rk_BaseAddress(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_RK_BASE);
}

u32 XRijndaelencrypt_hls_Get_rk_HighAddress(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_RK_HIGH);
}

u32 XRijndaelencrypt_hls_Get_rk_TotalBytes(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_RK_HIGH - XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_RK_BASE + 1);
}

u32 XRijndaelencrypt_hls_Get_rk_BitWidth(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRIJNDAELENCRYPT_HLS_BUS_A_WIDTH_RK;
}

u32 XRijndaelencrypt_hls_Get_rk_Depth(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRIJNDAELENCRYPT_HLS_BUS_A_DEPTH_RK;
}

u32 XRijndaelencrypt_hls_Write_rk_Words(XRijndaelencrypt_hls *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_RK_HIGH - XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_RK_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_RK_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XRijndaelencrypt_hls_Read_rk_Words(XRijndaelencrypt_hls *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_RK_HIGH - XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_RK_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_RK_BASE + (offset + i)*4);
    }
    return length;
}

u32 XRijndaelencrypt_hls_Write_rk_Bytes(XRijndaelencrypt_hls *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_RK_HIGH - XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_RK_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_RK_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XRijndaelencrypt_hls_Read_rk_Bytes(XRijndaelencrypt_hls *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_RK_HIGH - XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_RK_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Bus_a_BaseAddress + XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_RK_BASE + offset + i);
    }
    return length;
}

void XRijndaelencrypt_hls_InterruptGlobalEnable(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRijndaelencrypt_hls_WriteReg(InstancePtr->Bus_a_BaseAddress, XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_GIE, 1);
}

void XRijndaelencrypt_hls_InterruptGlobalDisable(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRijndaelencrypt_hls_WriteReg(InstancePtr->Bus_a_BaseAddress, XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_GIE, 0);
}

void XRijndaelencrypt_hls_InterruptEnable(XRijndaelencrypt_hls *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XRijndaelencrypt_hls_ReadReg(InstancePtr->Bus_a_BaseAddress, XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_IER);
    XRijndaelencrypt_hls_WriteReg(InstancePtr->Bus_a_BaseAddress, XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_IER, Register | Mask);
}

void XRijndaelencrypt_hls_InterruptDisable(XRijndaelencrypt_hls *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XRijndaelencrypt_hls_ReadReg(InstancePtr->Bus_a_BaseAddress, XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_IER);
    XRijndaelencrypt_hls_WriteReg(InstancePtr->Bus_a_BaseAddress, XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_IER, Register & (~Mask));
}

void XRijndaelencrypt_hls_InterruptClear(XRijndaelencrypt_hls *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRijndaelencrypt_hls_WriteReg(InstancePtr->Bus_a_BaseAddress, XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_ISR, Mask);
}

u32 XRijndaelencrypt_hls_InterruptGetEnabled(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRijndaelencrypt_hls_ReadReg(InstancePtr->Bus_a_BaseAddress, XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_IER);
}

u32 XRijndaelencrypt_hls_InterruptGetStatus(XRijndaelencrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRijndaelencrypt_hls_ReadReg(InstancePtr->Bus_a_BaseAddress, XRIJNDAELENCRYPT_HLS_BUS_A_ADDR_ISR);
}

