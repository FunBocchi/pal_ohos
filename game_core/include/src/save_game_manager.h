//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

// 负责存档的保存和加载

#ifndef pal_ohos_SAVE_GAME_MANAGER_H
#define pal_ohos_SAVE_GAME_MANAGER_H

#include "src/base/scene.h"
#include "src/inventory/inventory.h"
#include "src/player/experience.h"
#include "src/player/party.h"
#include "src/player/player_roles.h"
#include "src/player/poison_status.h"
#include "src/player/trail.h"
#include "util/common.h"
#include "util/palcommon.h"
#include <cstdint>

struct SavedGame_Common {
    uint16_t w_saved_times_;              // 保存次数
    uint16_t w_viewport_x, w_viewport_y_; // 摄像机位置
    uint16_t n_party_member_;             // 队伍人数
    uint16_t w_num_scene_;                // 场景编号
    uint16_t w_palette_offset_;
    uint16_t w_party_direction_;  // 队伍朝向
    uint16_t w_num_music_;        // 背景音乐编号
    uint16_t w_num_battle_music_; // 战斗场景音乐
    uint16_t w_num_battle_field_; // 战斗场景背景
    uint16_t w_screen_wave_;      // 屏幕滚动强度
    uint16_t w_battle_speed_;     // 战斗速度
    uint16_t w_collect_value_;    // 收集物品总数
    uint16_t w_layer_;
    uint16_t w_chase_range_;
    uint16_t w_chasespeed_change_cycles_;
    uint16_t n_follower_;
    uint16_t rgw_reserved2[3];                  // 占位符，恒0
    uint32_t dw_cash_;                          // 现金总数
    Party rg_party_[MAX_PLAYABLE_PLAYER_ROLES]; // 队伍组成
    Trail rg_trail_[MAX_PLAYABLE_PLAYER_ROLES]; // 队伍轨迹
    AllExperience exp_;                         // 经验数据
    PlayerRoles player_roles_;
    PoisonStatus rg_poison_status_[MAX_POISONS][MAX_PLAYABLE_PLAYER_ROLES]; // 中毒状况
    Inventory rg_inventory_[MAX_INVENTORY];                                 // 物品状况
    Scene rg_scene_[MAX_SCENES];
};

class SaveGameManager {
public:
    void saveGame(int save_slot, uint16_t saved_times); // 存档
    void initGameData(int save_slot);                   // 读取
    void reloadInNextTick(int save_slot);               // 在下一帧重加载

private:
    /**
     * 根据系统选择对应的loading方式
     */
    int loadGameDOS(int i_save_slot);
    int loadGameWIN(int i_save_slot);
    int loadGame(int i_save_slot);
};

#endif // pal_ohos_SAVE_GAME_MANAGER_H
