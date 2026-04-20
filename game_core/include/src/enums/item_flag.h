//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_ITEM_FLAG_H
#define pal_ohos_ITEM_FLAG_H

#include "util/common.h"
#include <cstdint>
enum class ItemFlag : uint16_t {
    Usable = (1 << 0),
    Equipable = (1 << 1),
    Throwable = (1 << 2),
    Consuming = (1 << 3),
    ApplyToAll = (1 << 4),
    Sellable = (1 << 5),
    EquipableByPlayerRole_First = (1 << 6)
};

#endif // pal_ohos_ITEM_FLAG_H
