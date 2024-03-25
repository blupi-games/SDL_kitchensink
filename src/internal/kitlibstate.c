#include <stddef.h>
#include "kitchensink/internal/kitlibstate.h"

#ifdef LIBASS
static Kit_LibraryState _librarystate = {0, 1, 0, 3, 64, 64, NULL, NULL};
#else // LIBASS
static Kit_LibraryState _librarystate = {0, 1, 0, 3, 64, 64};
#endif // !LIBASS

Kit_LibraryState* Kit_GetLibraryState() {
    return &_librarystate;
}
