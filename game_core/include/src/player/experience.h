//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_EXPERIENCE_H
#define pal_ohos_EXPERIENCE_H

#include "util/common.h"
#include "util/palcommon.h"

typedef struct Experience {
    WORD exp_; // 当前经验点
    WORD reserved_;
    WORD level_; // 当前等级
    WORD count_;
} EXPERIENCE, *LPEXPERIENCE;

// 各种属性设定，除角色升级外，可通过多次使用对应技能或动作来提升对应能力值
typedef struct AllExperience {
    EXPERIENCE primary_exp_[MAX_PLAYER_ROLES];
    EXPERIENCE health_exp_[MAX_PLAYER_ROLES];
    EXPERIENCE magic_exp_[MAX_PLAYER_ROLES];
    EXPERIENCE attack_exp_[MAX_PLAYER_ROLES];
    EXPERIENCE magic_power_exp_[MAX_PLAYER_ROLES];
    EXPERIENCE defence_exp_[MAX_PLAYER_ROLES];
    EXPERIENCE dexterity_exp_[MAX_PLAYER_ROLES];
    EXPERIENCE flee_exp_[MAX_PLAYER_ROLES];
} ALLEXPERIENCE, *LPALLEXPERIENCE;

#endif // pal_ohos_EXPERIENCE_H
