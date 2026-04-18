add_library(
  game_core_src
  OBJECT
  equipment_manager.cpp
  game_resource_loader.cpp
  save_game_manager.cpp
)

# 添加头文件路径
target_include_directories(
  game_core_src
  PRIVATE
  ${GAME_CORE_ROOT}/include
)