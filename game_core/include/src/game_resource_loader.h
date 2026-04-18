//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_GAME_RESOURCE_LOADER_H
#define pal_ohos_GAME_RESOURCE_LOADER_H

#include "src/base/global.h"

// 负责打开MKF文件、分配内存、加在静态游戏数据等功能，即负责实现资源初始化
//开始游戏时调用initialize()，获取游戏资源数据
//退出游戏时调用shutdown()，释放资源
class GameResourceLoader {
public:
    //单例
    static GameResourceLoader *getInstance();
    void initialize();//初始化
    void shutdown();//关闭

private:
    void readGameData();//读取资源文件
    void freeGameData();//释放资源文件
    LPGLOBALVARS globals_;
};

#endif // pal_ohos_GAME_RESOURCE_LOADER_H
