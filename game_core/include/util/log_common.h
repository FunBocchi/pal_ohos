//
// Created on 2026/4/11.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_LOG_COMMON_H
#define pal_ohos_LOG_COMMON_H

#include <hilog/log.h>

#define LOG_PRINT_DOMAIN 0xFF00
#define APP_LOG_DOMAIN 0x0001

constexpr const char *APP_LOG_TAG = "PAL_OHOS";

#define SAMPLE_LOGI(...) ((void)OH_LOG_Print(LOG_APP, LOG_INFO, LOG_DOMAIN, APP_LOG_TAG, __VA_ARGS__))
#define SAMPLE_LOGD(...) ((void)OH_LOG_Print(LOG_APP, LOG_DEBUG, LOG_DOMAIN, APP_LOG_TAG, __VA_ARGS__))
#define SAMPLE_LOGW(...) ((void)OH_LOG_Print(LOG_APP, LOG_WARN, LOG_DOMAIN, APP_LOG_TAG, __VA_ARGS__))
#define SAMPLE_LOGE(...) ((void)OH_LOG_Print(LOG_APP, LOG_ERROR, LOG_DOMAIN, APP_LOG_TAG, __VA_ARGS__))

#endif // pal_ohos_LOG_COMMON_H
