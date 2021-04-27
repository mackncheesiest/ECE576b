// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xcompute_statistics.h"

extern XCompute_statistics_Config XCompute_statistics_ConfigTable[];

XCompute_statistics_Config *XCompute_statistics_LookupConfig(u16 DeviceId) {
	XCompute_statistics_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XCOMPUTE_STATISTICS_NUM_INSTANCES; Index++) {
		if (XCompute_statistics_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XCompute_statistics_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XCompute_statistics_Initialize(XCompute_statistics *InstancePtr, u16 DeviceId) {
	XCompute_statistics_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XCompute_statistics_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XCompute_statistics_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

