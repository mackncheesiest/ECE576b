# This script segment is generated automatically by AutoPilot

set axilite_register_dict [dict create]
set port_BUS_A {
vals_i { 
	dir I
	width 512
	depth 1
	mode ap_none
	offset 64
	offset_end 131
}
vals_o { 
	dir O
	width 512
	depth 1
	mode ap_vld
	offset 132
	offset_end 199
}
hr { 
	dir I
	width 64
	depth 600
	mode ap_memory
	offset 8192
	offset_end 16383
}
ap_start { }
ap_done { }
ap_ready { }
ap_idle { }
}
dict set axilite_register_dict BUS_A $port_BUS_A


