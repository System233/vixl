cmake_minimum_required(VERSION 3.0)
project(vixl C CXX)

add_definitions(-DVIXL_INCLUDE_TARGET_A64 -DVIXL_INCLUDE_TARGET_A32 -DVIXL_INCLUDE_TARGET_T32 -DVIXL_CODE_BUFFER_MALLOC)
set(VIXL_SRC )
file(GLOB VIXL_SRC LIST_DIRECTORIES FALSE src/*.cc src/**/*.cc)

add_library(vixl SHARED ${VIXL_SRC})
add_library(vixl_static STATIC ${VIXL_SRC})

target_include_directories(vixl PUBLIC src)
target_include_directories(vixl_static PUBLIC src)