//
// Created on 2026/4/20.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef PAL_OHOS_SDL_COLOR_H
#define PAL_OHOS_SDL_COLOR_H

#include <cstdint>
struct SDL_Color{
    uint8_t r,g,b;
};

#endif //PAL_OHOS_SDL_COLOR_H
