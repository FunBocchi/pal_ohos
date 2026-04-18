//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_FILES_H
#define pal_ohos_FILES_H

#include "util/common.h"

// 用于存储游戏资源文件，在游戏运行期间会保持打开直至退出时被关闭
// 使用RawFile类型代替原版FILE，以适配鸿蒙系统NDK
typedef struct Files {
    LPRAWFILE FBP;  // 战斗背景_FBP.MKF
    LPRAWFILE MGO;  // 场景精灵图_MGO.MKF
    LPRAWFILE BALL; // 物品位图_BALL.MKF
    LPRAWFILE DATA; // 综合数据文件_DATA.MKF
    LPRAWFILE F;    // 战斗精灵图_F.MKF
    LPRAWFILE FIRE; // 特效精灵图_FIRE.MKF
    LPRAWFILE RGM;  // 角色头像_RGM.MKF
    LPRAWFILE SSS;  // 脚本数据_SSS.MKF
} FILES, *LPFILES;

#endif //pal_ohos_FILES_H
