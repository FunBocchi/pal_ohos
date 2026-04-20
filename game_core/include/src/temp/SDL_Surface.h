//
// Created on 2026/4/20.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef PAL_OHOS_SDL_SURFACE_H
#define PAL_OHOS_SDL_SURFACE_H

#include "src/temp/SDL_Palette.h"
#include "src/temp/SDL_Rect.h"
#include <cstdint>
struct SDL_Surface{
    void*pixels_;
    int32_t w_;
    int32_t h_;
    int32_t pitch_;
    int32_t type_color_;
    SDL_Palette*palette_;
    SDL_Rect rect_;
};

#endif //PAL_OHOS_SDL_SURFACE_H
