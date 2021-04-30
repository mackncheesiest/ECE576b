CC = /usr/bin/aarch64-linux-gnu-gcc

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
