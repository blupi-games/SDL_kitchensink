#include "kitchensink/internal/kitlibstate.h"

#ifdef LIBASS
static Kit_LibraryState _librarystate = {0, NULL};
#else // LIBASS
static Kit_LibraryState _librarystate = {0};
#endif // !LIBASS

Kit_LibraryState* Kit_GetLibraryState() {
    return &_librarystate;
}
