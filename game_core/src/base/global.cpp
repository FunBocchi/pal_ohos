//
// Created on 2026/4/21.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "src/base/global.h"
#include "src/ui/ui.h"
#include "util/palcommon.h"
#include "util/util.h"

/**
 * 由于将各种方法封装进了GlobalVars类中，同时该类为单例模式，因此做出了一定程度上的修改
 */
bool GlobalVars::InitGlobals() {
    auto f = getF();
    // 打开文件
    f.FBP = UTIL::openRequiredFile("FBP.MKF");
    f.MGO = UTIL::openRequiredFile("MGO.MKF");
    f.BALL = UTIL::openRequiredFile("BALL.MKF");
    f.DATA = UTIL::openRequiredFile("DATA.MKF");
    f.F = UTIL::openRequiredFile("F.MKF");
    f.FIRE = UTIL::openRequiredFile("FIRE.MKF");
    f.RGM = UTIL::openRequiredFile("RGM.MKF");
    f.SSS = UTIL::openRequiredFile("SSS.MKF");

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

bool GlobalVars::SetPlayerStatus(uint16_t player_role, uint16_t status_id, uint16_t num_round) {
    bool 
}