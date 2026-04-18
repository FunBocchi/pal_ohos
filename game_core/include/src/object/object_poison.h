//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_OBJECT_POISON_H
#define pal_ohos_OBJECT_POISON_H

#include "util/common.h"

// 毒药
typedef struct ObjectPoison {
    WORD level_;
    WORD color_;
    WORD player_script_;
    WORD reserved_;
    WORD enemy_script_;
} OBJECT_POISON;

#endif // pal_ohos_OBJECT_POISON_H
