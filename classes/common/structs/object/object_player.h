//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_OBJECT_PLAYER_H
#define pal_ohos_OBJECT_PLAYER_H

#include <array>
// 系统字符串及玩家角色
struct ObjectPlayer {
    std::array<uint16_t, 2> reserved_; // 占位0
    // 进入死亡状态时会触发的脚本，后续考虑修改为函数执政
    uint16_t script_on_friend_death_;
    uint16_t script_on_dying_;
};

#endif // pal_ohos_OBJECT_PLAYER_H
