//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_INVENTORY_H
#define pal_ohos_INVENTORY_H

#include <cstdint>
// 库存
struct Inventory {
    uint16_t item;
    uint16_t amount;
    uint16_t amount_in_use;
};

#endif // pal_ohos_INVENTORY_H
