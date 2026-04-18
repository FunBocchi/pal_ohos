//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_EQUIPMENT_MANAGER_H
#define pal_ohos_EQUIPMENT_MANAGER_H

#include "util/common.h"
// 可能用到body_part.h

class EquipmentManager {
public:
    void updateAllEquipments();
    void removeEquipmentEffect(uint16_t player_role, uint16_t equip_part);
};

#endif // pal_ohos_EQUIPMENT_MANAGER_H
