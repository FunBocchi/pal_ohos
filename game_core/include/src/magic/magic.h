//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_MAGIC_H
#define pal_ohos_MAGIC_H

#include "util/common.h"
#include "structures/magic_special.h"

typedef struct Magic {
    // 视觉效果相关
    WORD effect_;            // 效果精灵编号
    WORD type_;              // 法术类型（对应MagicType）
    WORD x_offset_;          // 效果的X轴偏移量
    WORD y_offset_;          // 效果的Y轴偏移量
    MAGIC_SPECIAL specific_; // 特殊参数（根据魔法类型决定）
    SHORT speed_;            // 动画播放速度
    WORD keep_effect_;       // 保持效果？
    WORD fire_delay_;        // 法术发射阶段的起始帧数
    WORD effect_times_;      // 效果播放总次数
    // 屏幕特效相关
    WORD shake_; // 屏幕震动强度
    WORD wave_;  // 屏幕波动强度

    WORD unknown_;
    // 战斗数值相关
    WORD cost_mp_;     // 法力值消耗
    WORD base_damage_; // 基础伤害
    WORD elemental_;   // 元素属性（0->无属性，end->毒属性）
    SHORT sound_;      // 施法时播放的音效
} MAGIC, *LPMAGIC;

#endif //pal_ohos_MAGIC_H
