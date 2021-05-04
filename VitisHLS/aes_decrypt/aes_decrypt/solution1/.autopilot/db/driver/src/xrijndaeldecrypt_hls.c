// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xrijndaeldecrypt_hls.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XRijndaeldecrypt_hls_CfgInitialize(XRijndaeldecrypt_hls *InstancePtr, XRijndaeldecrypt_hls_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Bus_BaseAddress = ConfigPtr->Bus_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XRijndaeldecrypt_hls_Start(XRijndaeldecrypt_hls *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRijndaeldecrypt_hls_ReadReg(InstancePtr->Bus_BaseAddress, XRIJNDAELDECRYPT_HLS_BUS_ADDR_AP_CTRL) & 0x80;
    XRijndaeldecrypt_hls_WriteReg(InstancePtr->Bus_BaseAddress, XRIJNDAELDECRYPT_HLS_BUS_ADDR_AP_CTRL, Data | 0x01);
}

u32 XRijndaeldecrypt_hls_IsDone(XRijndaeldecrypt_hls *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRijndaeldecrypt_hls_ReadReg(InstancePtr->Bus_BaseAddress, XRIJNDAELDECRYPT_HLS_BUS_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XRijndaeldecrypt_hls_IsIdle(XRijndaeldecrypt_hls *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRijndaeldecrypt_hls_ReadReg(InstancePtr->Bus_BaseAddress, XRIJNDAELDECRYPT_HLS_BUS_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XRijndaeldecrypt_hls_IsReady(XRijndaeldecrypt_hls *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XRijndaeldecrypt_hls_ReadReg(InstancePtr->Bus_BaseAddress, XRIJNDAELDECRYPT_HLS_BUS_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XRijndaeldecrypt_hls_EnableAutoRestart(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRijndaeldecrypt_hls_WriteReg(InstancePtr->Bus_BaseAddress, XRIJNDAELDECRYPT_HLS_BUS_ADDR_AP_CTRL, 0x80);
}

void XRijndaeldecrypt_hls_DisableAutoRestart(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRijndaeldecrypt_hls_WriteReg(InstancePtr->Bus_BaseAddress, XRIJNDAELDECRYPT_HLS_BUS_ADDR_AP_CTRL, 0);
}

u32 XRijndaeldecrypt_hls_Get_ct_BaseAddress(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_BASE);
}

u32 XRijndaeldecrypt_hls_Get_ct_HighAddress(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_HIGH);
}

u32 XRijndaeldecrypt_hls_Get_ct_TotalBytes(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_HIGH - XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_BASE + 1);
}

u32 XRijndaeldecrypt_hls_Get_ct_BitWidth(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRIJNDAELDECRYPT_HLS_BUS_WIDTH_CT;
}

u32 XRijndaeldecrypt_hls_Get_ct_Depth(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRIJNDAELDECRYPT_HLS_BUS_DEPTH_CT;
}

u32 XRijndaeldecrypt_hls_Write_ct_Words(XRijndaeldecrypt_hls *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_HIGH - XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XRijndaeldecrypt_hls_Read_ct_Words(XRijndaeldecrypt_hls *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_HIGH - XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_BASE + (offset + i)*4);
    }
    return length;
}

u32 XRijndaeldecrypt_hls_Write_ct_Bytes(XRijndaeldecrypt_hls *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_HIGH - XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XRijndaeldecrypt_hls_Read_ct_Bytes(XRijndaeldecrypt_hls *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_HIGH - XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_CT_BASE + offset + i);
    }
    return length;
}

u32 XRijndaeldecrypt_hls_Get_pt_BaseAddress(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_BASE);
}

u32 XRijndaeldecrypt_hls_Get_pt_HighAddress(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_HIGH);
}

u32 XRijndaeldecrypt_hls_Get_pt_TotalBytes(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_HIGH - XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_BASE + 1);
}

u32 XRijndaeldecrypt_hls_Get_pt_BitWidth(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRIJNDAELDECRYPT_HLS_BUS_WIDTH_PT;
}

u32 XRijndaeldecrypt_hls_Get_pt_Depth(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRIJNDAELDECRYPT_HLS_BUS_DEPTH_PT;
}

u32 XRijndaeldecrypt_hls_Write_pt_Words(XRijndaeldecrypt_hls *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_HIGH - XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XRijndaeldecrypt_hls_Read_pt_Words(XRijndaeldecrypt_hls *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_HIGH - XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_BASE + (offset + i)*4);
    }
    return length;
}

u32 XRijndaeldecrypt_hls_Write_pt_Bytes(XRijndaeldecrypt_hls *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_HIGH - XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XRijndaeldecrypt_hls_Read_pt_Bytes(XRijndaeldecrypt_hls *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_HIGH - XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_PT_BASE + offset + i);
    }
    return length;
}

u32 XRijndaeldecrypt_hls_Get_rk_BaseAddress(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_BASE);
}

u32 XRijndaeldecrypt_hls_Get_rk_HighAddress(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_HIGH);
}

u32 XRijndaeldecrypt_hls_Get_rk_TotalBytes(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_HIGH - XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_BASE + 1);
}

u32 XRijndaeldecrypt_hls_Get_rk_BitWidth(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRIJNDAELDECRYPT_HLS_BUS_WIDTH_RK;
}

u32 XRijndaeldecrypt_hls_Get_rk_Depth(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRIJNDAELDECRYPT_HLS_BUS_DEPTH_RK;
}

u32 XRijndaeldecrypt_hls_Write_rk_Words(XRijndaeldecrypt_hls *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_HIGH - XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XRijndaeldecrypt_hls_Read_rk_Words(XRijndaeldecrypt_hls *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_HIGH - XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_BASE + (offset + i)*4);
    }
    return length;
}

u32 XRijndaeldecrypt_hls_Write_rk_Bytes(XRijndaeldecrypt_hls *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_HIGH - XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XRijndaeldecrypt_hls_Read_rk_Bytes(XRijndaeldecrypt_hls *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_HIGH - XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Bus_BaseAddress + XRIJNDAELDECRYPT_HLS_BUS_ADDR_RK_BASE + offset + i);
    }
    return length;
}

void XRijndaeldecrypt_hls_InterruptGlobalEnable(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRijndaeldecrypt_hls_WriteReg(InstancePtr->Bus_BaseAddress, XRIJNDAELDECRYPT_HLS_BUS_ADDR_GIE, 1);
}

void XRijndaeldecrypt_hls_InterruptGlobalDisable(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRijndaeldecrypt_hls_WriteReg(InstancePtr->Bus_BaseAddress, XRIJNDAELDECRYPT_HLS_BUS_ADDR_GIE, 0);
}

void XRijndaeldecrypt_hls_InterruptEnable(XRijndaeldecrypt_hls *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XRijndaeldecrypt_hls_ReadReg(InstancePtr->Bus_BaseAddress, XRIJNDAELDECRYPT_HLS_BUS_ADDR_IER);
    XRijndaeldecrypt_hls_WriteReg(InstancePtr->Bus_BaseAddress, XRIJNDAELDECRYPT_HLS_BUS_ADDR_IER, Register | Mask);
}

void XRijndaeldecrypt_hls_InterruptDisable(XRijndaeldecrypt_hls *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XRijndaeldecrypt_hls_ReadReg(InstancePtr->Bus_BaseAddress, XRIJNDAELDECRYPT_HLS_BUS_ADDR_IER);
    XRijndaeldecrypt_hls_WriteReg(InstancePtr->Bus_BaseAddress, XRIJNDAELDECRYPT_HLS_BUS_ADDR_IER, Register & (~Mask));
}

void XRijndaeldecrypt_hls_InterruptClear(XRijndaeldecrypt_hls *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XRijndaeldecrypt_hls_WriteReg(InstancePtr->Bus_BaseAddress, XRIJNDAELDECRYPT_HLS_BUS_ADDR_ISR, Mask);
}

u32 XRijndaeldecrypt_hls_InterruptGetEnabled(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRijndaeldecrypt_hls_ReadReg(InstancePtr->Bus_BaseAddress, XRIJNDAELDECRYPT_HLS_BUS_ADDR_IER);
}

u32 XRijndaeldecrypt_hls_InterruptGetStatus(XRijndaeldecrypt_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XRijndaeldecrypt_hls_ReadReg(InstancePtr->Bus_BaseAddress, XRIJNDAELDECRYPT_HLS_BUS_ADDR_ISR);
}

