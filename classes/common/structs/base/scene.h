//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_SCENE_H
#define pal_ohos_SCENE_H

#include <cstdint>
/**
 * 场景
 */
struct Scene {
    uint16_t map_num;            // 地图序号
    uint16_t script_on_enter;    // 进入当前地图时触发的脚本
    uint16_t script_on_teleport; // 从当前地图传送出去的时候触发的脚本
    uint16_t event_object_index; // 当前场景涉及的物品，对应索引+1
};

#endif // pal_ohos_SCENE_H
