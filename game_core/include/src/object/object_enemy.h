//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_OBJECT_ENEMY_H
#define pal_ohos_OBJECT_ENEMY_H

#include "util/common.h"

// 敌人
typedef struct ObjectEnemy {
    WORD enemy_id_;
    WORD resistance_to_sorcery_;
    // 脚本
    WORD on_turn_start_;
    WORD on_battle_end_;
    WORD on_ready_;
} OBJECT_ENEMY;

#endif // pal_ohos_OBJECT_ENEMY_H
