CC = gcc
CFLAGS = -Wall -g -I../FFmpeg
LD = gcc 
FFMPEGLIBS = -lavformat -lavcodec -lavutil -lswresample 
FFMPEGLIBS += -lz -lva -lpthread -lm -lz -lX11  -lva-drm  -lva-x11 
FFMPEGLIBS += -lfdk-aac -lmp3lame -lvdpau #-libvorbis -loupus -lopusfile
FFMPEGLIBS += -lx264 #-lvpx-vp9 -lvpx -lx265
LDFLAGS = -L../ffmpeg_build/lib/ 

LDFLAGS += $(FFMPEGLIBS)


%.o: %.c
	$(CC) $< $(CFLAGS) -c -o $@

main: main.o
	$(LD) $^ $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -rf *.o main

