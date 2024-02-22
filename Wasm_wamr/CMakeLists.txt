
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(scgms_wasm CXX C ASM)

FILE(GLOB_RECURSE scgms_srcs "sources/scgms/*.c" "sources/scgms/*.cpp" "sources/scmgs/.h" "sources/main.cpp" "sources/my_config.h")

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fno-exceptions ")

ADD_EXECUTABLE(scgms ${scgms_srcs})

target_compile_definitions(scgms PRIVATE WASM=1)
target_compile_definitions(scgms PRIVATE EMBEDDED=1)


target_include_directories(scgms PRIVATE "sources" )
target_include_directories(scgms PRIVATE "sources/scgms" )

target_link_options(scgms PUBLIC "-Wl,--export=push_event")
#target_link_options(scgms PUBLIC "-Wl,--export=main")

