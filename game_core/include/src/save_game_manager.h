//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

// 负责存档的保存和加载

#ifndef pal_ohos_SAVE_GAME_MANAGER_H
#define pal_ohos_SAVE_GAME_MANAGER_H

#include "util/common.h"

class SaveGameManager {
public:
    void saveGame(int save_slot, uint16_t saved_times); // 存档
    void initGameData(int save_slot);                   // 读取
    void reloadInNextTick(int save_slot);               // 在下一帧重加载

private:
    enum class SaveFormat { DOS, WIN95 };
    bool loadGame(int save_slot, SaveFormat format);
    void loadDefaultGame();
};

#endif // pal_ohos_SAVE_GAME_MANAGER_H
