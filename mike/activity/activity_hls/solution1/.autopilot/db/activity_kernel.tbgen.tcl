set moduleName activity_kernel
set isTopModule 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {activity_kernel}
set C_modelType { void 0 }
set C_modelArgList {
	{ len int 32 regular  }
	{ hr int 64 regular {pointer 0}  }
	{ t int 64 regular {pointer 0}  }
	{ meanhr int 64 regular {pointer 1}  }
	{ tpower int 64 regular {pointer 1}  }
	{ stationarity int 64 regular {pointer 1}  }
	{ activity int 64 regular {pointer 1}  }
	{ acmin int 64 regular {pointer 2}  }
	{ hrmin int 64 regular {pointer 1}  }
	{ stmin int 64 regular {pointer 1}  }
	{ tpmin int 64 regular {pointer 1}  }
	{ tmin0 int 64 regular {pointer 1}  }
	{ tmin1 int 64 regular {pointer 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "len", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "len","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "hr", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "hr","cData": "long","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "t", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "t","cData": "long","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "meanhr", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "meanhr","cData": "long","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "tpower", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "tpower","cData": "long","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "stationarity", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "stationarity","cData": "long","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "activity", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "activity","cData": "long","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "acmin", "interface" : "wire", "bitwidth" : 64, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "acmin","cData": "long","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "hrmin", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "hrmin","cData": "long","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "stmin", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "stmin","cData": "long","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "tpmin", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "tpmin","cData": "long","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "tmin0", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "tmin0","cData": "long","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "tmin1", "interface" : "wire", "bitwidth" : 64, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "tmin1","cData": "long","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} ]}
# RTL Port declarations: 
set portNum 30
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ len sc_in sc_lv 32 signal 0 } 
	{ hr sc_in sc_lv 64 signal 1 } 
	{ t sc_in sc_lv 64 signal 2 } 
	{ meanhr sc_out sc_lv 64 signal 3 } 
	{ meanhr_ap_vld sc_out sc_logic 1 outvld 3 } 
	{ tpower sc_out sc_lv 64 signal 4 } 
	{ tpower_ap_vld sc_out sc_logic 1 outvld 4 } 
	{ stationarity sc_out sc_lv 64 signal 5 } 
	{ stationarity_ap_vld sc_out sc_logic 1 outvld 5 } 
	{ activity sc_out sc_lv 64 signal 6 } 
	{ activity_ap_vld sc_out sc_logic 1 outvld 6 } 
	{ acmin_i sc_in sc_lv 64 signal 7 } 
	{ acmin_o sc_out sc_lv 64 signal 7 } 
	{ acmin_o_ap_vld sc_out sc_logic 1 outvld 7 } 
	{ hrmin sc_out sc_lv 64 signal 8 } 
	{ hrmin_ap_vld sc_out sc_logic 1 outvld 8 } 
	{ stmin sc_out sc_lv 64 signal 9 } 
	{ stmin_ap_vld sc_out sc_logic 1 outvld 9 } 
	{ tpmin sc_out sc_lv 64 signal 10 } 
	{ tpmin_ap_vld sc_out sc_logic 1 outvld 10 } 
	{ tmin0 sc_out sc_lv 64 signal 11 } 
	{ tmin0_ap_vld sc_out sc_logic 1 outvld 11 } 
	{ tmin1 sc_out sc_lv 64 signal 12 } 
	{ tmin1_ap_vld sc_out sc_logic 1 outvld 12 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "len", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "len", "role": "default" }} , 
 	{ "name": "hr", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "hr", "role": "default" }} , 
 	{ "name": "t", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "t", "role": "default" }} , 
 	{ "name": "meanhr", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "meanhr", "role": "default" }} , 
 	{ "name": "meanhr_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "meanhr", "role": "ap_vld" }} , 
 	{ "name": "tpower", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "tpower", "role": "default" }} , 
 	{ "name": "tpower_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "tpower", "role": "ap_vld" }} , 
 	{ "name": "stationarity", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "stationarity", "role": "default" }} , 
 	{ "name": "stationarity_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "stationarity", "role": "ap_vld" }} , 
 	{ "name": "activity", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "activity", "role": "default" }} , 
 	{ "name": "activity_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "activity", "role": "ap_vld" }} , 
 	{ "name": "acmin_i", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "acmin", "role": "i" }} , 
 	{ "name": "acmin_o", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "acmin", "role": "o" }} , 
 	{ "name": "acmin_o_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "acmin", "role": "o_ap_vld" }} , 
 	{ "name": "hrmin", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "hrmin", "role": "default" }} , 
 	{ "name": "hrmin_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "hrmin", "role": "ap_vld" }} , 
 	{ "name": "stmin", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "stmin", "role": "default" }} , 
 	{ "name": "stmin_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "stmin", "role": "ap_vld" }} , 
 	{ "name": "tpmin", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "tpmin", "role": "default" }} , 
 	{ "name": "tpmin_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "tpmin", "role": "ap_vld" }} , 
 	{ "name": "tmin0", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "tmin0", "role": "default" }} , 
 	{ "name": "tmin0_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "tmin0", "role": "ap_vld" }} , 
 	{ "name": "tmin1", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "tmin1", "role": "default" }} , 
 	{ "name": "tmin1_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "tmin1", "role": "ap_vld" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"],
		"CDFG" : "activity_kernel",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "len", "Type" : "None", "Direction" : "I"},
			{"Name" : "hr", "Type" : "None", "Direction" : "I"},
			{"Name" : "t", "Type" : "None", "Direction" : "I"},
			{"Name" : "meanhr", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "tpower", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "stationarity", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "activity", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "acmin", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "hrmin", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "stmin", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "tpmin", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "tmin0", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "tmin1", "Type" : "Vld", "Direction" : "O"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dadddsub_64ns_64ns_64_2_full_dsp_1_U1", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dsub_64ns_64ns_64_2_full_dsp_1_U2", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dmul_64ns_64ns_64_2_max_dsp_1_U3", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dmul_64ns_64ns_64_2_max_dsp_1_U4", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ddiv_64ns_64ns_64_6_no_dsp_1_U5", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ddiv_64ns_64ns_64_6_no_dsp_1_U6", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dcmp_64ns_64ns_1_1_no_dsp_1_U7", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dcmp_64ns_64ns_1_1_no_dsp_1_U8", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.sitodp_32ns_64_2_no_dsp_1_U9", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dsqrt_64ns_64ns_64_6_no_dsp_1_U10", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dacc_64ns_64ns_1ns_64_3_no_dsp_1_U11", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.dacc_64ns_64ns_1ns_64_3_no_dsp_1_U12", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	activity_kernel {
		len {Type I LastRead 0 FirstWrite -1}
		hr {Type I LastRead 0 FirstWrite -1}
		t {Type I LastRead 36 FirstWrite -1}
		meanhr {Type O LastRead -1 FirstWrite 14}
		tpower {Type O LastRead -1 FirstWrite 26}
		stationarity {Type O LastRead -1 FirstWrite 14}
		activity {Type O LastRead -1 FirstWrite 36}
		acmin {Type IO LastRead 36 FirstWrite 36}
		hrmin {Type O LastRead -1 FirstWrite 36}
		stmin {Type O LastRead -1 FirstWrite 36}
		tpmin {Type O LastRead -1 FirstWrite 36}
		tmin0 {Type O LastRead -1 FirstWrite 36}
		tmin1 {Type O LastRead -1 FirstWrite 36}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "0", "Max" : "0"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
	{"Pipeline" : "2", "EnableSignal" : "ap_enable_pp2"}
]}

set Spec2ImplPortList { 
	len { ap_none {  { len in_data 0 32 } } }
	hr { ap_none {  { hr in_data 0 64 } } }
	t { ap_none {  { t in_data 0 64 } } }
	meanhr { ap_vld {  { meanhr out_data 1 64 }  { meanhr_ap_vld out_vld 1 1 } } }
	tpower { ap_vld {  { tpower out_data 1 64 }  { tpower_ap_vld out_vld 1 1 } } }
	stationarity { ap_vld {  { stationarity out_data 1 64 }  { stationarity_ap_vld out_vld 1 1 } } }
	activity { ap_vld {  { activity out_data 1 64 }  { activity_ap_vld out_vld 1 1 } } }
	acmin { ap_ovld {  { acmin_i in_data 0 64 }  { acmin_o out_data 1 64 }  { acmin_o_ap_vld out_vld 1 1 } } }
	hrmin { ap_vld {  { hrmin out_data 1 64 }  { hrmin_ap_vld out_vld 1 1 } } }
	stmin { ap_vld {  { stmin out_data 1 64 }  { stmin_ap_vld out_vld 1 1 } } }
	tpmin { ap_vld {  { tpmin out_data 1 64 }  { tpmin_ap_vld out_vld 1 1 } } }
	tmin0 { ap_vld {  { tmin0 out_data 1 64 }  { tmin0_ap_vld out_vld 1 1 } } }
	tmin1 { ap_vld {  { tmin1 out_data 1 64 }  { tmin1_ap_vld out_vld 1 1 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
