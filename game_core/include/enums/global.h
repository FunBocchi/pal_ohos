/** -*- mode: c; tab-width: 4; c-basic-offset: 4; c-file-style: "linux" -*-
 *
 * Copyright (c) 2009-2011, Wei Mingzhi <whistler_wmz@users.sf.net>.
 * Copyright (c) 2011-2024, SDLPAL development team.
 * All rights reserved.
 *
 * C++ port and optimizations Copyright (c) 2025-2026, FunBocchi <lzx13735999188@petalmail.com>
 *
 *
 * This file is part of SDLPAL.
 *
 * SDLPAL is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 3
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef pal_ohos_GLOBAL_H
#define pal_ohos_GLOBAL_H

#include "util/common.h"
#include "util/palcommon.h"
#include <array>

// 角色状态
enum class CharaStatus : uint8_t {
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

// 可装备身体部位
enum class BodyPart : uint8_t {
    Head = 0, // 头
    Body,
    Shoulder,
    Hand,
    Feet,
    Wear,
    Extra
};

// 事件对象的状态及触发模式，由EventObject调用
enum class ObjectState : SHORT {
    Hidden = 0, // 隐藏
    Normal = 1,
    Blocker = 2
};
enum class TriggerMode : WORD {
    None = 0,
    SearchNear,
    SearchNormal,
    SearchFar,
    TouchNear,
    TouchNormal,
    TouchFar,
    TouchFurther,
    TouchFurthest
};

// 事件对象，地图上的交互元素
// 后续优化考虑对源文件读取及生成类型进行单独划分
struct EventObjectRaw {
    SHORT vanish_time_;
    WORD x_;
    WORD y_;
    SHORT layer_;
    WORD trigger_script_;
    WORD auto_script_;
    SHORT state_;       // 当前元素所处状态，对应SHORT类型
    WORD trigger_mode_; // 触发方式，对应WORD类型
    WORD sprite_num_;
    USHORT sprite_frames_;
    WORD direction_;
    WORD current_frame_num_;
    USHORT script_idle_frame_;
    WORD sprite_ptr_offset_;
    USHORT sprite_frames_auto_;
    WORD script_idle_frame_count_auto_;
};
// 使用上述结构体读取二进制文件代码后转换到下方可被使用的类型
struct EventObject {
    SHORT vanish_time_;
    WORD x_;
    WORD y_;
    SHORT layer_;
    WORD trigger_script_;
    WORD auto_script_;
    SHORT state_;       // 当前元素所处状态，对应SHORT类型
    WORD trigger_mode_; // 触发方式，对应WORD类型
    WORD sprite_num_;
    USHORT sprite_frames_;
    WORD direction_;
    WORD current_frame_num_;
    USHORT script_idle_frame_;
    WORD sprite_ptr_offset_;
    USHORT sprite_frames_auto_;
    WORD script_idle_frame_count_auto_;
};

// 场景
struct Scene {
    WORD map_num_;            // 地图序号
    WORD script_on_enter_;    // 进入当前地图时触发的脚本
    WORD script_on_teleport_; // 从当前地图传送出去的时候触发的脚本
    WORD event_object_index_; // 当前场景涉及的物品，对应索引+1
};

// 对象包括系统字符串、玩家、物品、魔法、敌人和毒药脚本

// 系统字符串及玩家角色
struct ObjectPlayer {
    WORD reserved[2];
    // 进入死亡状态时会触发的脚本，后续考虑修改为函数执政
    WORD script_on_friend_death_;
    WORD script_on_dying_;
};
typedef ObjectPlayer OBJECT_PLAYER;

enum class ItemFlag {
    Usable = (1 << 0),
    Equipable = (1 << 1),
    Throwable = (1 << 2),
    Consuming = (1 << 3),
    ApplyToAll = (1 << 4),
    Sellable = (1 << 5),
    EquipableByPlayerRole_First = (1 << 6),
    Resurved = (1 << 7)
};

// 物品（原版）
struct ObjectItemDos {
    WORD bitmap_; // 在BALL.MKF中对应的bitmap序号
    WORD price_;
    WORD script_on_use_;   // 使用时触发的脚本
    WORD script_on_equip_; // 装备时触发的脚本
    WORD script_on_throw_; // 丢弃时触发的脚本
    WORD flags_;
};
typedef ObjectItemDos OBJECT_ITEM_DOS;

// 物品（增强）
struct ObjectItem {
    WORD bitmap_; // 在BALL.MKF中对应的bitmap序号
    WORD price_;
    WORD script_on_use_;   // 使用时触发的脚本
    WORD script_on_equip_; // 装备时触发的脚本
    WORD script_on_throw_; // 丢弃时触发的脚本
    WORD script_desc_;
    WORD flags_;
};
typedef ObjectItem OBJECT_ITEM;

enum class MagicFlag {
    UsableOutSideBattle = (1 << 0),
    UsableInBattle = (1 << 1),
    UsableToEnemy = (1 << 3),
    ApplyToAll = (1 << 4)
};

// 法术
struct ObjectMagicDOS {
    WORD number_;
    WORD reserved1_;
    WORD script_on_success_;
    WORD script_on_use_;
    WORD reserved2_;
    WORD flags_;
};
typedef ObjectMagicDOS OBJECT_MAGIC_DOS;
struct ObjectMagic {
    WORD number_;
    WORD reserved1_;
    WORD script_on_success_;
    WORD script_on_use_;
    WORD reserved2_;
    WORD flags_;
};
typedef ObjectMagicDOS OBJECT_MAGIC;

// 敌人
struct ObjectEnemy {
    WORD enemy_id_;
    WORD resistance_to_sorcery_;
    // 脚本
    WORD on_turn_start_;
    WORD on_battle_end_;
    WORD on_ready_;
};
typedef ObjectEnemy OBJECT_ENEMY;

// 毒药
typedef struct ObjectPosion {
    WORD level_;
    WORD color_;
    WORD player_script_;
    WORD reserved_;
    WORD enemy_script_;
} OBJECT_POISON;

typedef union ObjectDos {
    WORD rgw_data[6];
    OBJECT_PLAYER player_;
    OBJECT_ITEM_DOS item_;
    OBJECT_MAGIC_DOS magic_;
    OBJECT_ENEMY enemy_;
    OBJECT_POISON poison_;
} OBJECT_DOS, *LPOBJECT_DOS;

typedef union Object {
    WORD rgw_data[7];
    OBJECT_PLAYER player_;
    OBJECT_ITEM item_;
    OBJECT_MAGIC magic_;
    OBJECT_ENEMY enemy_;
    OBJECT_POISON poison_;
} OBJECT, *LPOBJECT;

typedef struct ScriptEntry {
    WORD operation_;
    WORD rgw_operand_[3];
} SCRIPTENTRY, *LPSCRIPTENTRY;

// 库存
typedef struct Inventory {
    WORD item_;
    USHORT amount_;
    USHORT amount_in_use_;
} INVENTORY, *LPINVENTORY;

typedef struct Store {
    WORD rgw_items_[MAX_STORE_ITEM];
} STORE, *LPSTORE;

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

typedef struct EnemyTeam {
    WORD rgw_enemy_[MAX_ENEMIES_IN_TEAM];
} ENEMYTEAM, *LPENEMYTEAM;

// 对源代码进行了修改，使用array实现相同功能，暂时不知道会不会对二进制源码的读取产生影响
using Players = std::array<WORD, MAX_PLAYER_ROLES>;

typedef struct PlayerRoles {
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
} PLAYERROLES, *LPPLAYERROLES;

// 法术类型
typedef enum class MagicType : uint8_t {
    Normal = 0,        // 普通单体
    AttackAll = 1,     // 依次攻击
    AttackWhole = 2,   // 群体攻击
    AttackField = 3,   // 全屏攻击
    ApplyToPlayer = 4, // 单体治疗
    ApplyToParty = 5,  // 群体治疗
    Trance = 8,        // 觉醒（特殊状态）
    Summon = 9         // 召唤术
} MAGIC_TYPE;

// 特殊法术参数
typedef union MagicSpecial {
    WORD summon_effect_; // 召唤精灵
    SHORT layer_offset_; // 仅用于非召唤魔法
    // 实际图层位置：Pal_Y(pos)+y_offset+magic_layer_offset
} MAGIC_SPECIAL, *LPMAGIC_SPECIAL;

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

typedef struct BattleField {
    WORD screen_wave_;                        // 屏幕波动等级
    SHORT magic_effect_[NUM_MAGIC_ELEMENTAL]; // 元素魔法的特效状态
} BATTLEFIELD, *LPBATTLEFIELD;

#endif // pal_ohos_GLOBAL_H
