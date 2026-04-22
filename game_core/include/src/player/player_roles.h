//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_PLAYER_ROLES_H
#define pal_ohos_PLAYER_ROLES_H

#include "util/palcommon.h"
#include <array>
#include <cstdint>

/*
 * 角色各项属性的默认存储单元
 */
using Players = std::array<uint16_t, MAX_PLAYER_ROLES>;

struct PlayerRoles {
    Players avatar;                                                  // 立绘（显示在状态界面）
    Players sprite_num_in_battle;                                    // 战斗中显示的精灵图编号，来自F.MKF
    Players sprite_num;                                              // 普通场景中显示的精灵图编号，来自MGO.MKF
    Players name;                                                    // 角色名称，来自WORD.DAT
    Players attack_all;                                              // 是否可以群体攻击
    Players unknown1;                                                // 占位符
    Players level;                                                   // 等级
    Players max_hp;                                                  // 最大生命值
    Players max_mp;                                                  // 最大法力值
    Players hp;                                                      // 当前生命值
    Players mp;                                                      // 当前法力值
    uint16_t equipment[MAX_PLAYER_EQUIPMENTS][MAX_PLAYER_ROLES];          // 装备信息
    Players attack_strength;                                         // 物攻
    Players magic_strength;                                          // 法强
    Players defence;                                                 // 对各种攻击的综合防御力
    Players dexterity;                                               // 敏捷
    Players flee_rate;                                               // 逃跑成功率
    Players poison_resistance;                                       // 中毒抗性
    uint16_t elemental_resistance[NUM_MAGIC_ELEMENTAL][MAX_PLAYER_ROLES]; // 元素魔法抗性
    Players unknown2;                                                // 占位符
    Players unknown3;                                                // 占位符
    Players unknown4;                                                // 占位符
    Players covered_by;                                              // 当生命值过低或者处于异常状态时，谁来保护
    uint16_t magic[MAX_PLAYER_MAGICS][MAX_PLAYER_ROLES];                 // 可学习的法术
    Players walk_frames;                                             // 行动帧数？
    Players cooperative_magic;                                       // 合体法术
    Players unknown5;                                                // 占位符
    Players unknown6;                                                // 占位符
    Players death_sound;                                             // 死亡音效
    Players attack_sound;                                            // 普攻音效
    Players weapon_sound;                                            // 武器音效
    Players critical_sound;                                          // 暴击音效
    Players magic_sound;                                             // 魔攻音效
    Players cover_sound;                                             // 保护队友时音效
    Players dying_sound;                                             // 濒死音效
};

#endif // pal_ohos_PLAYER_ROLES_H
