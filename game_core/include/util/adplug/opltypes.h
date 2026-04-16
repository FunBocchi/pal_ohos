//
// Created on 2026/4/13.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#ifndef pal_ohos_OPLTYPES_H
#define pal_ohos_OPLTYPES_H

typedef enum _OPLCORE_TYPE {
    OPLCORE_MAME,
    OPLCORE_DBFLT,
    OPLCORE_DBINT,
    OPLCORE_NUKED,
} OPLCORE_TYPE;

typedef enum _OPLCHIP_TYPE {
    OPLCHIP_OPL2,
    OPLCHIP_OPL3,

    OPLCHIP_DUAL_OPL2,
} OPLCHIP_TYPE;

#define OPL3_EXTREG_BASE 0x100
#define OPL3_4OP_REGISTER 0x104
#define OPL3_MODE_REGISTER 0x105

#endif // pal_ohos_OPLTYPES_H
