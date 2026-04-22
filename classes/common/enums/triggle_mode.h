//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_TRIGGLE_MODE_H
#define pal_ohos_TRIGGLE_MODE_H

#include <cstdint>

// 地图元素的触发方式
enum class TriggerMode:uint16_t {
    None = 0,
    SearchNear=1,
    SearchNormal=2,
    SearchFar=3,
    TouchNear=4,
    TouchNormal=5,
    TouchFar=6,
    TouchFurther=7,
    TouchFurthest=8
};

#endif // pal_ohos_TRIGGLE_MODE_H
