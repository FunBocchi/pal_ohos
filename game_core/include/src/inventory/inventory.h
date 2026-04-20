//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_INVENTORY_H
#define pal_ohos_INVENTORY_H

#include "util/common.h"
#include <cstdint>

// 库存
struct Inventory {
    uint16_t item_;
    uint16_t amount_;
    uint16_t amount_in_use_;
};

#endif // pal_ohos_INVENTORY_H
