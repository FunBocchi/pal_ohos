//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_GAME_RESOURCE_LOADER_H
#define pal_ohos_GAME_RESOURCE_LOADER_H

#include "global.h"

// 负责打开MKF文件、分配内存、加在静态游戏数据等功能，即负责实现资源初始化
class GameResourceLoader {
public:
    static GameResourceLoader *getInstance();
    void initialize();
    void free();

private:
    void readGameData();
    void initGameData();
    LPGLOBALVARS globals_;
};

#endif // pal_ohos_GAME_RESOURCE_LOADER_H
