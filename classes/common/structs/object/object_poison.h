//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_OBJECT_POISON_H
#define pal_ohos_OBJECT_POISON_H

#include <cstdint>
// 毒药
struct ObjectPoison {
    uint16_t level;
    uint16_t color;
    uint16_t player_script;
    uint16_t reserved;
    uint16_t enemy_script;
};

#endif // pal_ohos_OBJECT_POISON_H
