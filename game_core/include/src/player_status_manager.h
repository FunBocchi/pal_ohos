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
    static bool setStatus(uint16_t player_role, uint16_t status_id, uint16_t num_round);
    static void removeStatus(uint16_t player_role, uint16_t status_id);
    static void clearAllStatus();
    static void addPoison(uint16_t player_role, uint16_t poison_id);
    static void curePoison(uint16_t player_role, uint16_t poison_id);
    bool isPoisoned(uint16_t player_role, uint16_t min_level) const;
};

#endif // pal_ohos_PLAYER_STATUS_MANAGER_H
