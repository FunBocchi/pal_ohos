//
// Created on 2026/4/11.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_NATIVE_GAME_BRIDGE_H
#define pal_ohos_NATIVE_GAME_BRIDGE_H

#include <ace/xcomponent/native_interface_xcomponent.h>
#include <napi/native_api.h>
#include <native_drawing/drawing_bitmap.h>
#include <native_drawing/drawing_canvas.h>
#include <native_window/external_window.h>
#include <string>

class NativeGameBridge {
public:
    NativeGameBridge() = default;
    ~NativeGameBridge();

    explicit NativeGameBridge(std::string id) : id_(id) {}
    static napi_value napiRegister(napi_env env, napi_callback_info info);
    static napi_value napiUnregister(napi_env env, napi_callback_info info);
    static napi_value napiInput(napi_env env, napi_callback_info info);
    static void release(std::string &id);
    void drawPath();
    void setWidth(uint64_t width);
    void setHeight(uint64_t height);
    void setNativeWindow(OHNativeWindow *native_window);
    OHNativeWindow *getNativeWindow();
    uint64_t getWidth() { return width_; }
    uint64_t getHeight() { return height_; }
    void prepare();
    void create();
    void display();
    void constructPath(int x, int y, int offset_y);
    void setPenBrush();
    void exportNapi(napi_env env, napi_value exports);
    void registerCallback(OH_NativeXComponent *native_xcomponent);
    void registerOnFrameCallback(OH_NativeXComponent *native_xcomponent);
    void destroy();
    static NativeGameBridge *getInstance(std::string &id);

    std::string id_;
    int default_offsetY_ = 200;

private:
    OH_NativeXComponent_Callback render_callback_;

    uint64_t width_ = 0;
    uint64_t height_ = 0;

    float aX = 0.0;
    float aY = 0.0;
    float bX = 80.0;
    float cY = 0.0;

    bool desc = false;

    OH_Drawing_Bitmap *c_bitmap_ = nullptr;
    OH_Drawing_Canvas *c_canvas_ = nullptr;

    OHNativeWindow *native_window_ = nullptr;
    uint32_t *mapped_addr_ = nullptr;
    BufferHandle *buffer_handle_ = nullptr;
    struct NativeWindowBuffer *buffer_ = nullptr;
    int fence_fd_ = 0;
};

#endif // pal_ohos_NATIVE_GAME_BRIDGE_H
