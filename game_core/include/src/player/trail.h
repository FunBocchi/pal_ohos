//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_TRAIL_H
#define pal_ohos_TRAIL_H

#include <cstdint>

// 队员跟随轨迹，用于让后排队员按前排队友的路径跟随移动
struct Trail {
    uint16_t x_, y_;     // 历史位置坐标
    uint16_t direction_; // 移动方向-指示当前位置的角色朝向
};

#endif // pal_ohos_TRAIL_H
