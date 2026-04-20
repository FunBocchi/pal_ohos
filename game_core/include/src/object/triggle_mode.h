//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_TRIGGLE_MODE_H
#define pal_ohos_TRIGGLE_MODE_H
#include "util/common.h"

// 地图元素的触发方式
enum class TriggerMode {
    None = 0,
    SearchNear,
    SearchNormal,
    SearchFar,
    TouchNear,
    TouchNormal,
    TouchFar,
    TouchFurther,
    TouchFurthest
};

#endif // pal_ohos_TRIGGLE_MODE_H
