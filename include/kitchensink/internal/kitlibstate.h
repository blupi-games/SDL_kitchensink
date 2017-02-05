#ifndef KITLIBSTATE_H
#define KITLIBSTATE_H

#ifdef LIBASS
#include <ass/ass.h>
#endif // LIBASS
#include "kitchensink/kitconfig.h"

typedef struct Kit_LibraryState {
    unsigned int init_flags;
#ifdef LIBASS
    ASS_Library *libass_handle;
#endif // LIBASS
} Kit_LibraryState;

KIT_LOCAL Kit_LibraryState* Kit_GetLibraryState();

#endif // KITLIBSTATE_H
