/* 
 * Some video stuff
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <linux/limits.h>

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>

#define PEXIT_FAILURE(MSG) do{fprintf(stderr, "%s\n", MSG); \
                              exit(EXIT_FAILURE);}while(0)


static void usage(char *pname) {
    fprintf(stderr, "%s -f [file]\n", pname);
}


int main(int argc, char **argv) {
    
    char fname[NAME_MAX];
    int opts;

    if(argc == 1) {
        fprintf(stderr, "no args given\n");
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    while((opts = getopt(argc, argv, "hf:")) != -1) {
        switch (opts) {
            case 'h':
                usage(argv[0]);
                exit(EXIT_SUCCESS);
            case 'f':
                strncpy(fname, optarg, sizeof(fname));
                break;
            default:
                usage(argv[0]);
                exit(EXIT_FAILURE);
        }
    }


    AVFormatContext *avf_ctx = avformat_alloc_context();
    if(!avf_ctx) {
        exit(EXIT_FAILURE);
    }
    
    if(avformat_open_input(&avf_ctx, fname, NULL, NULL) != 0) {
        exit(EXIT_FAILURE);
    }
    
    /* http://ffmpeg.org/doxygen/trunk/group__lavf__decoding.html#gad42172e27cddafb81096939783b157bb */
    if(avformat_find_stream_info(avf_ctx, NULL) < 0) {
        exit(EXIT_FAILURE);
    }

    AVCodec *codec;
    for (int i = 0; i< avf_ctx->nb_streams; i++) {
        AVCodecParameters *codec_params = avf_ctx->streams[i]->codecpar;
        printf("AVStream->time_base before open codec %d/%d\n", avf_ctx->streams[i]->time_base.num, avf_ctx->streams[i]->time_base.den);
        printf("AVStream->r_frame_rate before open codec %d/%d\n", avf_ctx->streams[i]->r_frame_rate.num, avf_ctx->streams[i]->r_frame_rate.den);
        printf("AVStream->start_time %" PRId64 "\n", avf_ctx->streams[i]->start_time);
        printf("AVStream->duration %" PRId64 "\n", avf_ctx->streams[i]->duration);
    }

    avformat_close_input(&avf_ctx);
    avformat_free_context(avf_ctx);
    exit(EXIT_SUCCESS);
}

