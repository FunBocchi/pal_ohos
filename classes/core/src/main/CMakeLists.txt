# 收集当前模块的所有源文件
#file(GLOB MAIN_SOURCES "*.cpp")
set(
    MAIN_SOURCES
    dummy.cpp
    global.cpp
)

# 创建object库
add_library(main_objects
    OBJECT
    ${MAIN_SOURCES}
)

# 私有的头文件
target_include_directories(main_objects
    PRIVATE
    ${CLASSES_ROOT}/core/include/main
)