
CC = gcc

CFILES = $(wildcard *.c)
XFILES = $(CFILES:.c=)

CFLAGS = -static
LDFLAGS = -lm
PROFFLAGS = -g

$(XFILES):
	$(CC) $(CFILES) $(CFLAGS) $(PROFFLAGS) -o $@ $(LDFLAGS)

all: $(XFILES)

.PHONY: clean
clean:
	rm -f $(XFILES) *.txt
