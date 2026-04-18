//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_PLAYER_ATTRIBUTE_CALCULATOR_H
#define pal_ohos_PLAYER_ATTRIBUTE_CALCULATOR_H

#include "util/common.h"

class PlayerAttributeCalculator {
public:
    static uint16_t getAttackStrength(uint16_t player_role);
    static uint16_t getMagicStrength(uint16_t player_role);
    static uint16_t getDefence(uint16_t player_role);
    static uint16_t getDexterity(uint16_t player_role);
    static uint16_t getFleeRate(uint16_t player_role);
    static uint16_t getPoisonResistance(uint16_t player_role);

    static uint16_t getBattleSprite(uint16_t player_role);
    static uint16_t getCooperativeMagic(uint16_t player_role);
    static bool canAttackAll(uint16_t player_role);
};

#endif // pal_ohos_PLAYER_ATTRIBUTE_CALCULATOR_H
