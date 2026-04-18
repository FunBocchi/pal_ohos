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
#include "src/base/store.h"
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

// 升级所需经验点
typedef WORD LEVELUPEXP, *LPLEVELUPEXP;

typedef struct GameData {
    LPEVENTOBJECT lp_event_object_;
    int n_event_object_;

    SCENE scene_[MAX_SCENES];
    OBJECT object_[MAX_OBJECTS];

    LPSCRIPTENTRY lp_script_entry_;
    int n_script_entry_;

    LPSTORE lp_store_;
    int n_store_;

    LPENEMY lp_enemy_;
    int n_enemy_;

    LPENEMYTEAM lp_enemy_team_;
    int n_enemy_team_;

    PLAYERROLES player_roles;

    LPMAGIC lp_magic_;
    int n_magic_;

    LPBATTLEFIELD lp_battle_field_;
    int n_battle_field_;

    LPLEVELUPMAGIC_ALL lp_levelup_magic_;
    int n_levelup_magic_;

    ENEMYPOS enemy_pos_;
    LEVELUPEXP levelup_exp_[MAX_LEVELS + 1];

    WORD battle_effect_index_[10][2];
} GAMEDATA, *LPGAMEDATA;

#endif // pal_ohos_GAME_DATA_H
