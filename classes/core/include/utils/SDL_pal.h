//
// Created on 2026/4/23.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef PAL_OHOS_SDL_PAL_H
#define PAL_OHOS_SDL_PAL_H

#include <cstdint>
class SDLPal{
public:
    static uint32_t GetTicks();
};

#endif //PAL_OHOS_SDL_PAL_H
