//
// Created on 2026/4/20.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef PAL_OHOS_UI_H
#define PAL_OHOS_UI_H

#include "object_desc.h"
class UI {
public:
    static ObjectDesc *loadObjectDesc(const char *file_name);
};

#endif // PAL_OHOS_UI_H
