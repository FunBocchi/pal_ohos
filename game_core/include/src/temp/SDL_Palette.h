//
// Created on 2026/4/20.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef PAL_OHOS_SDL_PALETTE_H
#define PAL_OHOS_SDL_PALETTE_H

#include "src/temp/SDL_Color.h"
#include <cstdint>
struct SDL_Palette{
    int32_t n_color_;
    SDL_Color *colors;
};

#endif //PAL_OHOS_SDL_PALETTE_H
