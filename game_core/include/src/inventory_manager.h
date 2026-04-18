//
// Created on 2026/4/18.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_INVENTORY_MANAGER_H
#define pal_ohos_INVENTORY_MANAGER_H

#include "util/common.h"

class InventoryManager {
public:
    int countItem(uint16_t object_id);        // 计算物品数量
    int getItemAmount(uint16_t item);         // 获取物品总数
    int addItem(uint16_t object_id, int num); // 添加物品
    void compressInventory();                 // 清理背包中的空槽位，并将物品向前排列到数组前端

private:
    bool getItemIndex(uint16_t object_id, int *num) const; // 获取物品索引
};

#endif // pal_ohos_INVENTORY_MANAGER_H
