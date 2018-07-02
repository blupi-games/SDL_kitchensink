#ifndef KITLIBSTATE_H
#define KITLIBSTATE_H

#ifdef LIBASS
#include "kitchensink/internal/libass.h"
#endif // LIBASS
#include "kitchensink/kitconfig.h"

typedef struct Kit_LibraryState {
    unsigned int init_flags;
    unsigned int thread_count;
    unsigned int font_hinting;
    unsigned int video_buf_frames;
    unsigned int audio_buf_frames;
    unsigned int subtitle_buf_frames;
#ifdef LIBASS
    ASS_Library *libass_handle;
    void *ass_so_handle;
#endif // LIBASS
} Kit_LibraryState;

KIT_LOCAL Kit_LibraryState* Kit_GetLibraryState();

#endif // KITLIBSTATE_H
