CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(WBSPECK_SE)

include_directories(include)

aux_source_directory(src WBSPECK_SE_SRC)
aux_source_directory(src/wbmatrix WBSPECK_SE_SRC)

add_library(WBSPECK_SE_LIB ${WBSPECK_SE_SRC})

add_executable(WBSPECK_SE test/default_test.c)
add_executable(WBSPECK_SE_BP test/bit_packed_test.c)
add_executable(WBSPECK_SE_IBP test/inlined_bit_packed_test.c)
add_executable(WBSPECK_SE_I test/inlined_test.c)
add_executable(WBSPECK_SE_SIMD test/simd_test.c)
add_executable(WBSPECK_SE_SP test/sparse_matrix_test.c)
add_executable(WBSPECK_SE_NEON test/neon_test.c)

target_link_libraries(WBSPECK_SE WBSPECK_SE_LIB)
target_link_libraries(WBSPECK_SE_BP WBSPECK_SE_LIB)
target_link_libraries(WBSPECK_SE_IBP WBSPECK_SE_LIB)
target_link_libraries(WBSPECK_SE_I WBSPECK_SE_LIB)
target_link_libraries(WBSPECK_SE_SIMD WBSPECK_SE_LIB)
target_link_libraries(WBSPECK_SE_SP WBSPECK_SE_LIB)
target_link_libraries(WBSPECK_SE_NEON WBSPECK_SE_LIB)

# SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99  -O2 -m64 -mavx2")
# set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -march=armv8-a+fp+simd+crypto+crc")