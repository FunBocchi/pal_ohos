# 收集当前模块的所有源文件
file(GLOB UTILS_SOURCES "*.cpp")

# 创建object库
add_library(
    utils_objects
    OBJECT
    ${UTILS_SOURCES}
)

target_link_libraries(
    utils_objects
    PRIVATE
    common_headers
)

# 私有的头文件
target_include_directories(
    utils_objects
    PRIVATE
    ${CLASSES_ROOT}/core/include/utils
)