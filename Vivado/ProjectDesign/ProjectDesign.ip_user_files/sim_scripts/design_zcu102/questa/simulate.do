onbreak {quit -f}
onerror {quit -f}

vsim -lib xil_defaultlib design_zcu102_opt

do {wave.do}

view wave
view structure
view signals

do {design_zcu102.udo}

run -all

quit -force
