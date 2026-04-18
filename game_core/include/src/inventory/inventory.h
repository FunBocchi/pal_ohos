//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_INVENTORY_H
#define pal_ohos_INVENTORY_H

#include "util/common.h"

// 库存
typedef struct Inventory {
    WORD item_;
    USHORT amount_;
    USHORT amount_in_use_;
} INVENTORY, *LPINVENTORY;

#endif // pal_ohos_INVENTORY_H
