//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "src/game_resource_loader.h"
#include "src/ui/ui.h"
#include "util/util.h"
#include <cstdint>

GameResourceLoader *GameResourceLoader::getInstance() {
    static GameResourceLoader instance;
    return &instance;
}


bool GameResourceLoader::initGlobals() {
    // 分配内存空间
    if (globals_ == nullptr) {
        // 分配内存区域并进行初始化
        globals_ = new GlobalVars();
        if (globals_ == nullptr) {
        //分配内存空间失败返回
            return false;
        }
    }
    /**
     * 此处作用将指针指向打开的文件位置
     */
    globals_->f.FBP = UTIL::openRequiredFile("FBP.MKF");
    globals_->f.MGO = UTIL::openRequiredFile("MGO.MKF");
    globals_->f.BALL = UTIL::openRequiredFile("BALL.MKF");
    globals_->f.DATA = UTIL::openRequiredFile("DATA.MKF");
    globals_->f.F = UTIL::openRequiredFile("F.MKF");
    globals_->f.FIRE = UTIL::openRequiredFile("FIRE.MKF");
    globals_->f.RGM = UTIL::openRequiredFile("RGM.MKF");
    globals_->f.SSS = UTIL::openRequiredFile("SSS.MKF");
    
    globals_->lp_object_desc_=UI::loadObjectDesc("desc.dat");
    /**
     * 获取游戏资源版本
     */

    /**
     * 当资源为WIN95版本时，应用AVI Playing
     */

    /**
     * 当面没有特定信息文件时检测游戏语言
     */

    /**
     * 设置解压函数
     */

    /**
     * 设置存档序号
     */
    globals_->current_save_slot_ = 1;

    return true;
}

void GameResourceLoader::freeGlobals() {
    /**
     * 关闭打开的文件
     */
    UTIL::closeFile(globals_->f.FBP);
    UTIL::closeFile(globals_->f.MGO);
    UTIL::closeFile(globals_->f.BALL);
    UTIL::closeFile(globals_->f.DATA);
    UTIL::closeFile(globals_->f.F);
    UTIL::closeFile(globals_->f.FIRE);
    UTIL::closeFile(globals_->f.RGM);
    UTIL::closeFile(globals_->f.SSS);
    /**
     * 释放游戏数据
     */
    free(globals_->g.lp_event_object_);
    free(globals_->g.lp_script_entry_);
    free(globals_->g.lp_store_);
    free(globals_->g.lp_enemy_);
    free(globals_->g.lp_enemy_team_);
    free(globals_->g.lp_magic_);
    free(globals_->g.lp_battle_field_);
    free(globals_->g.lp_levelup_magic_);
}

/**
 * 从文件中读取游戏数据
 */
void GameResourceLoader::readGlobalGameData() { const GameData *p = &globals_->g;}

/**
 * 初始化游戏数据
 */
void GameResourceLoader::initGlobalGameData() {  }

/**
 * 加载默认游戏数据
 */
void GameResourceLoader::loadDefaultGame() { GameData*p=&globals_->g;uint32_t i;

globals_->entering_scene_=true;}