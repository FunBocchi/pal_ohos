//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_EVENT_OBJECT_H
#define pal_ohos_EVENT_OBJECT_H

#include "util/common.h"
#include "src/object/triggle_mode.h"

// 对象包括系统字符串、玩家、物品、魔法、敌人和毒药脚本
// 事件对象，地图上的交互元素
// 后续优化考虑对源文件读取及生成类型进行单独划分
struct EventObjectRaw {
    SHORT vanish_time_;
    WORD x_;
    WORD y_;
    SHORT layer_;
    WORD trigger_script_;
    WORD auto_script_;
    SHORT state_;       // 当前元素所处状态，对应SHORT类型
    WORD trigger_mode_; // 触发方式，对应WORD类型
    WORD sprite_num_;
    USHORT sprite_frames_;
    WORD direction_;
    WORD current_frame_num_;
    USHORT script_idle_frame_;
    WORD sprite_ptr_offset_;
    USHORT sprite_frames_auto_;
    WORD script_idle_frame_count_auto_;
};
// 使用上述结构体读取二进制文件代码后转换到下方可被使用的类型
typedef struct EventObject {
    SHORT vanish_time_;
    WORD x_;
    WORD y_;
    SHORT layer_;
    WORD trigger_script_;
    WORD auto_script_;
    SHORT state_;       // 当前元素所处状态，对应SHORT类型
    TRIGGERMODE trigger_mode_; // 触发方式，对应WORD类型，使用对应的枚举类型替代
    WORD sprite_num_;
    USHORT sprite_frames_;
    WORD direction_;
    WORD current_frame_num_;
    USHORT script_idle_frame_;
    WORD sprite_ptr_offset_;
    USHORT sprite_frames_auto_;
    WORD script_idle_frame_count_auto_;
} EVENTOBJECT, *LPEVENTOBJECT;

#endif // pal_ohos_EVENT_OBJECT_H
