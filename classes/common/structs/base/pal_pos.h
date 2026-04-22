//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_PAL_POS_H
#define pal_ohos_PAL_POS_H

#include <cstdint>
/**
 * 用于存储位置的基础坐标类型
 */
struct PalPos {
    uint16_t x;
    uint16_t y;
};

#endif // pal_ohos_PAL_POS_H
