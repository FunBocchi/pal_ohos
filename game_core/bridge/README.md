### 简简简简述

本项目基于palsdl、pal-harmony等改进而来，目前处于新建文件夹阶段


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