//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_LEVEL_UP_MAGIC_H
#define pal_ohos_LEVEL_UP_MAGIC_H

#include "util/common.h"
#include "util/palcommon.h"
#include <cstdint>

// 升级时学会的法术
struct LevelUpMagic {
    uint16_t level_; // 达到的等级
    uint16_t magic_; // 学会的法术
};

struct LevelUpMagic_All {
    LevelUpMagic m[MAX_PLAYER_ROLES];
};

#endif // pal_ohos_LEVEL_UP_MAGIC_H
