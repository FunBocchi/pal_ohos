//
// Created on 2026/4/20.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef PAL_OHOS_BOX_H
#define PAL_OHOS_BOX_H

#include "../base/pal_pos.h"
#include "../temp/SDL_Surface.h"
#include <cstdint>
struct Box{
    PalPos pos_;
    uint16_t width_,height_;
    SDL_Surface *lp_saved_area_;
};

#endif //PAL_OHOS_BOX_H
