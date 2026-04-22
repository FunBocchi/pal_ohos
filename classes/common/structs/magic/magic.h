//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_MAGIC_H
#define pal_ohos_MAGIC_H

#include "magic_special.h"
#include <cstdint>
struct Magic {
    // 视觉效果相关
    uint16_t effect_;            // 效果精灵编号
    uint16_t type_;              // 法术类型（对应MagicType）
    uint16_t x_offset_;          // 效果的X轴偏移量
    uint16_t y_offset_;          // 效果的Y轴偏移量
    MagicSpecial specific_; // 特殊参数（根据魔法类型决定）
    int16_t speed_;            // 动画播放速度
    uint16_t keep_effect_;       // 保持效果？
    uint16_t fire_delay_;        // 法术发射阶段的起始帧数
    uint16_t effect_times_;      // 效果播放总次数
    // 屏幕特效相关
    uint16_t shake_; // 屏幕震动强度
    uint16_t wave_;  // 屏幕波动强度

    uint16_t unknown_;
    // 战斗数值相关
    uint16_t cost_mp_;     // 法力值消耗
    uint16_t base_damage_; // 基础伤害
    uint16_t elemental_;   // 元素属性（0->无属性，end->毒属性）
    int16_t sound_;      // 施法时播放的音效
};

#endif //pal_ohos_MAGIC_H
