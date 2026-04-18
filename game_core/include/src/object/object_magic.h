//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_OBJECT_MAGIC_H
#define pal_ohos_OBJECT_MAGIC_H
#include "enums/magic_flag.h"
#include "util/common.h"
// 法术
typedef struct ObjectMagicDOS {
    WORD number_;
    WORD reserved1_;
    WORD script_on_success_;
    WORD script_on_use_;
    WORD reserved2_;
    MAGICFLAG flags_;
} OBJECT_MAGIC_DOS;

typedef struct ObjectMagic {
    WORD number_;
    WORD reserved1_;
    WORD script_on_success_;
    WORD script_on_use_;
    WORD script_desc_;
    WORD reserved2_;
    MAGICFLAG flags_;
} OBJECT_MAGIC;

#endif // pal_ohos_OBJECT_MAGIC_H
