//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_SCRIPT_ENTRY_H
#define pal_ohos_SCRIPT_ENTRY_H

#include "util/common.h"

typedef struct ScriptEntry {
    WORD operation_;
    WORD rgw_operand_[3];
} SCRIPTENTRY, *LPSCRIPTENTRY;

#endif // pal_ohos_SCRIPT_ENTRY_H
