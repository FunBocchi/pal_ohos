//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_MAGIC_TYPE_H
#define pal_ohos_MAGIC_TYPE_H

#include "util/common.h"

// 法术类型
typedef enum class MagicType : WORD {
    Normal = 0,        // 普通单体
    AttackAll = 1,     // 依次攻击
    AttackWhole = 2,   // 群体攻击
    AttackField = 3,   // 全屏攻击
    ApplyToPlayer = 4, // 单体治疗
    ApplyToParty = 5,  // 群体治疗
    Trance = 8,        // 觉醒（特殊状态）
    Summon = 9         // 召唤术
} MAGIC_TYPE;

#endif // pal_ohos_MAGIC_TYPE_H
