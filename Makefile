CC = gcc
CFLAGS = -Wall -g -I../FFmpeg
LD = gcc 
FFMPEGLIBS = -lavformat -lavcodec -lavutil -lswresample 
FFMPEGLIBS += -lz -lva -lpthread -lm -lz -lX11  -lva-drm  -lva-x11 
FFMPEGLIBS += -lvorbis -lfdk-aac -lmp3lame -lvdpau 
FFMEPGLIBS += -lx264 #-lx265
LDFLAGS = -L../ffmpeg_build/lib/ 

LDFLAGS += $(FFMPEGLIBS)


%.o: %.c
	$(CC) $< $(CFLAGS) -c -o $@

main: main.o
	$(LD) $^ $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -rf *.o main

