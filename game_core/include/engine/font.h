//
// Created on 2026/4/16.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_FONT_H
#define pal_ohos_FONT_H

#include "util/common.h"
#include "util/palcfg.h"
#include "util/palcommon.h"

PAL_C_LINKAGE_BEGIN

extern char *font_offset_x;
extern char *font_offset_y;

/*++
  Purpose:

    Initialize the font subsystem.

  Parameters:

    [IN]  cfg - Pointer to the configuration object.

  Return value:

    0 = success, -1 = failure.
--*/
int PAL_InitFont(const CONFIGURATION *cfg);

void PAL_FreeFont(void);

/*++
  Purpose:

    Draw a Unicode character on a surface.

  Parameters:

    [IN]  wChar - the unicode character to be drawn.

    [OUT] lpSurface - the destination surface.

    [IN]  pos - the destination location of the surface.

    [IN]  bColor - the color of the character.

  Return value:

    None.

--*/
void PAL_DrawCharOnSurface(uint16_t wChar, SDL_Surface *lpSurface, PAL_POS pos, uint8_t bColor, BOOL fUse8x8Font);

/*++
  Purpose:

    Get the text width of a character.

  Parameters:

    [IN]  wChar - the unicode character for width calculation.

  Return value:

    The width of the character in pixels, 16 for full-width char and 8 for half-width char.

--*/
int PAL_CharWidth(uint16_t wChar);

/*++
  Purpose:

    Get the height of the currently used font.

  Parameters:

    None.

  Return value:

    The height of the font in pixels.

--*/
int PAL_FontHeight(void);

PAL_C_LINKAGE_END

#endif // pal_ohos_FONT_H
