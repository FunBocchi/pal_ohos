//
// Created on 2026/4/23.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef PAL_OHOS_SCRIPT_H
#define PAL_OHOS_SCRIPT_H

#include <cstdint>
class Script {
public:
    static uint16_t RunTriggerScript(uint16_t script_entry,uint16_t event_object_id);
    static uint16_t RunAutoScript(uint16_t script_entry,uint16_t event_object_id);
};

#endif //PAL_OHOS_SCRIPT_H
