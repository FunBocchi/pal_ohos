//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_GAME_DATA_H
#define pal_ohos_GAME_DATA_H

#include "src/base/battle_field.h"
#include "src/base/scene.h"
#include "src/base/script_entry.h"
#include "../inventory/store.h"
#include "src/enemy/enemy.h"
#include "src/enemy/enemy_pos.h"
#include "src/enemy/enemy_team.h"
#include "src/magic/level_up_magic.h"
#include "src/magic/magic.h"
#include "src/object/event_object.h"
#include "src/object/object.h"
#include "src/player/player_roles.h"
#include "util/common.h"
#include "util/palcommon.h"
#include <cstdint>

// 升级所需经验点
typedef uint16_t LEVELUPEXP, *LPLEVELUPEXP;

struct GameData {
    EventObject* lp_event_object;
    int n_event_object;

    Scene scene[MAX_SCENES];
   Object object[MAX_OBJECTS];

    ScriptEntry* lp_script_entry;
    int n_script_entry;

    Store* lp_store;
    int n_store;

    Enemy* lp_enemy;
    int n_enemy;

    EnemyTeam* lp_enemy_team;
    int n_enemy_team;

    PlayerRoles player_roles;

    Magic* lp_magic;
    int n_magic;

    BattleField* lp_battle_field;
    int n_battle_field;

    LevelUpMagic_All* lp_levelup_magic;
    int n_levelup_magic;

    EnemyPos enemy_pos;
    LEVELUPEXP levelup_exp[MAX_LEVELS + 1];

    uint16_t     battle_effect_index[10][2];
};

#endif // pal_ohos_GAME_DATA_H
