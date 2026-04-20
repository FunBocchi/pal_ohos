//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_EXPERIENCE_H
#define pal_ohos_EXPERIENCE_H

#include "util/common.h"
#include "util/palcommon.h"

struct Experience {
    uint16_t exp_; // 当前经验点
    uint16_t reserved_;
    uint16_t level_; // 当前等级
    uint16_t count_;
};

// 各种属性设定，除角色升级外，可通过多次使用对应技能或动作来提升对应能力值
struct AllExperience {
    Experience primary_exp_[MAX_PLAYER_ROLES];
    Experience health_exp_[MAX_PLAYER_ROLES];
    Experience magic_exp_[MAX_PLAYER_ROLES];
    Experience attack_exp_[MAX_PLAYER_ROLES];
    Experience magic_power_exp_[MAX_PLAYER_ROLES];
    Experience defence_exp_[MAX_PLAYER_ROLES];
    Experience dexterity_exp_[MAX_PLAYER_ROLES];
    Experience flee_exp_[MAX_PLAYER_ROLES];
};

#endif // pal_ohos_EXPERIENCE_H
