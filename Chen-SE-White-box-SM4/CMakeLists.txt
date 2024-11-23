CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(WBSM4_SE_CL)

include_directories(include)

aux_source_directory(src WBSM4_SE_CL_SRC)
aux_source_directory(src/wbmatrix WBSM4_SE_CL_SRC)

add_library(WBSM4_SE_CL_LIB ${WBSM4_SE_CL_SRC})

add_executable(WBSM4_SE_CL test/test.c)
add_executable(WBSM4_SE_CL_AVX2 test/avx2_test.c)
# add_executable(WBSM4_SE_CL_NEON test/neon_test.c)

target_link_libraries(WBSM4_SE_CL WBSM4_SE_CL_LIB)
target_link_libraries(WBSM4_SE_CL_AVX2 WBSM4_SE_CL_LIB)
# target_link_libraries(WBSM4_SE_CL_NEON WBSM4_SE_CL_LIB)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99  -O2 -m64 -mavx2")
# set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -march=armv8-a+fp+simd+crypto+crc")