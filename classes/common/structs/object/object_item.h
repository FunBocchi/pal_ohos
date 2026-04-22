//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_OBJECT_ITEM_H
#define pal_ohos_OBJECT_ITEM_H

#include <cstdint>
// 物品（原版）
struct ObjectItemDos {
    uint16_t bitmap_; // 在BALL.MKF中对应的bitmap序号
    uint16_t price_;
    uint16_t script_on_use_;   // 使用时触发的脚本
    uint16_t script_on_equip_; // 装备时触发的脚本
    uint16_t script_on_throw_; // 丢弃时触发的脚本
    uint16_t flags_;
};

// 物品（增强）
struct ObjectItem {
    uint16_t bitmap_; // 在BALL.MKF中对应的bitmap序号
    uint16_t price_;
    uint16_t script_on_use_;   // 使用时触发的脚本
    uint16_t script_on_equip_; // 装备时触发的脚本
    uint16_t script_on_throw_; // 丢弃时触发的脚本
    uint16_t script_desc_;
    uint16_t flags_;
};

#endif // pal_ohos_OBJECT_ITEM_H
