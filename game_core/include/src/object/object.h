//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_OBJECT_H
#define pal_ohos_OBJECT_H

#include "structures/object_enemy.h"
#include "structures/object_item.h"
#include "structures/object_magic.h"
#include "structures/object_player.h"
#include "structures/object_poison.h"
#include "util/common.h"

typedef union ObjectDos {
    WORD data[6];
    OBJECT_PLAYER player_;
    OBJECT_ITEM_DOS item_;
    OBJECT_MAGIC_DOS magic_;
    OBJECT_ENEMY enemy_;
    OBJECT_POISON poison_;
} OBJECT_DOS, *LPOBJECT_DOS;

typedef union Object {
    WORD data[7];
    OBJECT_PLAYER player_;
    OBJECT_ITEM item_;
    OBJECT_MAGIC magic_;
    OBJECT_ENEMY enemy_;
    OBJECT_POISON poison_;
} OBJECT, *LPOBJECT;

#endif // pal_ohos_OBJECT_H
