CC = /usr/bin/aarch64-linux-gnu-gcc

CFILES = $(wildcard *.c)
XFILES = $(CFILES:.c=)

CFLAGS = -static
LDFLAGS = -lm
LIBPATHS = -L/usr/aarch64-linux-gnu/lib

$(XFILES):
	$(CC) $(CFILES) $(CFLAGS) -o $@ $(LDFLAGS) $(LIBPATHS)

enc:
	$(CC) aes.c drivers_aes.c -DENC -o aes_enc.out $(LDFLAGS) $(LIBPATHS)
dec:
	$(CC) aes.c drivers_aes.c -DDEC -o aes_dec.out $(LDFLAGS) $(LIBPATHS)
all:
	$(CC) aes.c drivers_aes.c -DENC -DDEC -o aes_enc_dec.out $(LDFLAGS) $(LIBPATHS)


.PHONY: clean
clean:
	rm -f *.out
