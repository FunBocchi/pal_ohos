//
// Created on 2026/4/11.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "xcomponent_bridge_registry.h"
#include "log_common.h"

XComponentBridgeRegistry *XComponentBridgeRegistry::getInstance() {
    static XComponentBridgeRegistry instance;
    return &instance;
}

XComponentBridgeRegistry::~XComponentBridgeRegistry() {
    SAMPLE_LOGI("~XComponentBridgeRegistry");
    for (auto iter = native_xcomponent_map_.begin(); iter != native_xcomponent_map_.end(); ++iter) {
        if (iter->second != nullptr) {
            delete iter->second;
            iter->second = nullptr;
        }
    }
    native_xcomponent_map_.clear();

    for (auto iter = render_map_.begin(); iter != render_map_.end(); ++iter) {
        if (iter->second != nullptr) {
            delete iter->second;
            iter->second = nullptr;
        }
    }
    render_map_.clear();
}

void XComponentBridgeRegistry::exportNapi(napi_env env, napi_value exports) {
    native_xcomponent_map_.clear();
    render_map_.clear();

    if ((env == nullptr) || (exports == nullptr)) {
        SAMPLE_LOGE("ExportNapi: env or exports is null");
        return;
    }

    napi_value export_instance = nullptr;
    if (napi_get_named_property(env, exports, OH_NATIVE_XCOMPONENT_OBJ, &export_instance) != napi_ok) {
        SAMPLE_LOGE("ExportNapi: napi_get_named_property fail");
        return;
    }

    OH_NativeXComponent *native_xcomponent = nullptr;
    if (napi_unwrap(env, export_instance, reinterpret_cast<void **>(&native_xcomponent)) != napi_ok) {
        SAMPLE_LOGE("ExportNapi: napi_unwrap fail");
        return;
    }

    char id_str[OH_XCOMPONENT_ID_LEN_MAX + 1] = {'\0'};
    uint64_t id_size = OH_XCOMPONENT_ID_LEN_MAX + 1;
    if (OH_NativeXComponent_GetXComponentId(native_xcomponent, id_str, &id_size) !=
        OH_NATIVEXCOMPONENT_RESULT_SUCCESS) {
        SAMPLE_LOGE("ExportNapi: OH_NativeXComponent_GetXComponentId fail");
        return;
    }

    std::string id(id_str);
    auto context = XComponentBridgeRegistry::getInstance();
    if ((context != nullptr) && (native_xcomponent != nullptr)) {
        context->setNativeXComponent(id, native_xcomponent);
        auto render = context->getRender(id);
        if (render != nullptr) {
            render->registerCallback(native_xcomponent);
            render->exportNapi(env, exports);
            return;
        } else {
            SAMPLE_LOGE("Render is nullptr");
            return;
        }
    }
}