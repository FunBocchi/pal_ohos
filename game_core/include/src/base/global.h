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
#include <cstdint>

struct GlobalVars {
    Files f;
    GameData g;

    int32_t cur_main_menu_item_;
    int32_t cur_system_menu_item_;
    int32_t cur_inv_menu_item_;
    int32_t cur_playing_rng_;
    uint8_t current_save_slot_;
    bool in_main_game_;
    bool entering_scene_;
    bool need_to_fade_in_;
    bool in_battle_;
    bool auto_battle_;

#ifndef PAL_CLASSIC
    uint8_t battle_speed_;
#endif
    uint16_t last_unequipped_item_;

    // 使用array替代源项目创建数组的方案，更符合C++规范
    std::array<PlayerRoles, MAX_PLAYER_EQUIPMENTS + 1> equipment_effect_;
    std::array<std::array<uint16_t, kCharaStatusCount>, MAX_PLAYER_ROLES> player_status_;

    PalPos viewport_;
    PalPos party_offset_;
    uint16_t layer_;
    uint16_t max_party_member_index_;
    std::array<Party, MAX_PLAYABLE_PLAYER_ROLES> party_;
    std::array<Trail, MAX_PLAYABLE_PLAYER_ROLES> trail_;
    uint16_t party_direction_;
    uint16_t num_scene_;
    uint16_t num_palette_;
    bool night_palette_;
    uint16_t num_music_;
    uint16_t num_battle_music_;
    uint16_t num_battle_field_;
    uint16_t collect_value_;
    uint16_t screen_wave_;
    int16_t wave_progression_;
    uint16_t chase_range_;
    uint16_t chasespeed_change_cycles_;
    uint16_t follower_;

    uint32_t cash_;

    AllExperience exp_;
    std::array<std::array<PoisonStatus, MAX_PLAYABLE_PLAYER_ROLES>, MAX_POISONS> poison_status_;
    std::array<Inventory, MAX_INVENTORY> inventory_;
    /**
     * 待ui类补全后补全该处
     * LPOBJECTDESC lpObjectDesc;
     **/

    uint32_t frame_num_;
};

#endif // pal_ohos_GLOBAL_H
