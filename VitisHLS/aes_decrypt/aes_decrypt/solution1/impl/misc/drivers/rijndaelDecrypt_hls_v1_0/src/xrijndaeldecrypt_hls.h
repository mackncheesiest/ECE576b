// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XRIJNDAELDECRYPT_HLS_H
#define XRIJNDAELDECRYPT_HLS_H

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
#include "xrijndaeldecrypt_hls_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u32 Bus_BaseAddress;
} XRijndaeldecrypt_hls_Config;
#endif

typedef struct {
    u64 Bus_BaseAddress;
    u32 IsReady;
} XRijndaeldecrypt_hls;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XRijndaeldecrypt_hls_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XRijndaeldecrypt_hls_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XRijndaeldecrypt_hls_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XRijndaeldecrypt_hls_ReadReg(BaseAddress, RegOffset) \
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
int XRijndaeldecrypt_hls_Initialize(XRijndaeldecrypt_hls *InstancePtr, u16 DeviceId);
XRijndaeldecrypt_hls_Config* XRijndaeldecrypt_hls_LookupConfig(u16 DeviceId);
int XRijndaeldecrypt_hls_CfgInitialize(XRijndaeldecrypt_hls *InstancePtr, XRijndaeldecrypt_hls_Config *ConfigPtr);
#else
int XRijndaeldecrypt_hls_Initialize(XRijndaeldecrypt_hls *InstancePtr, const char* InstanceName);
int XRijndaeldecrypt_hls_Release(XRijndaeldecrypt_hls *InstancePtr);
#endif

void XRijndaeldecrypt_hls_Start(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_IsDone(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_IsIdle(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_IsReady(XRijndaeldecrypt_hls *InstancePtr);
void XRijndaeldecrypt_hls_EnableAutoRestart(XRijndaeldecrypt_hls *InstancePtr);
void XRijndaeldecrypt_hls_DisableAutoRestart(XRijndaeldecrypt_hls *InstancePtr);

u32 XRijndaeldecrypt_hls_Get_ct_BaseAddress(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_Get_ct_HighAddress(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_Get_ct_TotalBytes(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_Get_ct_BitWidth(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_Get_ct_Depth(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_Write_ct_Words(XRijndaeldecrypt_hls *InstancePtr, int offset, word_type *data, int length);
u32 XRijndaeldecrypt_hls_Read_ct_Words(XRijndaeldecrypt_hls *InstancePtr, int offset, word_type *data, int length);
u32 XRijndaeldecrypt_hls_Write_ct_Bytes(XRijndaeldecrypt_hls *InstancePtr, int offset, char *data, int length);
u32 XRijndaeldecrypt_hls_Read_ct_Bytes(XRijndaeldecrypt_hls *InstancePtr, int offset, char *data, int length);
u32 XRijndaeldecrypt_hls_Get_pt_BaseAddress(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_Get_pt_HighAddress(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_Get_pt_TotalBytes(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_Get_pt_BitWidth(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_Get_pt_Depth(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_Write_pt_Words(XRijndaeldecrypt_hls *InstancePtr, int offset, word_type *data, int length);
u32 XRijndaeldecrypt_hls_Read_pt_Words(XRijndaeldecrypt_hls *InstancePtr, int offset, word_type *data, int length);
u32 XRijndaeldecrypt_hls_Write_pt_Bytes(XRijndaeldecrypt_hls *InstancePtr, int offset, char *data, int length);
u32 XRijndaeldecrypt_hls_Read_pt_Bytes(XRijndaeldecrypt_hls *InstancePtr, int offset, char *data, int length);
u32 XRijndaeldecrypt_hls_Get_rk_BaseAddress(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_Get_rk_HighAddress(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_Get_rk_TotalBytes(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_Get_rk_BitWidth(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_Get_rk_Depth(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_Write_rk_Words(XRijndaeldecrypt_hls *InstancePtr, int offset, word_type *data, int length);
u32 XRijndaeldecrypt_hls_Read_rk_Words(XRijndaeldecrypt_hls *InstancePtr, int offset, word_type *data, int length);
u32 XRijndaeldecrypt_hls_Write_rk_Bytes(XRijndaeldecrypt_hls *InstancePtr, int offset, char *data, int length);
u32 XRijndaeldecrypt_hls_Read_rk_Bytes(XRijndaeldecrypt_hls *InstancePtr, int offset, char *data, int length);

void XRijndaeldecrypt_hls_InterruptGlobalEnable(XRijndaeldecrypt_hls *InstancePtr);
void XRijndaeldecrypt_hls_InterruptGlobalDisable(XRijndaeldecrypt_hls *InstancePtr);
void XRijndaeldecrypt_hls_InterruptEnable(XRijndaeldecrypt_hls *InstancePtr, u32 Mask);
void XRijndaeldecrypt_hls_InterruptDisable(XRijndaeldecrypt_hls *InstancePtr, u32 Mask);
void XRijndaeldecrypt_hls_InterruptClear(XRijndaeldecrypt_hls *InstancePtr, u32 Mask);
u32 XRijndaeldecrypt_hls_InterruptGetEnabled(XRijndaeldecrypt_hls *InstancePtr);
u32 XRijndaeldecrypt_hls_InterruptGetStatus(XRijndaeldecrypt_hls *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
