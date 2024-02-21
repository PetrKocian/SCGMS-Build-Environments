file(GLOB_RECURSE srcs
     "*.h"
     "*.cpp"
     "*.c"
)

idf_component_register(SRCS "${srcs}"
                       INCLUDE_DIRS sources sources/scgms ${PROJECT_DIR}/components
                       REQUIRES filters)

target_compile_options(${COMPONENT_LIB} PUBLIC -std=gnu++2a -Wno-unknown-pragmas)

target_compile_definitions(${COMPONENT_LIB} PRIVATE ESP32=1)
target_compile_definitions(${COMPONENT_LIB} PRIVATE EMBEDDED=1)
