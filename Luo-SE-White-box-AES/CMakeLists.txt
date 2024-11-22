CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(WBAES_SE)

include_directories(include)

aux_source_directory(src WBAES_SE_SRC)
aux_source_directory(src/wbmatrix WBAES_SE_SRC)

add_library(WBAES_SE_LIB ${WBAES_SE_SRC})

add_executable(LL_TEST test/LL_test.c)
add_executable(WBAES_SE_LT test/wbaes_se_lt_test.c)
# add_executable(WBAES_SE_LT_NEON test/wbaes_se_lt_neon_test.c)
add_executable(AES_TEST test/aes_test.c)

target_link_libraries(LL_TEST WBAES_SE_LIB)
target_link_libraries(WBAES_SE_LT WBAES_SE_LIB)
# target_link_libraries(WBAES_SE_LT_NEON WBAES_SE_LIB)
target_link_libraries(AES_TEST WBAES_SE_LIB)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99  -O2 -m64 -mavx2")
# set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -march=armv8-a+fp+simd+crypto+crc")