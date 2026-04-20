//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_ENUMS_CHARA_STATUS_H
#define pal_ohos_ENUMS_CHARA_STATUS_H

#include "util/common.h"

// 角色状态
enum class CharaStatus : uint16_t {
    Confused = 0, // 混乱状态（随机攻击友方）
// 判断游戏模式是否为经典模式
#ifdef PAL_CLASSIC
    Paralyzed, // 麻痹
#else
    Slow, // 减速
#endif
    Sleep,      // 睡眠（无法行动）
    Silence,    // 沉默（无法使用魔法）
    Puppet,     // 仅死亡单位生效，继续攻击
    Bravery,    // 物攻++
    Protect,    // 防守
    Haste,      // 加速
    DualAttack, // 连击
    Default
};
// 由于使用了枚举类无法直接使用创建数组，故添加一层转换
constexpr inline size_t kCharaStatusCount = static_cast<size_t>(CharaStatus::Default);

#endif //pal_ohos_ENUMS_CHARA_STATUS_H
