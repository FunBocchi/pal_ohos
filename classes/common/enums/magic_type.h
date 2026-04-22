//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_MAGIC_TYPE_H
#define pal_ohos_MAGIC_TYPE_H

// 法术类型
enum class MagicType {
    kNormal = 0,        // 普通单体
    kAttackAll = 1,     // 依次攻击
    kAttackWhole = 2,   // 群体攻击
    kAttackField = 3,   // 全屏攻击
    kApplyToPlayer = 4, // 单体治疗
    kApplyToParty = 5,  // 群体治疗
    kTrance = 8,        // 觉醒（特殊状态）
    kSummon = 9         // 召唤术
};

#endif // pal_ohos_MAGIC_TYPE_H
