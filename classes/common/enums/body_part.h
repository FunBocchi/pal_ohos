//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_BODY_PART_H
#define pal_ohos_BODY_PART_H

#include "util/common.h"

// 可装备身体部位
// 暂时未确认类型，理论上是2字节类型uint16_t
enum class BodyPart : uint16_t {
    kHead = 0, // 头
    kBody,
    kShoulder,
    kHand,
    kFeet,
    kWear,
    kExtra
};

#endif // pal_ohos_BODY_PART_H
