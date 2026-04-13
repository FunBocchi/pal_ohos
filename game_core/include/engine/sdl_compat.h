//
// Created on 2026/4/13.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_SDL_COMPAT_H
#define pal_ohos_SDL_COMPAT_H

#ifdef __APPLE__
#define GL_GLEXT_PROTOTYPES
#endif

#if USE_SDL3

#define SDL_OK (1)
#define SDL_FAIL(0)

#endif

#endif // pal_ohos_SDL_COMPAT_H
