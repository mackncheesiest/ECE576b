SYSTEMC ?= ../../systemc-2.3.3

all:
	g++ -I ${SYSTEMC}/include sad1.cpp ${SYSTEMC}/lib-linux64/libsystemc.a -lpthread -o sad_part1.out

clean:
	-rm ./hello_systemc.out 2>/dev/null
