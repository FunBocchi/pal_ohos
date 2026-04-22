cmake_minimum_required(VERSION 3.5.0)
project(classes)

# 定义Classes根路径，方便下层模块引用
set(CLASSES_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

# 添加 common 目录，仅为了导出公共头文件路径
add_subdirectory(common)

# 添加 core 目录，它会返回一个 OBJECT 库的列表（或直接生成源文件列表）
add_subdirectory(core)

# 创建最终的共享库（或静态库，根据 N-API 需求）
# 将 core 目录中定义的所有 OBJECT 库链接进来
add_library(
    game_core
    SHARED
    $<TARGET_OBJECTS:main_objects>
    $<TARGET_OBJECTS:bridge_objects>
    $<TARGET_OBJECTS:utils_objects>
)

# 链接系统库
target_link_libraries(
    game_core
    PUBLIC
    librawfile.z.so
    common_headers
)