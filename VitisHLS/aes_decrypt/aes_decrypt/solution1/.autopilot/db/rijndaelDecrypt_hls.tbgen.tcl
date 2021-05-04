set moduleName rijndaelDecrypt_hls
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
set C_modelName {rijndaelDecrypt_hls}
set C_modelType { void 0 }
set C_modelArgList {
	{ rk int 32 regular {axi_slave 0}  }
	{ ct int 8 regular {axi_slave 0}  }
	{ pt int 8 regular {axi_slave 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "rk", "interface" : "axi_slave", "bundle":"BUS","type":"ap_memory","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "rk","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":256}, "offset_end" : {"in":511}} , 
 	{ "Name" : "ct", "interface" : "axi_slave", "bundle":"BUS","type":"ap_memory","bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "ct","cData": "char","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":16}, "offset_end" : {"in":31}} , 
 	{ "Name" : "pt", "interface" : "axi_slave", "bundle":"BUS","type":"ap_memory","bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "pt","cData": "char","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"out":32}, "offset_end" : {"out":47}} ]}
# RTL Port declarations: 
set portNum 20
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ s_axi_BUS_AWVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_BUS_AWREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_BUS_AWADDR sc_in sc_lv 9 signal -1 } 
	{ s_axi_BUS_WVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_BUS_WREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_BUS_WDATA sc_in sc_lv 32 signal -1 } 
	{ s_axi_BUS_WSTRB sc_in sc_lv 4 signal -1 } 
	{ s_axi_BUS_ARVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_BUS_ARREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_BUS_ARADDR sc_in sc_lv 9 signal -1 } 
	{ s_axi_BUS_RVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_BUS_RREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_BUS_RDATA sc_out sc_lv 32 signal -1 } 
	{ s_axi_BUS_RRESP sc_out sc_lv 2 signal -1 } 
	{ s_axi_BUS_BVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_BUS_BREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_BUS_BRESP sc_out sc_lv 2 signal -1 } 
	{ interrupt sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "s_axi_BUS_AWADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "BUS", "role": "AWADDR" },"address":[{"name":"rijndaelDecrypt_hls","role":"start","value":"0","valid_bit":"0"},{"name":"rijndaelDecrypt_hls","role":"continue","value":"0","valid_bit":"4"},{"name":"rijndaelDecrypt_hls","role":"auto_start","value":"0","valid_bit":"7"},{"name":"ct","role":"data","value":"16"},{"name":"rk","role":"data","value":"256"}] },
	{ "name": "s_axi_BUS_AWVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "BUS", "role": "AWVALID" } },
	{ "name": "s_axi_BUS_AWREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "BUS", "role": "AWREADY" } },
	{ "name": "s_axi_BUS_WVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "BUS", "role": "WVALID" } },
	{ "name": "s_axi_BUS_WREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "BUS", "role": "WREADY" } },
	{ "name": "s_axi_BUS_WDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "BUS", "role": "WDATA" } },
	{ "name": "s_axi_BUS_WSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "BUS", "role": "WSTRB" } },
	{ "name": "s_axi_BUS_ARADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "BUS", "role": "ARADDR" },"address":[{"name":"rijndaelDecrypt_hls","role":"start","value":"0","valid_bit":"0"},{"name":"rijndaelDecrypt_hls","role":"done","value":"0","valid_bit":"1"},{"name":"rijndaelDecrypt_hls","role":"idle","value":"0","valid_bit":"2"},{"name":"rijndaelDecrypt_hls","role":"ready","value":"0","valid_bit":"3"},{"name":"rijndaelDecrypt_hls","role":"auto_start","value":"0","valid_bit":"7"},{"name":"pt","role":"data","value":"32"}] },
	{ "name": "s_axi_BUS_ARVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "BUS", "role": "ARVALID" } },
	{ "name": "s_axi_BUS_ARREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "BUS", "role": "ARREADY" } },
	{ "name": "s_axi_BUS_RVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "BUS", "role": "RVALID" } },
	{ "name": "s_axi_BUS_RREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "BUS", "role": "RREADY" } },
	{ "name": "s_axi_BUS_RDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "BUS", "role": "RDATA" } },
	{ "name": "s_axi_BUS_RRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "BUS", "role": "RRESP" } },
	{ "name": "s_axi_BUS_BVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "BUS", "role": "BVALID" } },
	{ "name": "s_axi_BUS_BREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "BUS", "role": "BREADY" } },
	{ "name": "s_axi_BUS_BRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "BUS", "role": "BRESP" } },
	{ "name": "interrupt", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "BUS", "role": "interrupt" } }, 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6"],
		"CDFG" : "rijndaelDecrypt_hls",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "183", "EstimateLatencyMax" : "183",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "rk", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "ct", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "pt", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "Td0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "Td4s", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.Td0_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.Td4s_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.BUS_s_axi_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_rotr_fu_2177", "Parent" : "0",
		"CDFG" : "rotr",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "2", "EstimateLatencyMax" : "2",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "val_r", "Type" : "None", "Direction" : "I"},
			{"Name" : "bits", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_rotr_fu_2184", "Parent" : "0",
		"CDFG" : "rotr",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "2", "EstimateLatencyMax" : "2",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "val_r", "Type" : "None", "Direction" : "I"},
			{"Name" : "bits", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_rotr_fu_2191", "Parent" : "0",
		"CDFG" : "rotr",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "2", "EstimateLatencyMax" : "2",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "val_r", "Type" : "None", "Direction" : "I"},
			{"Name" : "bits", "Type" : "None", "Direction" : "I"}]}]}


set ArgLastReadFirstWriteLatency {
	rijndaelDecrypt_hls {
		rk {Type I LastRead 106 FirstWrite -1}
		ct {Type I LastRead 15 FirstWrite -1}
		pt {Type O LastRead -1 FirstWrite 96}
		Td0 {Type I LastRead -1 FirstWrite -1}
		Td4s {Type I LastRead -1 FirstWrite -1}}
	rotr {
		val_r {Type I LastRead 1 FirstWrite -1}
		bits {Type I LastRead 0 FirstWrite -1}}
	rotr {
		val_r {Type I LastRead 1 FirstWrite -1}
		bits {Type I LastRead 0 FirstWrite -1}}
	rotr {
		val_r {Type I LastRead 1 FirstWrite -1}
		bits {Type I LastRead 0 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "183", "Max" : "183"}
	, {"Name" : "Interval", "Min" : "184", "Max" : "184"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
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
