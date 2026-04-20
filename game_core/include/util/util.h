//
// Created on 2026/4/19.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef PAL_OHOS_UTIL_H
#define PAL_OHOS_UTIL_H

#include "util/common.h"
#include <rawfile/raw_file_manager.h>

class UTIL {
public:
    static RawFile* openRequiredFile(const char *lpsz_file_name);
    static void closeFile(RawFile* fp);
private:
    static RawFile*openRequiredFileForMode(const char *lpsz_file_name,const NativeResourceManager*mgr);
};


#endif // PAL_OHOS_UTIL_H
