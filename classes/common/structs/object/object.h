//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_OBJECT_H
#define pal_ohos_OBJECT_H

#include "object_enemy.h"
#include "object_item.h"
#include "object_magic.h"
#include "object_player.h"
#include "object_poison.h"
#include <cstdint>

union ObjectDos {
    uint16_t data[6];
    ObjectPlayer player;
    ObjectItemDos item;
    ObjectMagicDOS magic;
    ObjectEnemy enemy;
    ObjectPoison poison;
};

union Object {
    uint16_t data[7];
    ObjectPlayer player;
    ObjectItem item;
    ObjectMagic magic;
    ObjectEnemy enemy;
    ObjectPoison poison;
};

#endif // pal_ohos_OBJECT_H
