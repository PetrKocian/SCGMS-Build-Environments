
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(scgms_wasm CXX C ASM)

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread -s PTHREAD_POOL_SIZE=3 -s \"EXPORTED_RUNTIME_METHODS=['stringToNewUTF8', 'intArrayFromString', 'UTF8ToString']\"")

FILE(GLOB_RECURSE scgms_srcs "main.cpp" "smartcgms_sources/*.c" "smartcgms_sources/*.cpp" "smartcgms_sources/*.h")

ADD_EXECUTABLE(scgms ${scgms_srcs})

target_compile_definitions(scgms PRIVATE WASM=1)
target_compile_definitions(scgms PRIVATE EMCC=1)
target_compile_definitions(scgms PRIVATE EMBEDDED=1)
target_compile_options(scgms PRIVATE -pthread)


target_include_directories(scgms PRIVATE "smartcgms_sources" )
target_include_directories(scgms PRIVATE "smartcgms_sources/scgms" )
target_include_directories(scgms PRIVATE "smartcgms_sources/filters" )
