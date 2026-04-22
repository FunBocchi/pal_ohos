//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_FILES_H
#define pal_ohos_FILES_H

#include <rawfile/raw_file.h>

// 用于存储游戏资源文件，在游戏运行期间会保持打开直至退出时被关闭
// 使用RawFile类型代替原版FILE，以适配鸿蒙系统NDK
struct Files {
    RawFile* FBP;  // 战斗背景_FBP.MKF
    RawFile* MGO;  // 场景精灵图_MGO.MKF
    RawFile* BALL; // 物品位图_BALL.MKF
    RawFile* DATA; // 综合数据文件_DATA.MKF
    RawFile* F;    // 战斗精灵图_F.MKF
    RawFile* FIRE; // 特效精灵图_FIRE.MKF
    RawFile* RGM;  // 角色头像_RGM.MKF
    RawFile* SSS;  // 脚本数据_SSS.MKF
};

#endif //pal_ohos_FILES_H
