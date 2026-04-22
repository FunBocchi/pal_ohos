//
// Created on 2026/4/23.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef PAL_OHOS_MKF_READER_H
#define PAL_OHOS_MKF_READER_H

#include <cstdint>
#include <rawfile/raw_file.h>
class MKFUtil {
public:
    static RawFile *OpenRequiredFile(const char *file_name);
};

#endif // PAL_OHOS_MKF_READER_H
