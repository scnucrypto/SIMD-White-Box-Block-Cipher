cmake_minimum_required(VERSION 3.9.0)

project(WBMatrix_SIMD)

# global import header file
set(WBMATRIX_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
include_directories(${WBMATRIX_INCLUDE_DIR})

# files in library
aux_source_directory(src/ wbmatrix_src)
aux_source_directory(src/wbmatrix wbmatrix_src)

add_library(WBMatrix_LIB ${wbmatrix_src})

add_executable(WBSM4SE test/wbsm4_se_test.c)
add_executable(WBSM4SELA test/wbsm4_se_la_test.c)
# add_executable(WBSM4SEAVX2 test/wbsm4_se_avx2_test.c)
# add_executable(WBSM4SENEON test/wbsm4_se_neon_test.c)
add_executable(WBSM4XL test/wbsm4_xl_test.c)
add_executable(WBSM4BW test/wbsm4_bw_test.c)

target_link_libraries(WBSM4SE WBMatrix_LIB)
target_link_libraries(WBSM4SELA WBMatrix_LIB)
# target_link_libraries(WBSM4SEAVX2 WBMatrix_LIB)
# target_link_libraries(WBSM4SENEON WBMatrix_LIB)
target_link_libraries(WBSM4XL WBMatrix_LIB)
target_link_libraries(WBSM4BW WBMatrix_LIB)

add_executable(SM4 test/sm4_test.c)
add_executable(SM4LUT test/sm4_lut_test.c)

target_link_libraries(SM4 WBMatrix_LIB)
target_link_libraries(SM4LUT WBMatrix_LIB)


SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99  -O2 -m64 -mavx2")
# set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O2 -march=armv8-a+fp+simd+crypto+crc")

