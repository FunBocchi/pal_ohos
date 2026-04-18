//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_PLAYER_ATTRIBUTE_CALCULATOR_H
#define pal_ohos_PLAYER_ATTRIBUTE_CALCULATOR_H

#include "util/common.h"

// 用于获取角色的属性数据以及一些相关的内容
class PlayerAttributeCalculator {
public:
    static uint16_t getAttackStrength(uint16_t player_role);   // 物攻
    static uint16_t getMagicStrength(uint16_t player_role);    // 法强
    static uint16_t getDefence(uint16_t player_role);          // 综合防御
    static uint16_t getDexterity(uint16_t player_role);        // 敏捷
    static uint16_t getFleeRate(uint16_t player_role);         // 逃跑概率
    static uint16_t getPoisonResistance(uint16_t player_role); // 毒抗性
    static uint16_t getElementalResistance(uint16_t player_role, int attrib);

    static uint16_t getBattleSprite(uint16_t player_role);
    static uint16_t getCooperativeMagic(uint16_t player_role);
    
    static bool canPlayerAttackAll(uint16_t player_role);
};

#endif // pal_ohos_PLAYER_ATTRIBUTE_CALCULATOR_H
