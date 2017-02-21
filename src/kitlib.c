#include "kitchensink/kitchensink.h"
#include "kitchensink/internal/kitlibstate.h"
#include <libavformat/avformat.h>
#ifdef LIBASS
#include <ass/ass.h>
#endif // LIBASS
#include <assert.h>

// No-op
void _libass_msg_callback(int level, const char *fmt, va_list va, void *data) {}

int Kit_Init(unsigned int flags) {
    Kit_LibraryState *state = Kit_GetLibraryState();

    if(state->init_flags != 0) {
        Kit_SetError("Kitchensink is already initialized.");
        return 1;
    }
    if(flags & KIT_INIT_NETWORK) {
        avformat_network_init();
    }
    if(flags & KIT_INIT_FORMATS) {
        av_register_all();
    }

    state->init_flags = flags;

#ifdef LIBASS
    // Init libass
    state->libass_handle = ass_library_init();

    // Make libass message spam go away
    ass_set_message_cb(state->libass_handle, _libass_msg_callback, NULL);
#endif // LIBASS
    
    return 0;
}

void Kit_Quit() {
    Kit_LibraryState *state = Kit_GetLibraryState();

    if(state->init_flags & KIT_INIT_NETWORK) {
        avformat_network_deinit();
    }
    state->init_flags = 0;

#ifdef LIBASS
    ass_library_done(state->libass_handle);
#endif // LIBASS
}

void Kit_GetVersion(Kit_Version *version) {
    assert(version != NULL);
    version->major = KIT_VERSION_MAJOR;
    version->minor = KIT_VERSION_MINOR;
    version->patch = KIT_VERSION_PATCH;
}
