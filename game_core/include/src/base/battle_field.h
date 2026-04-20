//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_BATTLE_FIELD_H
#define pal_ohos_BATTLE_FIELD_H

#include "util/common.h"
#include "util/palcommon.h"
#include <cstdint>

struct BattleField {
    uint16_t screen_wave_;                        // 屏幕波动等级
    int16_t magic_effect_[NUM_MAGIC_ELEMENTAL]; // 元素魔法的特效状态
};

#endif // pal_ohos_BATTLE_FIELD_H
