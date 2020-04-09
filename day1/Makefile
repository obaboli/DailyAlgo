CC = gcc
CFLAGS = -g
OUTPUT_DIR = ../target/

objects = memcpy
all: $(objects)


$(objects): %: %.c
	$(CC) $(CFLAGS) $< -o $(OUTPUT_DIR)$@

