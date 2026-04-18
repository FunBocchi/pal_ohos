//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_SCENE_H
#define pal_ohos_SCENE_H

#include "util/common.h"

// 场景
typedef struct Scene {
    WORD map_num_;            // 地图序号
    WORD script_on_enter_;    // 进入当前地图时触发的脚本
    WORD script_on_teleport_; // 从当前地图传送出去的时候触发的脚本
    WORD event_object_index_; // 当前场景涉及的物品，对应索引+1
} SCENE, *LPSCENE;

#endif // pal_ohos_SCENE_H
