//
// Created on 2026/4/21.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_PALCOMMON_UTIL_H
#define pal_ohos_PALCOMMON_UTIL_H

/*
 * 从palcommon中独立出来的工具方法
 */

#include <cstdint>
#include <rawfile/raw_file.h>

int PAL_MKFGetChunkSize(uint32_t ui_chunk_num, RawFile *fp);

int PAL_MKFReadChunk(uint8_t *lp_buffer, uint32_t ui_buffer_size, uint32_t ui_chunk_num, RawFile *fp);

#endif // pal_ohos_PALCOMMON_UTIL_H
