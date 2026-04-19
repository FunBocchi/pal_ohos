cmake_minimum_required(VERSION 3.5.0)
project(pal_game_core)

set(
  GAME_CORE_ROOT
  ${CMAKE_CURRENT_SOURCE_DIR}
)

# 添加各个子模块
#add_subdirectory(bridge)
# add_subdirectory(engine)
 add_subdirectory(src)
# add_subdirectory(util)

# 组装成完整的静态库
add_library(
  game_core
  STATIC
#  $<TARGET_OBJECTS:game_core_bridge>
#   $<TARGET_OBJECTS:game_core_engine>
   $<TARGET_OBJECTS:game_core_src>
#   $<TARGET_OBJECTS:game_core_util>
)

# set(
#   BRIDGE_SOURCES
#   bridge/native_game_bridge.cpp
#   bridge/xcomponent_bridge_registry.cpp
# )

# add_library(
#   game_core
#   STATIC
#   ${BRIDGE_SOURCES}
# )

target_include_directories(
  game_core
  PUBLIC
  ${GAME_CORE_ROOT}/include
)

target_link_libraries(
  game_core
  PUBLIC
  librawfile.z.so
)