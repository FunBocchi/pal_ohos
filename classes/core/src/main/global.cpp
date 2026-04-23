//
// Created on 2026/4/21.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "global.h"
#include "defs/palcommon.h"
#include "mkf_util.h"
#include "structs/ui/ui.h"
#include <cstdint>

/**
 * 由于将各种方法封装进了GlobalVars类中，同时该类为单例模式，因此做出了一定程度上的修改
 */

GlobalVars *GlobalVars::GetInstance() {
    static GlobalVars instance;
    return &instance;
}

/**
 * 打开并读取文件流
 * @return
 */
bool GlobalVars::InitGlobals() {
    auto f = getF();
    // 打开文件
    f.FBP = MKFUtil::OpenRequiredFile("FBP.MKF");
    f.MGO = MKFUtil::OpenRequiredFile("MGO.MKF");
    f.BALL = MKFUtil::OpenRequiredFile("BALL.MKF");
    f.DATA = MKFUtil::OpenRequiredFile("DATA.MKF");
    f.F = MKFUtil::OpenRequiredFile("F.MKF");
    f.FIRE = MKFUtil::OpenRequiredFile("FIRE.MKF");
    f.RGM = MKFUtil::OpenRequiredFile("RGM.MKF");
    f.SSS = MKFUtil::OpenRequiredFile("SSS.MKF");

    lp_object_desc_ = UI::loadObjectDesc("desc.dat");

    current_save_slot_ = 1;

    return true;
}

/**
 * 移除指定角色的指定魔法
 * @param player_role 玩家角色id
 * @param magic 魔法id
 */
void GlobalVars::RemoveMagic(uint16_t player_role, uint16_t magic) {
    for (int i = 0; i < MAX_PLAYER_MAGICS; ++i) {
        if (g_.player_roles.magic[i][player_role] == magic) {
            g_.player_roles.magic[i][player_role] = 0;
            break;
        }
    }
}

/**
 * 对指定角色设置持续状态
 * @param player_role
 * @param status_id
 * @param num_round
 * @return
 */
bool GlobalVars::SetPlayerStatus(uint16_t player_role, uint16_t status_id, uint16_t num_round) {
    bool if_success = true;
#ifndef PAL_CLASSIC
    if (status_id == CharaStatus::kSlow && player_status_[player_role][CharaStatus::kHaste] > 0) {
    }
#endif
}

/**
 * 获取角色综合攻击力
 * @param player_role
 * @return
 */
uint16_t GlobalVars::GetPlayerAttackStrength(uint16_t player_role) {
    uint16_t w;

    w = g_.player_roles.attack_strength[player_role];

    for (int32_t i = 0; i <= MAX_PLAYER_EQUIPMENTS; ++i) {
        w += equipment_effect_[i].attack_strength[player_role];
    }
    return w;
}

/**
 * 获取综合魔法攻击力
 * @param player_role
 * @return
 */
uint16_t GlobalVars::GetPlayerMagicStrength(uint16_t player_role) {
    uint16_t w;

    w = g_.player_roles.magic_strength[player_role];

    for (int32_t i; i <= MAX_PLAYER_EQUIPMENTS; ++i) {
        w += equipment_effect_[i].magic_strength[player_role];
    }
    return w;
}

/**
 * 获取综合防御力
 * @param player_role
 * @return
 */
uint16_t GlobalVars::GetPlayerDefence(uint16_t player_role) {
    uint16_t w;
    w = g_.player_roles.defence[player_role];
    for (int32_t i = 0; i <= MAX_PLAYER_EQUIPMENTS; ++i) {
        w += equipment_effect_[i].defence[player_role];
    }
    return w;
}

/**
 * 获取敏捷值
 * @param player_role
 * @return
 */
uint16_t GlobalVars::GetPlayerDexterity(uint16_t player_role) {
    uint16_t w;
    w = g_.player_roles.dexterity[player_role];
#ifdef PAL_CLASSIC
    for (int32_t i = 0; i <= MAX_PLAYER_EQUIPMENTS; ++i)
#else
    for (int32_t i = 0; i <= MAX_PLAYER_EQUIPMENTS - 1; ++i)
#endif
    {
        w += equipment_effect_[i].dexterity[player_role];
    }
    return w;
}

uint16_t GlobalVars::GetPlayerFleeRate(uint16_t player_role) {
    uint16_t w;
    w = g_.player_roles.flee_rate[player_role];
    for (int32_t i = 0; i <= MAX_PLAYER_EQUIPMENTS; ++i) {
        w += equipment_effect_[i].flee_rate[player_role];
    }
    return w;
}