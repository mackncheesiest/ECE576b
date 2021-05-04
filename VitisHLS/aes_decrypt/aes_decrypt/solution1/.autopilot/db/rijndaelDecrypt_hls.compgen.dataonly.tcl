# This script segment is generated automatically by AutoPilot

set axilite_register_dict [dict create]
set port_BUS {
ct { 
	dir I
	width 8
	depth 16
	mode ap_memory
	offset 16
	offset_end 31
}
pt { 
	dir O
	width 8
	depth 16
	mode ap_memory
	offset 32
	offset_end 47
}
rk { 
	dir I
	width 32
	depth 44
	mode ap_memory
	offset 256
	offset_end 511
}
ap_start { }
ap_done { }
ap_ready { }
ap_idle { }
}
dict set axilite_register_dict BUS $port_BUS


