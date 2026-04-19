//
// Created on 2026/4/19.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "util/util.h"
#include "rawfile/raw_file_manager.h"
#include "rawfile/raw_file.h"

LPRAWFILE UTIL::openRequiredFile(const char *lpsz_file_name) {
    RawFile *fp;
    /**
     * 使用OH_ResourceManager_OpenRawFile函数获取对应名称的文件资源；
     */
    NativeResourceManager*mgr;
    OH_ResourceManager_OpenRawDir(mgr,lpsz_file_name);
}