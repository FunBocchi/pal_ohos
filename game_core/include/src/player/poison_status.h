//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_POISON_STATUS_H
#define pal_ohos_POISON_STATUS_H

#include "stdint.h"
struct PoisonStatus {
    uint16_t poison_id;
    uint16_t poison_script;
};

#endif // pal_ohos_POISON_STATUS_H
