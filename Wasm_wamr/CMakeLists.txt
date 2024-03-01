
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(scgms_wasm CXX C ASM)

FILE(GLOB_RECURSE scgms_srcs "main.cpp" "smartcgms_sources/*.c" "smartcgms_sources/*.cpp" "smartcgms_sources/.h")

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fno-exceptions ")

ADD_EXECUTABLE(scgms ${scgms_srcs})

target_compile_definitions(scgms PRIVATE WASM=1)
target_compile_definitions(scgms PRIVATE EMBEDDED=1)


target_include_directories(scgms PRIVATE "smartcgms_sources" )
target_include_directories(scgms PRIVATE "smartcgms_sources/scgms" )
target_include_directories(scgms PRIVATE "smartcgms_sources/filters" )

#target_link_options(scgms PUBLIC "-Wl,--export=create_level_event") #do't forget extern C in source code
#target_link_options(scgms PUBLIC "-Wl,--export=build_filter_chain")

