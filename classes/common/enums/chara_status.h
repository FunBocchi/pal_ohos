//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_ENUMS_CHARA_STATUS_H
#define pal_ohos_ENUMS_CHARA_STATUS_H

#include <cstddef>
// 角色状态
enum class CharaStatus {
    kConfused = 0, // 混乱状态（随机攻击友方）
// 判断游戏模式是否为经典模式
#ifdef PAL_CLASSIC
    kParalyzed, // 麻痹
#else
    kSlow, // 减速
#endif
    kSleep,      // 睡眠（无法行动）
    kSilence,    // 沉默（无法使用魔法）
    kPuppet,     // 仅死亡单位生效，继续攻击
    kBravery,    // 物攻++
    kProtect,    // 防守
    kHaste,      // 加速
    kDualAttack, // 连击
    kAll
};
// 由于使用了枚举类无法直接使用创建数组，故添加一层转换
constexpr inline size_t kCharaStatusCount = static_cast<size_t>(CharaStatus::kAll   );

#ifndef PAL_CLASSIC
#define kParalyzed CharaStatus::kSleep
#endif

#endif //pal_ohos_ENUMS_CHARA_STATUS_H
