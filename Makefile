CC = gcc
CFLAGS = -Wall -g -I../FFmpeg
LD = gcc 
LDFLAGS = -L/..FFmpeg/libavformat  -L/..FFmpeg/libavcodec


%.o: %.c
	$(CC) $< $(CFLAGS) -c -o $@

main: main.o
	$(LD) $^ $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -rf *.o main

