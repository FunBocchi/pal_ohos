#创建一个Object库
add_library(core_bridge
    OBJECT
    bridge.cpp
)

#添加头文件路径
target_include_directories(core_bridge
    PRIVATE
    ${CLASSES_ROOT}/core/include
    ${CLASSES_ROOT}/common
)

#将这个OBJECT目标添加到全局列表中
set(GAME_CORE_OBJECT_LIBS ${GAME_CORE_OBJECT_LIBS} core_bridge CACHE INTERNAL "")