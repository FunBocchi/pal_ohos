//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_MAGIC_SPECIAL_H
#define pal_ohos_MAGIC_SPECIAL_H

#include <cstdint>
// 特殊法术参数
union MagicSpecial {
    uint16_t summon_effect_; // 召唤精灵
    int16_t layer_offset_; // 仅用于非召唤魔法
    // 实际图层位置：Pal_Y(pos)+y_offset+magic_layer_offset
};

#endif //pal_ohos_MAGIC_SPECIAL_H
