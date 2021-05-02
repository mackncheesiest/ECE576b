CC ?= /usr/bin/aarch64-linux-gnu-gcc

CFILES = $(wildcard *.c)
XFILES = $(CFILES:.c=)

CFLAGS = -static
LDFLAGS = -lm
LIBPATHS = -L/usr/aarch64-linux-gnu/lib

$(XFILES):
	$(CC) $(CFILES) $(CFLAGS) -o $@ $(LDFLAGS) $(LIBPATHS)

enc_acc:
	$(CC) aes.c drivers_aes.c -DENC -DUSE_ACCEL -o aes_enc_accel.out $(LDFLAGS) $(LIBPATHS)
enc_cpu:
	$(CC) aes.c drivers_aes.c -DENC -o aes_enc_cpu.out $(LDFLAGS) $(LIBPATHS)
dec_acc:
	$(CC) aes.c drivers_aes.c -DDEC -DUSE_ACCEL -o aes_dec_accel.out $(LDFLAGS) $(LIBPATHS)
dec_cpu:
	$(CC) aes.c drivers_aes.c -DDEC -o aes_dec_cpu.out $(LDFLAGS) $(LIBPATHS)
all_acc:
	$(CC) aes.c drivers_aes.c -DENC -DDEC -DUSE_ACCEL -o aes_enc_dec_accel.out $(LDFLAGS) $(LIBPATHS)
all_cpu:
	$(CC) aes.c drivers_aes.c -DENC -DDEC -o aes_enc_dec_cpu.out $(LDFLAGS) $(LIBPATHS)

.PHONY: clean
clean:
	rm -f *.out
