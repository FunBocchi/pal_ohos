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
    int countItem(uint16_t object_id);
    int getItemAmount(uint16_t item);
    int addItem(uint16_t object_id, int num);
    void compressInventory();

private:
    bool getItemIndex(uint16_t object_id, int *num) const;
};

#endif // pal_ohos_INVENTORY_MANAGER_H
