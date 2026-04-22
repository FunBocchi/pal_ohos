# 遍历所有子模块
#add_subdirectory(bridge)
add_subdirectory(main)

# 将各子模块的OBJECT库聚合为统一的core_objects库
add_library(core_objects
    OBJECT
#    $<TARGET_OBJECTS:bridge_objects>
    $<TARGET_OBJECTS:main_objects>
)

target_link_libraries(core_objects
    PRIVATE
    common_headers
)