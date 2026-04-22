//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_GAME_DATA_H
#define pal_ohos_GAME_DATA_H

#include <cstdint>
#include "../object/event_object.h"
#include "../../defs/palcommon.h"
#include "battle_field.h"
#include "scene.h"
#include "../object/object.h"
#include "script_entry.h"
#include "../inventory/store.h"
#include "../enemy/enemy.h"
#include "../enemy/enemy_pos.h"
#include "../enemy/enemy_team.h"
#include "../player/player_roles.h"
#include "../magic/magic.h"
#include "../magic/level_up_magic.h"
// 升级所需经验点
typedef uint16_t LEVELUPEXP, *LPLEVELUPEXP;

struct GameData {
    EventObject *lp_event_object;
    int n_event_object;

    Scene scene[MAX_SCENES];
    Object object[MAX_OBJECTS];

    ScriptEntry *lp_script_entry;
    int n_script_entry;

    Store *lp_store;
    int n_store;

    Enemy *lp_enemy;
    int n_enemy;

    EnemyTeam *lp_enemy_team;
    int n_enemy_team;

    PlayerRoles player_roles;

    Magic *lp_magic;
    int n_magic;

    BattleField *lp_battle_field;
    int n_battle_field;

    LevelUpMagic_All *lp_level_up_magic;
    int n_level_up_magic;

    EnemyPos enemy_pos;
    LEVELUPEXP level_up_exp[MAX_LEVELS + 1];

    uint16_t battle_effect_index[10][2];
};

#endif // pal_ohos_GAME_DATA_H
