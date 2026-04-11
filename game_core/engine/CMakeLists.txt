add_library(
  game_core_engine
  OBJECT
)

# 添加头文件路径
target_include_directories(
  game_core_engine
  PRIVATE
  ${GAME_CORE_ROOT}/include/engine
)