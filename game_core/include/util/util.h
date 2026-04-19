//
// Created on 2026/4/19.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef PAL_OHOS_UTIL_H
#define PAL_OHOS_UTIL_H

#include "util/common.h"

class UTIL {
public:
    static LPRAWFILE openRequiredFile(const char *lpsz_file_name);
    static void closeFile(LPRAWFILE fp);
};


#endif // PAL_OHOS_UTIL_H
