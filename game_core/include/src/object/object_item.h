//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_OBJECT_ITEM_H
#define pal_ohos_OBJECT_ITEM_H

#include "util/common.h"

// 物品（原版）
typedef struct ObjectItemDos {
    WORD bitmap_; // 在BALL.MKF中对应的bitmap序号
    WORD price_;
    WORD script_on_use_;   // 使用时触发的脚本
    WORD script_on_equip_; // 装备时触发的脚本
    WORD script_on_throw_; // 丢弃时触发的脚本
    WORD flags_;
} OBJECT_ITEM_DOS;

// 物品（增强）
typedef struct ObjectItem {
    WORD bitmap_; // 在BALL.MKF中对应的bitmap序号
    WORD price_;
    WORD script_on_use_;   // 使用时触发的脚本
    WORD script_on_equip_; // 装备时触发的脚本
    WORD script_on_throw_; // 丢弃时触发的脚本
    WORD script_desc_;
    WORD flags_;
} OBJECT_ITEM;

#endif // pal_ohos_OBJECT_ITEM_H
