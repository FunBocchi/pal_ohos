//
// Created on 2026/4/21.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "src/base/global.h"
#include "util/util.h"

bool GlobalVars::initGlobals() {
    f_.FBP=UTIL::openRequiredFile("FBP.MKF");
    f_.MGO=UTIL::openRequiredFile("MGO.MKF");
    f_.BALL=UTIL::openRequiredFile("BALL.MKF");
    
    f_.DATA=UTIL::openRequiredFile("DATA.MKF");
    
    f_.F=UTIL::openRequiredFile("F.MKF");
    f_.FIRE=UTIL::openRequiredFile("FIRE.MKF");
    
    f_.RGM=UTIL::openRequiredFile("RGM.MKF");
    f_.SSS=UTIL::openRequiredFile("SSS.MKF");
}