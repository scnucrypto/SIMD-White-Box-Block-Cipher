cmake_minimum_required(VERSION 3.9.0)

project(Xiao-Lai-White-box-SM4)

# global import header file
set(XL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
include_directories(${XL_INCLUDE_DIR})

# files in library
aux_source_directory(src/ xl_src)
aux_source_directory(src/wbmatrix xl_src)

add_library(XL_LIB ${xl_src})
add_executable(WBSM4XL test/wbsm4_xl_test.c)
target_link_libraries(WBSM4XL XL_LIB)

add_executable(SM4 test/sm4_test.c)

target_link_libraries(SM4 XL_LIB)


SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99  -O2")

