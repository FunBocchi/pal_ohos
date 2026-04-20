//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_PLAYER_ROLES_H
#define pal_ohos_PLAYER_ROLES_H

#include "util/common.h"
#include "util/palcommon.h"
#include <array>

// 对源代码进行了修改，使用array实现相同功能，暂时不知道会不会对二进制源码的读取产生影响
using Players = std::array<WORD, MAX_PLAYER_ROLES>;

struct PlayerRoles {
    Players avatar_;                                                  // 立绘（显示在状态界面）
    Players sprite_num_in_battle_;                                    // 战斗中显示的精灵图编号，来自F.MKF
    Players sprite_num_;                                              // 普通场景中显示的精灵图编号，来自MGO.MKF
    Players name_;                                                    // 角色名称，来自WORD.DAT
    Players attack_all_;                                              // 是否可以群体攻击
    Players unknown1_;                                                // 占位符
    Players level_;                                                   // 等级
    Players max_hp_;                                                  // 最大生命值
    Players max_mp_;                                                  // 最大法力值
    Players hp_;                                                      // 当前生命值
    Players mp_;                                                      // 当前法力值
    WORD equipment[MAX_PLAYER_EQUIPMENTS][MAX_PLAYER_ROLES];          // 装备信息
    Players attack_strength_;                                         // 物攻
    Players magic_strength_;                                          // 法强
    Players defence_;                                                 // 对各种攻击的综合防御力
    Players dexterity_;                                               // 敏捷
    Players flee_rate_;                                               // 逃跑成功率
    Players poison_resistance_;                                       // 中毒抗性
    WORD elemental_resistance[NUM_MAGIC_ELEMENTAL][MAX_PLAYER_ROLES]; // 元素魔法抗性
    Players unknown2_;                                                // 占位符
    Players unknown3_;                                                // 占位符
    Players unknown4_;                                                // 占位符
    Players covered_by_;                                              // 当生命值过低或者处于异常状态时，谁来保护
    WORD magic_[MAX_PLAYER_MAGICS][MAX_PLAYER_ROLES];                 // 可学习的法术
    Players walk_frames_;                                             // 行动帧数？
    Players cooperative_magic_;                                       // 合体法术
    Players unknown5_;                                                // 占位符
    Players unknown6_;                                                // 占位符
    Players death_sound_;                                             // 死亡音效
    Players attack_sound_;                                            // 普攻音效
    Players weapon_sound_;                                            // 武器音效
    Players critical_sound_;                                          // 暴击音效
    Players magic_sound_;                                             // 魔攻音效
    Players cover_sound_;                                             // 保护队友时音效
    Players dying_sound_;                                             // 濒死音效
};

#endif // pal_ohos_PLAYER_ROLES_H
