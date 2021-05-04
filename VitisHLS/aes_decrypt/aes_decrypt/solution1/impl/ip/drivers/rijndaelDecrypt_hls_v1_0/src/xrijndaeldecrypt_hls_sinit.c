// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xrijndaeldecrypt_hls.h"

extern XRijndaeldecrypt_hls_Config XRijndaeldecrypt_hls_ConfigTable[];

XRijndaeldecrypt_hls_Config *XRijndaeldecrypt_hls_LookupConfig(u16 DeviceId) {
	XRijndaeldecrypt_hls_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XRIJNDAELDECRYPT_HLS_NUM_INSTANCES; Index++) {
		if (XRijndaeldecrypt_hls_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XRijndaeldecrypt_hls_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XRijndaeldecrypt_hls_Initialize(XRijndaeldecrypt_hls *InstancePtr, u16 DeviceId) {
	XRijndaeldecrypt_hls_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XRijndaeldecrypt_hls_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XRijndaeldecrypt_hls_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

