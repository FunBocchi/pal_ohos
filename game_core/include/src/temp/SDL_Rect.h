//
// Created on 2026/4/20.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef PAL_OHOS_SDL_RECT_H
#define PAL_OHOS_SDL_RECT_H

#include <cstdint>
struct SDL_Rect{
    int32_t x,y,w,h;
};

#endif //PAL_OHOS_SDL_RECT_H
