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
    kUsable = (1 << 0),
    kEquipable = (1 << 1),
    kThrowable = (1 << 2),
    kConsuming = (1 << 3),
    kApplyToAll = (1 << 4),
    kSellable = (1 << 5),
    kEquipableByPlayerRole_First = (1 << 6)
};

#endif // pal_ohos_ITEM_FLAG_H
