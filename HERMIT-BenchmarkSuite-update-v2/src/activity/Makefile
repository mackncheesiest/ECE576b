#CC = gcc
CC = /media/jmack2545/data_drive/Xilinx/Vitis/2020.2/gnu/aarch64/lin/aarch64-linux/bin/aarch64-linux-gnu-gcc

CFILES = $(wildcard *.c)
XFILES = $(CFILES:.c=)

CFLAGS = -static
LDFLAGS = -lm
LIBPATHS = -L/usr/aarch64-linux-gnu/lib

$(XFILES):
	$(CC) $(CFILES) $(CFLAGS) -o $@ $(LDFLAGS) $(LIBPATHS)

all: $(XFILES)

.PHONY: clean
clean:
	rm -f $(XFILES) *.txt
