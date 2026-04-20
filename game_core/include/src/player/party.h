//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_PARTY_H
#define pal_ohos_PARTY_H

#include "util/common.h"

// 玩家队伍成员
struct Party {
    uint16_t player_role_;  // 角色编号-对应角色数据表中的索引
    int16_t x_, y_;       // 地图坐标
    uint16_t frame_;        // 动画帧号-当前播放动画的帧索引
    uint16_t image_offset_; // 图像偏移量
};

#endif // pal_ohos_PARTY_H
