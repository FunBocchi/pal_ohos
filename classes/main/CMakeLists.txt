add_library(
  core_main
  OBJECT
)

# 添加头文件路径
target_include_directories(
  core_main
  PRIVATE
  ${GAME_CORE_ROOT}/include
)