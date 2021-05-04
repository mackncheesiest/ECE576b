// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XRIJNDAELENCRYPT_HLS_H
#define XRIJNDAELENCRYPT_HLS_H

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
#include "xrijndaelencrypt_hls_hw.h"

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
} XRijndaelencrypt_hls_Config;
#endif

typedef struct {
    u64 Bus_a_BaseAddress;
    u32 IsReady;
} XRijndaelencrypt_hls;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XRijndaelencrypt_hls_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XRijndaelencrypt_hls_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XRijndaelencrypt_hls_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XRijndaelencrypt_hls_ReadReg(BaseAddress, RegOffset) \
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
int XRijndaelencrypt_hls_Initialize(XRijndaelencrypt_hls *InstancePtr, u16 DeviceId);
XRijndaelencrypt_hls_Config* XRijndaelencrypt_hls_LookupConfig(u16 DeviceId);
int XRijndaelencrypt_hls_CfgInitialize(XRijndaelencrypt_hls *InstancePtr, XRijndaelencrypt_hls_Config *ConfigPtr);
#else
int XRijndaelencrypt_hls_Initialize(XRijndaelencrypt_hls *InstancePtr, const char* InstanceName);
int XRijndaelencrypt_hls_Release(XRijndaelencrypt_hls *InstancePtr);
#endif

void XRijndaelencrypt_hls_Start(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_IsDone(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_IsIdle(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_IsReady(XRijndaelencrypt_hls *InstancePtr);
void XRijndaelencrypt_hls_EnableAutoRestart(XRijndaelencrypt_hls *InstancePtr);
void XRijndaelencrypt_hls_DisableAutoRestart(XRijndaelencrypt_hls *InstancePtr);

u32 XRijndaelencrypt_hls_Get_pt_BaseAddress(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_Get_pt_HighAddress(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_Get_pt_TotalBytes(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_Get_pt_BitWidth(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_Get_pt_Depth(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_Write_pt_Words(XRijndaelencrypt_hls *InstancePtr, int offset, word_type *data, int length);
u32 XRijndaelencrypt_hls_Read_pt_Words(XRijndaelencrypt_hls *InstancePtr, int offset, word_type *data, int length);
u32 XRijndaelencrypt_hls_Write_pt_Bytes(XRijndaelencrypt_hls *InstancePtr, int offset, char *data, int length);
u32 XRijndaelencrypt_hls_Read_pt_Bytes(XRijndaelencrypt_hls *InstancePtr, int offset, char *data, int length);
u32 XRijndaelencrypt_hls_Get_ct_BaseAddress(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_Get_ct_HighAddress(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_Get_ct_TotalBytes(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_Get_ct_BitWidth(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_Get_ct_Depth(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_Write_ct_Words(XRijndaelencrypt_hls *InstancePtr, int offset, word_type *data, int length);
u32 XRijndaelencrypt_hls_Read_ct_Words(XRijndaelencrypt_hls *InstancePtr, int offset, word_type *data, int length);
u32 XRijndaelencrypt_hls_Write_ct_Bytes(XRijndaelencrypt_hls *InstancePtr, int offset, char *data, int length);
u32 XRijndaelencrypt_hls_Read_ct_Bytes(XRijndaelencrypt_hls *InstancePtr, int offset, char *data, int length);
u32 XRijndaelencrypt_hls_Get_rk_BaseAddress(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_Get_rk_HighAddress(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_Get_rk_TotalBytes(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_Get_rk_BitWidth(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_Get_rk_Depth(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_Write_rk_Words(XRijndaelencrypt_hls *InstancePtr, int offset, word_type *data, int length);
u32 XRijndaelencrypt_hls_Read_rk_Words(XRijndaelencrypt_hls *InstancePtr, int offset, word_type *data, int length);
u32 XRijndaelencrypt_hls_Write_rk_Bytes(XRijndaelencrypt_hls *InstancePtr, int offset, char *data, int length);
u32 XRijndaelencrypt_hls_Read_rk_Bytes(XRijndaelencrypt_hls *InstancePtr, int offset, char *data, int length);

void XRijndaelencrypt_hls_InterruptGlobalEnable(XRijndaelencrypt_hls *InstancePtr);
void XRijndaelencrypt_hls_InterruptGlobalDisable(XRijndaelencrypt_hls *InstancePtr);
void XRijndaelencrypt_hls_InterruptEnable(XRijndaelencrypt_hls *InstancePtr, u32 Mask);
void XRijndaelencrypt_hls_InterruptDisable(XRijndaelencrypt_hls *InstancePtr, u32 Mask);
void XRijndaelencrypt_hls_InterruptClear(XRijndaelencrypt_hls *InstancePtr, u32 Mask);
u32 XRijndaelencrypt_hls_InterruptGetEnabled(XRijndaelencrypt_hls *InstancePtr);
u32 XRijndaelencrypt_hls_InterruptGetStatus(XRijndaelencrypt_hls *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
