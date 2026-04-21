//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_MAGIC_FLAG_H
#define pal_ohos_MAGIC_FLAG_H

/**
 * 法术特性标签
 */
enum class MagicFlag {
    kUsableOutSideBattle = (1 << 0),
    kUsableInBattle = (1 << 1),
    kUsableToEnemy = (1 << 3),
    kApplyToAll = (1 << 4)
};

#endif // pal_ohos_MAGIC_FLAG_H
