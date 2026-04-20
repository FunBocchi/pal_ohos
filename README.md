### 简简简简述

本项目基于palsdl、pal-harmony等修改而来，目前处于新建文件夹阶段

#### 备忘录

项目中采用同字节大小的类型进行相互的转换使用，通常为unsigned short及short等两字节为元的类型

当前优化保留了这一特性，并考虑加入转换来提高代码的可读性


#### 目录结构
```
pal_ohos/
├── classes/
│   ├── CMakeLists.txt
│   ├── include/
│   │   ├── src/
│   │   ├── bridge/
│   │   ├── engine/
│   │   └── util/
│   ├── src/
│   ├── bridge/
│   │   ├── CMakeLists.txt
│   │   ├── XComponentBridgeRegistry.cpp
│   │   ├── XComponentBridgeRegistry.h
│   │   ├── GameEngineBridge.cpp
│   │   └── GameEngineBridge.h
│   ├── engine/
│   │   ├── CMakeLists.txt
│   │   ├── battle.cpp
│   │   ├── script.cpp
│   │   ├── map.cpp
│   │   └── include/
│   │       ├── battle.h
│   │       ├── script.h
│   │       └── map.h
│   └── util/
│       ├── CMakeLists.txt
│       ├── util.cpp
│       └── include/
│           └── util.h
│
├── product/
│   └── laptop/
│       └── src/main/cpp/
│           ├── CMakeLists.txt
│           └── napi_init.cpp
│
└── CMakeLists.txt
```