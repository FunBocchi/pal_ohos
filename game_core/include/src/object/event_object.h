//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_EVENT_OBJECT_H
#define pal_ohos_EVENT_OBJECT_H

#include "../../enums/object_state.h"
#include "enums/triggle_mode.h"
#include <cstdint>

// 对象包括系统字符串、玩家、物品、魔法、敌人和毒药脚本
// 事件对象，地图上的交互元素
// 后续优化考虑对源文件读取及生成类型进行单独划分
struct EventObject {
    int16_t vanish_time;
    uint16_t x;
    uint16_t y;
    int16_t layer;
    uint16_t trigger_script;
    uint16_t auto_script;
    ObjectState state;       // 当前元素所处状态，对应SHORT类型
    TriggerMode trigger_mode; // 触发方式，对应WORD类型，使用对应的枚举类型替代
    uint16_t sprite_num;
    uint16_t sprite_frames;
    uint16_t direction;
    uint16_t current_frame_num;
    uint16_t script_idle_frame;
    uint16_t sprite_ptr_offset;
    uint16_t sprite_frames_auto;
    uint16_t script_idle_frame_count_auto;
};

#endif // pal_ohos_EVENT_OBJECT_H
