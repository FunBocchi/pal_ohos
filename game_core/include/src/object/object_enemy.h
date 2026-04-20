//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_OBJECT_ENEMY_H
#define pal_ohos_OBJECT_ENEMY_H

#include "util/common.h"
#include <cstdint>

// 敌人
struct ObjectEnemy {
    uint16_t enemy_id_;
    uint16_t resistance_to_sorcery_;
    // 脚本
    uint16_t on_turn_start_;
    uint16_t on_battle_end_;
    uint16_t on_ready_;
};

#endif // pal_ohos_OBJECT_ENEMY_H
