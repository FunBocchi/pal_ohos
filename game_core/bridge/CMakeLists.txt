add_library(
  game_core_bridge
  OBJECT
  native_game_bridge.cpp
  xcomponent_bridge_registry.cpp
)

# 添加头文件路径
target_include_directories(
  game_core_bridge
  PRIVATE
  ${GAME_CORE_ROOT}/include/bridge
)