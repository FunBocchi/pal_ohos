//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_PLAYER_PROGRESSION_MANAGER_H
#define pal_ohos_PLAYER_PROGRESSION_MANAGER_H

#include "util/common.h"

// 角色成长相关方法
class PlayerProgressionManager {
public:
    static bool increaseHPMP(uint16_t player_role, int16_t hp, int16_t mp); // 升级血量和魔力
    static bool addMagic(uint16_t player_role, uint16_t magic);
    static void removeMagic(uint16_t player_role, uint16_t magic);
    static void levelUp(uint16_t player_role, uint16_t num_level);
};

#endif // pal_ohos_PLAYER_PROGRESSION_MANAGER_H
