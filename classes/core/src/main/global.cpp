//
// Created on 2026/4/21.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "global.h"
#include "defs/palcommon.h"
#include "math_util.h"
#include "mkf_util.h"
#include "script.h"
#include "structs/ui/ui.h"
#include <cassert>
#include <cstdint>
#include "enums/body_part.h"

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

void GlobalVars::InitGameData(int32_t save_slot) {
    InitGlobalGameData();
    current_save_slot_=(uint8_t)save_slot;
    
    if (save_slot==0||!LoadGame(save_slot)) {
        LoadDefaultGame();
    }
    cur_inv_menu_item_=0;
    in_battle_=false;
//    memset(&player_status_, 0, sizeof(player_status_));
    player_status_.fill(std::array<uint16_t, kCharaStatusCount>{});
    
    UpdateEquipments();
}

int GlobalVars::CountItem(uint16_t object_id) {
    int32_t index,count,i,j,w;
    if (object_id==0) {
        return false;
    }
    index=0;
    count=0;
    
    while (index<MAX_INVENTORY) {
        if (inventory_[index].item==object_id) {
            count=inventory_[index].amount;break;
        } else if (inventory_[index].item==0) {
            break;
        }++index;
    }
    
    for (i=0; i<=max_party_member_index_; ++i) {
        w=party_[i].player_role;
        for (j=0; j<MAX_PLAYER_EQUIPMENTS; ++j) {
            if (g_.player_roles.equipment[j][w]==object_id) {
                ++count;
            }
        }
    }
    return count;
}

bool GlobalVars::GetItemIndexToInventory(uint16_t object_id, int32_t *index) {
    bool has_found=false;
    *index=0;
    while (*index<MAX_INVENTORY) {
        if (inventory_[*index].item==object_id) {
            has_found=true;break;
        } else if (inventory_[*index].item==0) {
            break;
        }
        (*index)++;
    }
    return has_found;
}

int GlobalVars::AddItemToInventory(uint16_t object_id, int32_t num) {
    int32_t index;
    bool has_found;
    if (object_id==0) {
        return false;
    }
    if (num==0) {
        num=1;
    }
    index=0;
    has_found=false;
        
    //寻找指定物品
    has_found=GetItemIndexToInventory(object_id, &index);

    if (num>0) {
        if (index>=MAX_INVENTORY) {
            return false;
        }
        if (has_found) {
            inventory_[index].amount+=num;
            if (inventory_[index].amount>99) {
                inventory_[index].amount=99;
            }
        }else{
            inventory_[index].item=object_id;
            if (num>99) {
                num=99;
            }
            inventory_[index].amount=num;
        }
        return true;
    }
}

int32_t GlobalVars::GetItemAmount(uint16_t item) {
    int32_t i;
    for (i=0; i<MAX_INVENTORY; ++i) {
        if (inventory_[i].item==0) {
            break;
        }
        if (inventory_[i].item==item) {
            return inventory_[i].amount;
        }
    }
    return 0;
}

/**
 * 整理背包
 */
void GlobalVars::CompressInventory() {
    int32_t i,j;
    j=0;
    //检测并删除数量为0的物品
    for (i=0; i<MAX_INVENTORY; ++i) {
        if (inventory_[i].amount>0) {
            inventory_[j]=inventory_[i];
            j++;
        }
    }
    for (; j<MAX_INVENTORY; ++j) {
        inventory_[j].amount=0;
        inventory_[j].amount_in_use=0;
        inventory_[j].item=0;
    }
}

bool GlobalVars::IncreaseHPMP(uint16_t player_role, int16_t hp, int16_t mp) {
    bool f=false;
    uint16_t orig_hp=g_.player_roles.hp[player_role];
    uint16_t orig_mp=g_.player_roles.mp[player_role];
    
    //只关注仍存活角色
    if (g_.player_roles.hp[player_role]>0) {
        //修改生命值
        g_.player_roles.hp[player_role]+=hp;
        
        if ((int16_t)(g_.player_roles.hp[player_role])<0) {
            g_.player_roles.hp[player_role]=0;
        } else if (g_.player_roles.hp[player_role]>g_.player_roles.max_hp[player_role]) {
            g_.player_roles.hp[player_role]=g_.player_roles.max_hp[player_role];
        }
        //修改法力值
        if ((int16_t)(g_.player_roles.mp[player_role])<0) {
            g_.player_roles.mp[player_role]=0;
        } else if (g_.player_roles.mp[player_role]>g_.player_roles.max_mp[player_role]) {
            g_.player_roles.mp[player_role]=g_.player_roles.max_mp[player_role];
        }
        
        if (orig_hp!=g_.player_roles.hp[player_role]||orig_mp!=g_.player_roles.mp[player_role]) {
            f=true;
        }
    }
    return f;
}

void GlobalVars::UpdateEquipments() {
    int32_t i,j;
    uint16_t w;
    memset(&(equipment_effect_), 0, sizeof(equipment_effect_));
    
    for (i=0; i<MAX_PLAYER_ROLES; ++i) {
        for (j=0; j<MAX_PLAYER_EQUIPMENTS; ++j) {
            w=g_.player_roles.equipment[j][i];
            if (w!=0) {
                g_.object[w].item.script_on_equip_=Script::RunTriggerScript(g_.object[w].item.script_on_equip_, (uint16_t)i);
            }
        }
    }
}

/**
 * 移除全部装备效果
 * @param player_role
 * @param equip_part
 */
void GlobalVars::RemoveEquipmentEffect(uint16_t player_role, uint16_t equip_part) {
    uint16_t*p;
    int32_t i,j;
    auto w_equip_part=static_cast<BodyPart>(equip_part);
    p=(uint16_t*)(&equipment_effect_[equip_part]);
    for (i=0; i<sizeof(PlayerRoles)/sizeof(Players); ++i) {
        p[i*MAX_PLAYER_ROLES+player_role]=0;
    }
    if (w_equip_part==BodyPart::kHand) {
        player_status_[player_role][static_cast<uint16_t>(CharaStatus::kDualAttack)]=0;
    } else if (w_equip_part == BodyPart::kWear) {
        for (i=0; i<=(int16_t)max_party_member_index_; ++i) {
            if (party_[i].player_role==player_role) {
                player_role=i;break;
            }
        }
        if (i<=(short)max_party_member_index_) {
            j=0;
            for (i=0; i<MAX_POISONS; ++i) {
                uint16_t w=poison_status_[i][player_role].poison_id;
                if (w==0) {
                    break;
                }
                if (g_.object[w].poison.level<99) {
                    poison_status_[j][player_role]=poison_status_[i][player_role];
                    ++j;
                }
            }
            while (j<MAX_POISONS){
                poison_status_[j][player_role].poison_id=0;
                poison_status_[j][player_role].poison_script=0;
                ++j;
            }
        }
    }
}

void GlobalVars::AddPoisonForPlayer(uint16_t player_role, uint16_t poison_id) {
    int32_t i,index;
    uint16_t w;
    for (index=0; index<=max_party_member_index_; ++i) {
        if (party_[index].player_role==player_role) {
            break;
        }
    }
    if (index>max_party_member_index_) {
        return;
    }
    for (i=0; i<MAX_POISONS; ++i) {
        w=poison_status_[i][index].poison_id;
        if (w==0) {
            break;
        }
        if (w==poison_id) {
            return;
        }
    }
    if (i<MAX_POISONS) {
        poison_status_[i][index].poison_id=poison_id;
        poison_status_[i][index].poison_script=Script::RunTriggerScript(g_.object[poison_id].poison.player_script, player_role);
    }
}

void GlobalVars::CurePoisonByLevel(uint16_t player_role, uint16_t max_level) {
    int32_t index;
    uint16_t w;
    for (index=0; index<=max_party_member_index_; ++index) {
        if (party_[index].player_role==player_role) {
            break;
        }
    }
    if (index>max_party_member_index_) {
        return;
    }
    for (int32_t i=0; i<MAX_POISONS; ++i) {
        w=poison_status_[i][index].poison_id;
        if (g_.object[w].poison.level<=max_level) {
            poison_status_[i][index].poison_id=0;
            poison_status_[i][index].poison_script=0;
        }
    }
}

bool GlobalVars::IsPlayerPoisonedByLevel(uint16_t player_role, uint16_t min_level) {
    int32_t index;
    uint16_t w;
    for (index=0; index<=max_party_member_index_; ++index) {
        if (party_[index].player_role==player_role) {
            break;
        }
    }
    if (index>max_party_member_index_) {
        return false;
    }
    for (int32_t i; i<MAX_POISONS; ++i) {
        w=poison_status_[i][index].poison_id;
        if (w==0) {
            continue;;
        }
        w=g_.object[w].poison.level;
        if (w>=99) {
            continue;
        }
        if (w>=min_level) {
            return true;
        }
    }
    return false;
}

void GlobalVars::CurePoisonByKind(uint16_t player_role, uint16_t poison_id) {
    int32_t index;
    for (index=0; index<=max_party_member_index_; ++index) {
        if (party_[index].player_role==player_role) {
            break;
        }
    }
    if (index>max_party_member_index_) {
        return;
    }
    for (int32_t i=0; i<MAX_POISONS; ++i) {
        if (poison_status_[i][index].poison_id==poison_id) {
            poison_status_[i][index].poison_id=0;poison_status_[i][index].poison_script=0;
        }
    }
}

bool GlobalVars::IsPlayerPoisonedByKind(uint16_t player_role, uint16_t poison_id) {
    int32_t index;
    for (index=0; index<=max_party_member_index_; ++index) {
        if (party_[index].player_role==player_role) {
            break;
        }
    }
    if (index>max_party_member_index_) {
        return false;
    }
    for (uint32_t i=0; i<MAX_POISONS; ++i) {
        if (poison_status_[i][index].poison_id==poison_id) {
            return true;
        }
    }
    return false;
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

uint16_t GlobalVars::GetPlayerPoisonResistance(uint16_t player_role) {
    uint16_t w;
    w=g_.player_roles.poison_resistance[player_role];
    for (int32_t i=0; i<=MAX_PLAYER_EQUIPMENTS; ++i) {
        w+=equipment_effect_[i].poison_resistance[player_role];
    }
    if (w>100) {
        w=100;
    }
    return w;
}

uint16_t GlobalVars::GetPlayerElementalResistance(uint16_t player_role, int32_t attrib) {
    uint16_t w;
    w=g_.player_roles.elemental_resistance[attrib][player_role];
    for (int32_t i=0;i<=MAX_PLAYER_EQUIPMENTS;++i){
        w+=equipment_effect_[i].elemental_resistance[attrib][player_role];
    }
    if (w>100) {
        w=100;
    }
    return w;
}

uint16_t GlobalVars::GetPlayerBattleSprite(uint16_t player_role) {
    uint16_t w;
    w=g_.player_roles.sprite_num_in_battle[player_role];
    for (int32_t i=0; i<=MAX_PLAYER_EQUIPMENTS; ++i) {
        if (equipment_effect_[i].sprite_num_in_battle[player_role]!=0) {
            w=equipment_effect_[i].sprite_num_in_battle[player_role];
        }
    }
    return w;
}

uint16_t GlobalVars::GetPlayerCooperativeMagic(uint16_t player_role) {
    uint16_t w;
    w=g_.player_roles.cooperative_magic[player_role];
    for (uint32_t i=0; i<=MAX_PLAYER_EQUIPMENTS; ++i) {
        if (equipment_effect_[i].cooperative_magic[player_role]!=0) {
            w=equipment_effect_[i].cooperative_magic[player_role];
        }
    }
    return w;
}

bool GlobalVars::CanPlayerAttackAll(uint16_t player_role) {
    bool f;
    f=false;
    for (uint32_t i=0; i<=MAX_PLAYER_EQUIPMENTS; ++i) {
        if (equipment_effect_[i].attack_all[player_role]!=0) {
            f=true;break;
        }
    }
    return f;
}

bool GlobalVars::AddMagic(uint16_t player_role, uint16_t magic) {
    int32_t i;
    //遍历目标角色的技能池
    for (i=0; i<MAX_PLAYER_MAGICS; ++i) {
        if (g_.player_roles.magic[i][player_role]==magic) {
            //已学会目标技能
            return false;
        }
    }
    //查找空技能槽
    for (i=0; i<MAX_PLAYER_MAGICS; ++i) {
        if (g_.player_roles.magic[i][player_role]==0) {
            break;
        }
    }
    if (i>=MAX_PLAYER_MAGICS) {
        return false;
    }
    g_.player_roles.magic[i][player_role]=magic;
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
    bool f;
    f=true;
    auto wStatus=static_cast<CharaStatus>(status_id);
#ifndef PAL_CLASSIC
    if (wStatus==CharaStatus::kSlow&&player_status_[player_role][static_cast<uint16_t>(CharaStatus::kHaste)]>0) {
        RemovePlayerStatus(player_role, static_cast<uint16_t>(CharaStatus::kHaste));
        return false;
    }
    if (wStatus==CharaStatus::kHaste&&player_status_[player_role][static_cast<uint16_t>(CharaStatus::kSlow)]>0) {
        RemovePlayerStatus(player_role, static_cast<uint16_t>(CharaStatus::kSlow));
        return false;
    }
#endif
    
    switch (wStatus){
    case CharaStatus::kConfused:
    case CharaStatus::kSleep:
    case CharaStatus::kSilence:
#ifdef PAL_CLASSIC
    case CharaStatus::kParalyzed:
#else
    case CharaStatus::kSlow:
#endif
        // 负面状态不重复设置
        if (player_status_[player_role][status_id]==0) {
            player_status_[player_role][status_id]=num_round;
        }
        break;
    case CharaStatus::kPuppet:
        //仅死亡状态角色可设置该状态
        if (g_.player_roles.hp[player_role]==0) {
            if (player_status_[player_role][status_id]<num_round) {
                player_status_[player_role][status_id]=num_round;
            }
        }else{
            f=false;
        }
        break;
    case CharaStatus::kBravery:
    case CharaStatus::kProtect:
    case CharaStatus::kHaste:
    case CharaStatus::kDualAttack:
            if (g_.player_roles.hp[player_role]!=0&&player_status_[player_role][status_id]<num_round) {
                player_status_[player_role][status_id]=num_round;
            }
        break;
    default:
        assert(false);
        break;
    }
    return f;
}

/**
 * 移除目标任务的指定状态
 * @param player_role
 * @param status_id
 */
void GlobalVars::RemovePlayerStatus(uint16_t player_role, uint16_t status_id) {
    //检查效果类型（不移除装备效果）
    if (player_status_[player_role][status_id]<=999) {
        player_status_[player_role][status_id]=0;
    }
}

void GlobalVars::ClearAllPlayerStatus() {
    for (uint32_t i=0; i<MAX_PLAYER_ROLES; ++i) {
        for (uint32_t j=0; j<static_cast<uint32_t>(CharaStatus::kAll    ); ++j) {
            if (player_status_[i][j]) {
                player_status_[i][j]=0;
            }
        }
    }
}

void GlobalVars::PlayerLevelUp(uint16_t player_role, uint16_t num_level) {
    uint16_t i;
    //添加角色等级
    g_.player_roles.level[player_role]+=num_level;
    if (g_.player_roles.level[player_role]>MAX_LEVELS) {
        g_.player_roles.level[player_role]=MAX_LEVELS;
    }
    
    //依照提升等级数提高属性值
    for (i=0; i<num_level; ++i) {
        g_.player_roles.max_hp[player_role]+=10+MathUtil::RandomLong(0, 7);
        g_.player_roles.max_mp[player_role]+=8+MathUtil::RandomLong(0, 5);
        g_.player_roles.attack_strength[player_role]+=4+MathUtil::RandomLong(0, 1);
        g_.player_roles.magic_strength[player_role]+=4+MathUtil::RandomLong(0, 1);
        g_.player_roles.defence[player_role]+=2+MathUtil::RandomLong(0, 1);
        g_.player_roles.dexterity[player_role]+=2+MathUtil::RandomLong(0, 1);
        g_.player_roles.flee_rate[player_role]+=2;
    }
    
#define STAT_LIMIT(t){if((t)>999) (t)=999;}
    STAT_LIMIT(g_.player_roles.max_hp[player_role]);
    STAT_LIMIT(g_.player_roles.max_mp[player_role]);
    STAT_LIMIT(g_.player_roles.attack_strength[player_role] );
    STAT_LIMIT(g_.player_roles.magic_strength[player_role]);
    STAT_LIMIT(g_.player_roles.defence[player_role]);
    STAT_LIMIT(g_.player_roles.dexterity[player_role]);
    STAT_LIMIT(g_.player_roles.flee_rate[player_role    ]);
#undef STAT_LIMIT
    
    exp_.primary_exp[player_role].exp=0;
    exp_.primary_exp[player_role].level=g_.player_roles.level[player_role];
}