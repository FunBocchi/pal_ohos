//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_OBJECT_MAGIC_H
#define pal_ohos_OBJECT_MAGIC_H
#include "../../enums/magic_flag.h"
#include "util/common.h"
#include <cstdint>
// 法术
struct ObjectMagicDOS {
    uint16_t number_;
    uint16_t reserved1_;
    uint16_t script_on_success_;
    uint16_t script_on_use_;
    uint16_t reserved2_;
    MagicFlag flags_;
};

struct ObjectMagic {
    uint16_t number_;
    uint16_t reserved1_;
    uint16_t script_on_success_;
    uint16_t script_on_use_;
    uint16_t script_desc_;
    uint16_t reserved2_;
    MagicFlag flags_;
};

#endif // pal_ohos_OBJECT_MAGIC_H
