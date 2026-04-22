//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_EXPERIENCE_H
#define pal_ohos_EXPERIENCE_H

#include <cstdint>
#include "../../defs/palcommon.h"
struct Experience {
    uint16_t exp; // 当前经验点
    uint16_t reserved;
    uint16_t level; // 当前等级
    uint16_t count;
};

// 各种属性设定，除角色升级外，可通过多次使用对应技能或动作来提升对应能力值
struct AllExperience {
    Experience primary_exp[MAX_PLAYER_ROLES];
    Experience health_exp[MAX_PLAYER_ROLES];
    Experience magic_exp[MAX_PLAYER_ROLES];
    Experience attack_exp[MAX_PLAYER_ROLES];
    Experience magic_power_exp[MAX_PLAYER_ROLES];
    Experience defence_exp[MAX_PLAYER_ROLES];
    Experience dexterity_exp[MAX_PLAYER_ROLES];
    Experience flee_exp[MAX_PLAYER_ROLES];
};

#endif // pal_ohos_EXPERIENCE_H
