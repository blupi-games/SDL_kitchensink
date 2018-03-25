#include <stdlib.h>
#include <assert.h>

#include "kitchensink/kiterror.h"
#include "kitchensink/internal/subtitle/kitsubtitlepacket.h"
#include "kitchensink/internal/subtitle/renderers/kitsubrenderer.h"


Kit_SubtitleRenderer* Kit_CreateSubtitleRenderer() {
    // Allocate renderer and make sure allocation was a success
    Kit_SubtitleRenderer *ren = calloc(1, sizeof(Kit_SubtitleRenderer));
    if(ren == NULL) {
        Kit_SetError("Unable to allocate kit subtitle renderer");
        return NULL;
    }
    return ren;
}

Kit_SubtitlePacket* Kit_RunSubtitleRenderer(Kit_SubtitleRenderer *ren, void *src, double start_pts, double end_pts) {
    if(ren == NULL)
        return NULL;
    if(ren->ren_render != NULL)
        return ren->ren_render(ren, src, start_pts, end_pts);
    return NULL;
}

void Kit_CloseSubtitleRenderer(Kit_SubtitleRenderer *ren) {
    if(ren == NULL)
        return;
    if(ren->ren_close != NULL)
        ren->ren_close(ren);
    free(ren);
}
