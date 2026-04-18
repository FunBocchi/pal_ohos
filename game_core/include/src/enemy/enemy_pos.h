//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_ENEMY_POS_H
#define pal_ohos_ENEMY_POS_H

#include "src/base/pal_pos.h"
#include "util/palcommon.h"

// 敌人位置坐标
typedef struct EnemyPos {
    PALPOS pos[MAX_ENEMIES_IN_TEAM][MAX_ENEMIES_IN_TEAM];
} ENEMYPOS, *LPENEMYPOS;

#endif // pal_ohos_ENEMY_POS_H
