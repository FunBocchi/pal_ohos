//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_PLAYER_STATUS_MANAGER_H
#define pal_ohos_PLAYER_STATUS_MANAGER_H

// 状态管理及中毒管理

#include "util/common.h"

class PlayerStatusManager {
public:
    //状态相关
    static bool setStatus(uint16_t player_role, uint16_t status_id, uint16_t num_round);//对角色添加状态
    static void removeStatus(uint16_t player_role, uint16_t status_id);
    static void clearAllPlayerStatus();
    // 毒药相关
    static void addPoisonForPlayer(uint16_t player_role, uint16_t poison_id);
    static void curePoisonByKind(uint16_t player_role, uint16_t poison_id);
    static void curePoisonByLevel(uint16_t player_role, uint16_t max_level);
    
    static bool isPlayerPoisonedByKind(uint16_t player_role,uint16_t poison_id);
    static bool isPlayerPoisonedByLevel(uint16_t player_role,uint16_t min_level);
};

#endif // pal_ohos_PLAYER_STATUS_MANAGER_H
