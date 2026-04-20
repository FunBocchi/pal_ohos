//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_ENEMY_H
#define pal_ohos_ENEMY_H

#include "util/common.h"
#include "util/palcommon.h"
#include <cstdint>

struct Enemy {
    // 动画帧数
    uint16_t idle_frames_;     // 待机
    uint16_t magic_frames_;    // 魔法攻击
    uint16_t attack_frames_;   // 普通攻击
    uint16_t idle_anim_speed_; // 闲置动画播放速度
    uint16_t act_wait_frames_; // 动作等待帧数？
    uint16_t y_pos_offset_;    // Y轴位置偏移量
    // 音效
    int16_t attack_sound_; // 普通攻击
    int16_t action_sound_; // 动作？
    int16_t magic_sound_;  // 施法
    int16_t death_sound_;  // 死亡
    int16_t call_sound_;   // 登场
    // 属性 及 特性
    uint16_t health_;                              // 血量
    uint16_t exp_;                                 // 经验值（击败获得）
    uint16_t cash_;                                // 金钱（击败获得）
    uint16_t level_;                               // 等级
    uint16_t magic_;                               // 可使用魔法编号
    uint16_t magic_rate_;                          // 施法概率
    uint16_t attack_equiv_item_;                   // 普攻等效道具编号
    uint16_t attack_equiv_item_rate_;              // 等效道具触发概率
    uint16_t steal_item_which_;                    // 偷取该敌人可获得道具编号
    uint16_t steal_item_total_;                    // 可偷取道具总数
    uint16_t attack_strength_;                     // 物攻
    uint16_t magic_strength;                       // 法强
    uint16_t defence_;                             // 防御力（综合）
    uint16_t dexterity_;                           // 敏捷
    uint16_t flee_rate_;                           // 逃跑成功率
    uint16_t poison_resistance_;                   // 中毒抗性
    uint16_t elem_resistance[NUM_MAGIC_ELEMENTAL]; // 元素魔法抗性
    uint16_t physical_resistance_;                 // 物理攻击抗性
    uint16_t dual_move_;                           // 是否能进行双重行动
    uint16_t collect_value_;                       // 收集该敌人获取物品的价值
};

#endif // pal_ohos_ENEMY_H
