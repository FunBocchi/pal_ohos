//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_MAGIC_SPECIAL_H
#define pal_ohos_MAGIC_SPECIAL_H

#include "util/common.h"

// 特殊法术参数
typedef union MagicSpecial {
    WORD summon_effect_; // 召唤精灵
    SHORT layer_offset_; // 仅用于非召唤魔法
    // 实际图层位置：Pal_Y(pos)+y_offset+magic_layer_offset
} MAGIC_SPECIAL, *LPMAGIC_SPECIAL;

#endif //pal_ohos_MAGIC_SPECIAL_H
