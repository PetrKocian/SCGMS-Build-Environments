file(GLOB_RECURSE srcs
     "*.h"
     "*.cpp"
     "*.c"
)

idf_component_register(SRCS "${srcs}"
                       INCLUDE_DIRS "."
                       REQUIRES scgms_embedded)

target_compile_options(${COMPONENT_LIB} PUBLIC -std=gnu++2a)

target_compile_definitions(${COMPONENT_LIB} PRIVATE ESP32=1)
