/* 
 * Some video stuff
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>

int main(void) {

    AVFormatContext *avf_ctx = avformat_alloc_context();
    if(!avf_ctx) {
        exit(EXIT_FAILURE);
    }

    avformat_free_context(avf_ctx);
    return 0;
}


