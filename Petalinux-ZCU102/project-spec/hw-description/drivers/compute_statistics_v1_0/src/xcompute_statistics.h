// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XCOMPUTE_STATISTICS_H
#define XCOMPUTE_STATISTICS_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xcompute_statistics_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u32 Bus_a_BaseAddress;
} XCompute_statistics_Config;
#endif

typedef struct {
    u64 Bus_a_BaseAddress;
    u32 IsReady;
} XCompute_statistics;

typedef u32 word_type;

typedef struct {
    u32 word_0;
    u32 word_1;
    u32 word_2;
    u32 word_3;
    u32 word_4;
    u32 word_5;
    u32 word_6;
    u32 word_7;
    u32 word_8;
    u32 word_9;
    u32 word_10;
    u32 word_11;
    u32 word_12;
    u32 word_13;
    u32 word_14;
    u32 word_15;
} XCompute_statistics_Vals_i;

typedef struct {
    u32 word_0;
    u32 word_1;
    u32 word_2;
    u32 word_3;
    u32 word_4;
    u32 word_5;
    u32 word_6;
    u32 word_7;
    u32 word_8;
    u32 word_9;
    u32 word_10;
    u32 word_11;
    u32 word_12;
    u32 word_13;
    u32 word_14;
    u32 word_15;
} XCompute_statistics_Vals_o;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XCompute_statistics_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XCompute_statistics_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XCompute_statistics_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XCompute_statistics_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XCompute_statistics_Initialize(XCompute_statistics *InstancePtr, u16 DeviceId);
XCompute_statistics_Config* XCompute_statistics_LookupConfig(u16 DeviceId);
int XCompute_statistics_CfgInitialize(XCompute_statistics *InstancePtr, XCompute_statistics_Config *ConfigPtr);
#else
int XCompute_statistics_Initialize(XCompute_statistics *InstancePtr, const char* InstanceName);
int XCompute_statistics_Release(XCompute_statistics *InstancePtr);
#endif

void XCompute_statistics_Start(XCompute_statistics *InstancePtr);
u32 XCompute_statistics_IsDone(XCompute_statistics *InstancePtr);
u32 XCompute_statistics_IsIdle(XCompute_statistics *InstancePtr);
u32 XCompute_statistics_IsReady(XCompute_statistics *InstancePtr);
void XCompute_statistics_EnableAutoRestart(XCompute_statistics *InstancePtr);
void XCompute_statistics_DisableAutoRestart(XCompute_statistics *InstancePtr);

void XCompute_statistics_Set_vals_i(XCompute_statistics *InstancePtr, XCompute_statistics_Vals_i Data);
XCompute_statistics_Vals_i XCompute_statistics_Get_vals_i(XCompute_statistics *InstancePtr);
XCompute_statistics_Vals_o XCompute_statistics_Get_vals_o(XCompute_statistics *InstancePtr);
u32 XCompute_statistics_Get_vals_o_vld(XCompute_statistics *InstancePtr);
u32 XCompute_statistics_Get_hr_BaseAddress(XCompute_statistics *InstancePtr);
u32 XCompute_statistics_Get_hr_HighAddress(XCompute_statistics *InstancePtr);
u32 XCompute_statistics_Get_hr_TotalBytes(XCompute_statistics *InstancePtr);
u32 XCompute_statistics_Get_hr_BitWidth(XCompute_statistics *InstancePtr);
u32 XCompute_statistics_Get_hr_Depth(XCompute_statistics *InstancePtr);
u32 XCompute_statistics_Write_hr_Words(XCompute_statistics *InstancePtr, int offset, word_type *data, int length);
u32 XCompute_statistics_Read_hr_Words(XCompute_statistics *InstancePtr, int offset, word_type *data, int length);
u32 XCompute_statistics_Write_hr_Bytes(XCompute_statistics *InstancePtr, int offset, char *data, int length);
u32 XCompute_statistics_Read_hr_Bytes(XCompute_statistics *InstancePtr, int offset, char *data, int length);

void XCompute_statistics_InterruptGlobalEnable(XCompute_statistics *InstancePtr);
void XCompute_statistics_InterruptGlobalDisable(XCompute_statistics *InstancePtr);
void XCompute_statistics_InterruptEnable(XCompute_statistics *InstancePtr, u32 Mask);
void XCompute_statistics_InterruptDisable(XCompute_statistics *InstancePtr, u32 Mask);
void XCompute_statistics_InterruptClear(XCompute_statistics *InstancePtr, u32 Mask);
u32 XCompute_statistics_InterruptGetEnabled(XCompute_statistics *InstancePtr);
u32 XCompute_statistics_InterruptGetStatus(XCompute_statistics *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
