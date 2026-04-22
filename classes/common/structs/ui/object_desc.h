//
// Created on 2026/4/20.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef PAL_OHOS_OBJECT_DESC_H
#define PAL_OHOS_OBJECT_DESC_H

#include <cstdint>
struct ObjectDesc{
    uint16_t object_id_;
    int8_t* lp_desc_;
    ObjectDesc*next;
};

#endif //PAL_OHOS_OBJECT_DESC_H
