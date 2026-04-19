//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_GAME_RESOURCE_LOADER_H
#define pal_ohos_GAME_RESOURCE_LOADER_H

#include "src/base/global.h"

// 负责打开MKF文件、分配内存、加在静态游戏数据等功能，即负责实现资源初始化
// 开始游戏时调用initialize()，获取游戏资源数据
// 退出游戏时调用shutdown()，释放资源
class GameResourceLoader {
public:
    // 单例
    static GameResourceLoader *getInstance();
    bool initGlobals(); // 初始化
    void freeGlobals(); // 关闭

    GameResourceLoader() = default;

    // 禁止拷贝和移动
    GameResourceLoader(const GameResourceLoader &) = delete;
    GameResourceLoader &operator=(const GameResourceLoader &) = delete;
    GameResourceLoader(GameResourceLoader &&) = delete;
    GameResourceLoader &operator=(GameResourceLoader &&) = delete;

private:
    void readGlobalGameData(); // 从文件中读取游戏数据
    void initGlobalGameData(); // 初始化游戏数据
    void loadDefaultGame();    // 读取默认游戏数据
    GlobalVars *globals_;
};

#endif // pal_ohos_GAME_RESOURCE_LOADER_H
