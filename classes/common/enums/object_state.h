//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_OBJECT_STATE_H
#define pal_ohos_OBJECT_STATE_H

#include "util/common.h"
#include <cstdint>

// 事件对象的状态及触发模式，由EventObject调用
enum class ObjectState : int16_t {
    kHidden = 0, // 隐藏
    kNormal = 1,
    kBlocker = 2
};

#endif // pal_ohos_OBJECT_STATE_H
