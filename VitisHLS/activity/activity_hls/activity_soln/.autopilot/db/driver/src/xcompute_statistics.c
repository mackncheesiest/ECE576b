// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xcompute_statistics.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XCompute_statistics_CfgInitialize(XCompute_statistics *InstancePtr, XCompute_statistics_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Bus_a_BaseAddress = ConfigPtr->Bus_a_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XCompute_statistics_Start(XCompute_statistics *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_AP_CTRL) & 0x80;
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_AP_CTRL, Data | 0x01);
}

u32 XCompute_statistics_IsDone(XCompute_statistics *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XCompute_statistics_IsIdle(XCompute_statistics *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XCompute_statistics_IsReady(XCompute_statistics *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XCompute_statistics_EnableAutoRestart(XCompute_statistics *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_AP_CTRL, 0x80);
}

void XCompute_statistics_DisableAutoRestart(XCompute_statistics *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_AP_CTRL, 0);
}

void XCompute_statistics_Set_vals_i(XCompute_statistics *InstancePtr, XCompute_statistics_Vals_i Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 0, Data.word_0);
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 4, Data.word_1);
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 8, Data.word_2);
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 12, Data.word_3);
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 16, Data.word_4);
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 20, Data.word_5);
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 24, Data.word_6);
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 28, Data.word_7);
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 32, Data.word_8);
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 36, Data.word_9);
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 40, Data.word_10);
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 44, Data.word_11);
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 48, Data.word_12);
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 52, Data.word_13);
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 56, Data.word_14);
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 60, Data.word_15);
}

XCompute_statistics_Vals_i XCompute_statistics_Get_vals_i(XCompute_statistics *InstancePtr) {
    XCompute_statistics_Vals_i Data;

    Data.word_0 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 0);
    Data.word_1 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 4);
    Data.word_2 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 8);
    Data.word_3 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 12);
    Data.word_4 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 16);
    Data.word_5 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 20);
    Data.word_6 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 24);
    Data.word_7 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 28);
    Data.word_8 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 32);
    Data.word_9 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 36);
    Data.word_10 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 40);
    Data.word_11 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 44);
    Data.word_12 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 48);
    Data.word_13 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 52);
    Data.word_14 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 56);
    Data.word_15 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_I_DATA + 60);
    return Data;
}

XCompute_statistics_Vals_o XCompute_statistics_Get_vals_o(XCompute_statistics *InstancePtr) {
    XCompute_statistics_Vals_o Data;

    Data.word_0 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA + 0);
    Data.word_1 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA + 4);
    Data.word_2 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA + 8);
    Data.word_3 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA + 12);
    Data.word_4 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA + 16);
    Data.word_5 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA + 20);
    Data.word_6 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA + 24);
    Data.word_7 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA + 28);
    Data.word_8 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA + 32);
    Data.word_9 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA + 36);
    Data.word_10 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA + 40);
    Data.word_11 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA + 44);
    Data.word_12 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA + 48);
    Data.word_13 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA + 52);
    Data.word_14 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA + 56);
    Data.word_15 = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_DATA + 60);
    return Data;
}

u32 XCompute_statistics_Get_vals_o_vld(XCompute_statistics *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_VALS_O_CTRL);
    return Data & 0x1;
}

u32 XCompute_statistics_Get_hr_BaseAddress(XCompute_statistics *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Bus_a_BaseAddress + XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_BASE);
}

u32 XCompute_statistics_Get_hr_HighAddress(XCompute_statistics *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Bus_a_BaseAddress + XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_HIGH);
}

u32 XCompute_statistics_Get_hr_TotalBytes(XCompute_statistics *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_HIGH - XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_BASE + 1);
}

u32 XCompute_statistics_Get_hr_BitWidth(XCompute_statistics *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCOMPUTE_STATISTICS_BUS_A_WIDTH_HR;
}

u32 XCompute_statistics_Get_hr_Depth(XCompute_statistics *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCOMPUTE_STATISTICS_BUS_A_DEPTH_HR;
}

u32 XCompute_statistics_Write_hr_Words(XCompute_statistics *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_HIGH - XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Bus_a_BaseAddress + XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XCompute_statistics_Read_hr_Words(XCompute_statistics *InstancePtr, int offset, word_type *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_HIGH - XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Bus_a_BaseAddress + XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_BASE + (offset + i)*4);
    }
    return length;
}

u32 XCompute_statistics_Write_hr_Bytes(XCompute_statistics *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_HIGH - XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Bus_a_BaseAddress + XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XCompute_statistics_Read_hr_Bytes(XCompute_statistics *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_HIGH - XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Bus_a_BaseAddress + XCOMPUTE_STATISTICS_BUS_A_ADDR_HR_BASE + offset + i);
    }
    return length;
}

void XCompute_statistics_InterruptGlobalEnable(XCompute_statistics *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_GIE, 1);
}

void XCompute_statistics_InterruptGlobalDisable(XCompute_statistics *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_GIE, 0);
}

void XCompute_statistics_InterruptEnable(XCompute_statistics *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_IER);
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_IER, Register | Mask);
}

void XCompute_statistics_InterruptDisable(XCompute_statistics *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_IER);
    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_IER, Register & (~Mask));
}

void XCompute_statistics_InterruptClear(XCompute_statistics *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XCompute_statistics_WriteReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_ISR, Mask);
}

u32 XCompute_statistics_InterruptGetEnabled(XCompute_statistics *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_IER);
}

u32 XCompute_statistics_InterruptGetStatus(XCompute_statistics *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XCompute_statistics_ReadReg(InstancePtr->Bus_a_BaseAddress, XCOMPUTE_STATISTICS_BUS_A_ADDR_ISR);
}

