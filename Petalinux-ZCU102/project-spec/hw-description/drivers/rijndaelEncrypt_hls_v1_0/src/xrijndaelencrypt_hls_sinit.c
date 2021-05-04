// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xrijndaelencrypt_hls.h"

extern XRijndaelencrypt_hls_Config XRijndaelencrypt_hls_ConfigTable[];

XRijndaelencrypt_hls_Config *XRijndaelencrypt_hls_LookupConfig(u16 DeviceId) {
	XRijndaelencrypt_hls_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XRIJNDAELENCRYPT_HLS_NUM_INSTANCES; Index++) {
		if (XRijndaelencrypt_hls_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XRijndaelencrypt_hls_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XRijndaelencrypt_hls_Initialize(XRijndaelencrypt_hls *InstancePtr, u16 DeviceId) {
	XRijndaelencrypt_hls_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XRijndaelencrypt_hls_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XRijndaelencrypt_hls_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

