# the minimum version of CMake.
cmake_minimum_required(VERSION 3.5.0)
project(pal_ohos_laptop)

set(
  NATIVERENDER_ROOT_PATH
  ${CMAKE_CURRENT_SOURCE_DIR}
)

include_directories(
  ${NATIVERENDER_ROOT_PATH}
  ${NATIVERENDER_ROOT_PATH}/include
)

add_subdirectory(
  ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../
  ${CMAKE_CURRENT_BINARY_DIR}/root_build
)

add_library(
  laptop
  SHARED
  napi_init.cpp
)

find_library(
  hilog-lib
  hilog_ndk.z
)

target_link_libraries(
  laptop
  PUBLIC
  libace_napi.z.so
  ${hilog-lib}
  libuv.so
  libffrt.z.so
  libnative_drawing.so
  libnative_window.so
  libace_ndk.z.so
  librawfile.z.so
  libavplayer.so
  libnative_media_core.so
  game_core
)