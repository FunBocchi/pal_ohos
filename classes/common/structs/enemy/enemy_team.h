//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_ENEMY_TEAM_H
#define pal_ohos_ENEMY_TEAM_H

#include <cstdint>
#include "../../defs/palcommon.h"
struct EnemyTeam {
    uint16_t rgw_enemy_[MAX_ENEMIES_IN_TEAM];
};

#endif //pal_ohos_ENEMY_TEAM_H
