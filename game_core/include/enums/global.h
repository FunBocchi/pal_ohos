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
struct ObjectPosion {
    WORD level_;
    WORD color_;
    WORD player_script_;
    WORD reserved_;
    WORD enemy_script_;
};
typedef ObjectPosion OBJECT_POISON;

union ObjectDos {
    WORD rgw_data[6];
    OBJECT_PLAYER player_;
    OBJECT_ITEM_DOS item_;
    OBJECT_MAGIC_DOS magic_;
    OBJECT_ENEMY enemy_;
    OBJECT_POISON poison_;
};
typedef ObjectDos OBJECT_DOS, *LPOBJECT_DOS;

union Object {
    WORD rgw_data[7];
    OBJECT_PLAYER player_;
    OBJECT_ITEM item_;
    OBJECT_MAGIC magic_;
    OBJECT_ENEMY enemy_;
    OBJECT_POISON poison_;
};
typedef Object OBJECT, *LPOBJECT;

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

typedef struct Enemy{
    
} ENEMY,*LPENEMY;
#endif // pal_ohos_GLOBAL_H
