//
// Created on 2026/4/11.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_XCOMPONENT_BRIDGE_REGISTRY_H
#define pal_ohos_XCOMPONENT_BRIDGE_REGISTRY_H

#include "native_game_bridge.h"
#include <ace/xcomponent/native_interface_xcomponent.h>
#include <js_native_api.h>
#include <js_native_api_types.h>
#include <string>

class XComponentBridgeRegistry {
public:
    ~XComponentBridgeRegistry();

    static XComponentBridgeRegistry *getInstance();

    void setNativeXComponent(std::string &id, OH_NativeXComponent *native_xcomponent);

    NativeGameBridge *getRender(std::string &id);

    void exportNapi(napi_env env, napi_value exports);

private:
    std::unordered_map<std::string, OH_NativeXComponent *> native_xcomponent_map_;
    std::unordered_map<std::string, NativeGameBridge *> render_map_;
};

#endif // pal_ohos_XCOMPONENT_BRIDGE_REGISTRY_H
