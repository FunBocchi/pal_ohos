//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_ENEMY_H
#define pal_ohos_ENEMY_H

#include "util/common.h"
#include "util/palcommon.h"

typedef struct Enemy {
    // 动画帧数
    WORD idle_frames_;     // 待机
    WORD magic_frames_;    // 魔法攻击
    WORD attack_frames_;   // 普通攻击
    WORD idle_anim_speed_; // 闲置动画播放速度
    WORD act_wait_frames_; // 动作等待帧数？
    WORD y_pos_offset_;    // Y轴位置偏移量
    // 音效
    SHORT attack_sound_; // 普通攻击
    SHORT action_sound_; // 动作？
    SHORT magic_sound_;  // 施法
    SHORT death_sound_;  // 死亡
    SHORT call_sound_;   // 登场
    // 属性 及 特性
    WORD health_;                              // 血量
    WORD exp_;                                 // 经验值（击败获得）
    WORD cash_;                                // 金钱（击败获得）
    WORD level_;                               // 等级
    WORD magic_;                               // 可使用魔法编号
    WORD magic_rate_;                          // 施法概率
    WORD attack_equiv_item_;                   // 普攻等效道具编号
    WORD attack_equiv_item_rate_;              // 等效道具触发概率
    WORD steal_item_which_;                    // 偷取该敌人可获得道具编号
    WORD steal_item_total_;                    // 可偷取道具总数
    WORD attack_strength_;                     // 物攻
    WORD magic_strength;                       // 法强
    WORD defence_;                             // 防御力（综合）
    WORD dexterity_;                           // 敏捷
    WORD flee_rate_;                           // 逃跑成功率
    WORD poison_resistance_;                   // 中毒抗性
    WORD elem_resistance[NUM_MAGIC_ELEMENTAL]; // 元素魔法抗性
    WORD physical_resistance_;                 // 物理攻击抗性
    WORD dual_move_;                           // 是否能进行双重行动
    WORD collect_value_;                       // 收集该敌人获取物品的价值
} ENEMY, *LPENEMY;

#endif // pal_ohos_ENEMY_H
