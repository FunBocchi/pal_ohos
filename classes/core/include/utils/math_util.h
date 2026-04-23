//
// Created on 2026/4/23.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef PAL_OHOS_MATH_UTIL_H
#define PAL_OHOS_MATH_UTIL_H

#include <cstdint>
class MathUtil{
public:
    static int32_t RandomLong(int32_t from,int32_t to);
};

#endif //PAL_OHOS_MATH_UTIL_H
