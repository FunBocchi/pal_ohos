//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_LEVEL_UP_MAGIC_H
#define pal_ohos_LEVEL_UP_MAGIC_H

#include "util/common.h"
#include "util/palcommon.h"

// 升级时学会的法术
typedef struct LevelUpMagic {
    WORD level_; // 达到的等级
    WORD magic_; // 学会的法术
} LEVELUPMAGIC, *LPLEVELUPMAGIC;

typedef struct LevelUpMagic_All {
    LEVELUPMAGIC m[MAX_PLAYER_ROLES];
} LEVELUPMAGIC_ALL, *LPLEVELUPMAGIC_ALL;

#endif // pal_ohos_LEVEL_UP_MAGIC_H
