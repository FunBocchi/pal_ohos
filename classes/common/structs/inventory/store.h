//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_STORE_H
#define pal_ohos_STORE_H


#include <cstdint>
#include "../../defs/palcommon.h"
struct Store {
    uint16_t rgw_items_[MAX_STORE_ITEM];
};

#endif // pal_ohos_STORE_H
