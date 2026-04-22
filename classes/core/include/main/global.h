//
// Created on 2026/4/21.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef PAL_OHOS_GLOBAL_H
#define PAL_OHOS_GLOBAL_H

#include "enums/chara_status.h"
#include "structs/base/files.h"
#include "structs/base/game_data.h"
#include "structs/inventory/inventory.h"
#include "structs/player/experience.h"
#include "structs/player/party.h"
#include "structs/player/poison_status.h"
#include "structs/player/trail.h"
#include "structs/ui/object_desc.h"
#include <cstdint>

class GlobalVars {
private:
    Files f_;
    GameData g_;

    int32_t cur_main_menu_item_;   // 当前主菜单项编号
    int32_t cur_system_menu_item_; // 当前系统菜单项编号
    int32_t cur_inv_menu_item_;     // 当前物品栏菜单项编号

    int32_t cur_playing_rng_;   // 当前正在播放的RNG动画
    uint8_t current_save_slot_; // 当前存档槽位（1-5）
    bool in_main_game_;         // 若在主游戏中则为True
    bool entering_scene_;       // 若正在进入新场景则为 TRUE
    bool need_to_fade_in_;      // 若绘制场景时需要淡入则为 TRUE
    bool in_battle_;            // 若在战斗中则为 TRUE
    bool auto_battle_;          // 若为自动战斗则为 TRUE

#ifndef PAL_CLASSIC
    uint8_t battle_speed_; // 战斗速度（1=最快，5=最慢）
#endif
    uint16_t last_unequipped_item_; // 最后卸下的物品

    std::array<PlayerRoles, MAX_PLAYER_EQUIPMENTS + 1> equipment_effect_;                 // 装备效果
    std::array<std::array<uint16_t, kCharaStatusCount>, MAX_PLAYER_ROLES> player_status_; // 玩家状态

    PalPos viewport_; // 视口坐标
    PalPos party_offset_;
    uint16_t layer_;
    uint16_t max_party_member_index_;                    // 队伍成员的最大索引（0 至 MAX_PLAYERS_IN_PARTY - 1）
    std::array<Party, MAX_PLAYABLE_PLAYER_ROLES> party_; // 玩家队伍
    std::array<Trail, MAX_PLAYABLE_PLAYER_ROLES> trail_; // 玩家足迹
    uint16_t party_direction_;                           // 队伍朝向
    uint16_t num_scene_;                                 // 当前场景编号
    uint16_t num_palette_;                               // 当前调色板编号
    bool night_palette_;                                 // 若使用较暗的夜间调色板则为 TRUE
    uint16_t num_music_;                                 // 当前音乐编号
    uint16_t num_battle_music_;                          // 当前战斗音乐编号
    uint16_t num_battle_field_;                          // 当前战斗场景编号
    uint16_t collect_value_;                             // “收集”物品的价值
    uint16_t screen_wave_;                               // 屏幕波动程度
    int16_t wave_progression_;
    uint16_t chase_range_;
    uint16_t chase_speed_change_cycles_;
    uint16_t follower_;

    uint32_t cash_; // 金钱数量

    AllExperience exp_;                                                                          // 经验状态
    std::array<std::array<PoisonStatus, MAX_PLAYABLE_PLAYER_ROLES>, MAX_POISONS> poison_status_; // 中毒状态
    std::array<Inventory, MAX_INVENTORY> inventory_;                                             // 物品栏状态
    ObjectDesc *lp_object_desc_;

    uint32_t frame_num_;

public:
    static GlobalVars *GetInstance();
    // 删除拷贝构造函数和赋值运算符
    GlobalVars(const GlobalVars &) = delete;
    GlobalVars &operator=(const GlobalVars &) = delete;

    bool IsWinVersion(bool *is_win95);
    bool InitGlobals();
    void FreeGlobals();
    void ReadGlobalGameData();
    void SaveGame(int32_t save_slot, uint16_t saved_times);
    void InitGameData(int32_t save_slot);
    void ReloadInNextTick(int32_t save_slot);
    int CountItem(uint16_t object_id);
    bool GetItemIndexToInventory(uint16_t object_id, int32_t *index);
    int AddItemToInventory(uint16_t object_id, int32_t num);
    bool IncreaseHPMP(uint16_t player_role, int16_t hp, int16_t mp);
    int32_t GetItemAmount(uint16_t item);
    void UpdateEquipments();
    void CompressInventory();
    void RemoveEquipmentEffect(uint16_t player_role, uint16_t equipPart);
    void AddPoisonForPlayer(uint16_t player_role, uint16_t poison_id);
    void CurePoisonByKind(uint16_t player_role, uint16_t poison_id);
    void CurePoisonByLevel(uint16_t player_role, uint16_t max_level);
    bool IsPlayerPoisonedByKind(uint16_t player_role, uint16_t poison_id);
    bool IsPlayerPoisonedByLevel(uint16_t player_role, uint16_t min_level);
    uint16_t GetPlayerAttackStrength(uint16_t player_role);
    uint16_t GetPlayerMagicStrength(uint16_t player_role);
    uint16_t GetPlayerDefence(uint16_t player_role);
    uint16_t GetPlayerDexterity(uint16_t player_role);
    uint16_t GetPlayerFleeRate(uint16_t player_role);
    uint16_t GetPlayerPoisonResistance(uint16_t player_role);
    uint16_t GetPlayerElementalResistance(uint16_t player_role, int32_t attrib);
    uint16_t GetPlayerBattleSprite(uint16_t player_role);
    uint16_t GetPlayerCooperativeMagic(uint16_t player_role);
    bool CanPlayerAttackAll(uint16_t player_role);
    bool AddMagic(uint16_t player_role, uint16_t magic);
    void RemoveMagic(uint16_t player_role, uint16_t magic);
    bool SetPlayerStatus(uint16_t player_role, uint16_t status_id, uint16_t num_round);
    void RemovePlayerStatus(uint16_t player_role, uint16_t status_id);
    void ClearAllPlayerStatus();
    void PlayerLevelUp(uint16_t player_role, uint16_t num_level);

private:
    GlobalVars() = default;
    ~GlobalVars() = default;
public:
    GameData getG(){
        return g_;
    };
    Files getF(){
        return f_;
    };
};

#endif // PAL_OHOS_GLOBAL_H
