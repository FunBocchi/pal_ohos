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

// 对源项目进行解耦，通过不同文件存储枚举类型用以区分
#include "src/base/files.h"
#include "src/base/game_data.h"
#include "src/base/pal_pos.h"
#include "src/inventory/inventory.h"
#include "src/player/chara_status.h"
#include "src/player/experience.h"
#include "src/player/party.h"
#include "src/player/poison_status.h"
#include "src/player/trail.h"
#include "util/common.h"
#include "util/palcommon.h"

typedef struct GlobalVars {
    FILES f;
    GAMEDATA g;

    int cur_main_menu_item_;
    int cur_system_menu_item_;
    int cur_inv_menu_item_;
    int cur_playing_rng_;
    BYTE current_save_slot_;
    bool in_main_game_;
    bool entering_scene_;
    bool need_to_fade_in_;
    bool in_battle_;
    bool auto_battle_;

#ifndef PAL_CLASSIC
    BYTE battle_speed_;
#endif
    WORD last_unequipped_item_;

    PLAYERROLES equipment_effect_[MAX_PLAYER_EQUIPMENTS + 1];
    // 使用array替代源项目创建数组的方案，更符合C++规范
    std::array<std::array<WORD, kCharaStatusCount>, MAX_PLAYER_ROLES> player_status_;

    PALPOS viewport_;
    PALPOS partyoffset_;
    WORD layer_;
    WORD max_party_member_index_;
    std::array<PARTY, MAX_PLAYABLE_PLAYER_ROLES> party_;
    std::array<TRAIL, MAX_PLAYABLE_PLAYER_ROLES> trail_;
    WORD party_direction_;
    WORD num_scene_;
    WORD num_palette_;
    bool night_palette_;
    WORD num_music_;
    WORD num_battle_music_;
    WORD num_battle_field_;
    WORD collect_value_;
    WORD screen_wave_;
    SHORT wave_progression_;
    WORD chase_range_;
    WORD chasespeed_change_cycles_;
    USHORT follower_;

    DWORD cash_;

    ALLEXPERIENCE exp_;
    std::array<std::array<POISONSTATUS, MAX_PLAYABLE_PLAYER_ROLES>, MAX_POISONS> poison_status_;
    std::array<INVENTORY, MAX_INVENTORY> inventory_;
    /**
     * 待ui类补全后补全该处
     * LPOBJECTDESC lpObjectDesc;
     **/

    DWORD frame_num_;
} GLOBALVARS, *LPGLOBALVARS;

#endif // pal_ohos_GLOBAL_H
