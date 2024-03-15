file(GLOB_RECURSE srcs
     "*.h"
     "*.cpp"
     "*.c"
)

idf_component_register(SRCS "${srcs}"
                       INCLUDE_DIRS sources sources/scgms ${PROJECT_DIR}/components
                       REQUIRES filters)

set_target_properties(${COMPONENT_LIB} PROPERTIES COMPILE_FLAGS -Wno-unknown-pragmas)


target_compile_options(${COMPONENT_LIB} PUBLIC -std=gnu++2a -Wno-unknown-pragmas)
target_compile_options(${COMPONENT_LIB} PUBLIC -std=gnu++2a -fcompare-debug-second)
target_compile_options(${COMPONENT_LIB} PUBLIC -std=gnu++2a -Wno-unused-parameter)
target_compile_options(${COMPONENT_LIB} PUBLIC -std=gnu++2a -Wno-unused-variable)
target_compile_options(${COMPONENT_LIB} PUBLIC -std=gnu++2a -Wno-implicit-fallthrough)
target_compile_options(${COMPONENT_LIB} PUBLIC -std=gnu++2a -Wno-cast-function-type)
target_compile_options(${COMPONENT_LIB} PUBLIC -std=gnu++2a -Wno-class-memaccess)
target_compile_options(${COMPONENT_LIB} PUBLIC -std=gnu++2a -Wno-unused-but-set-parameter)

target_compile_definitions(${COMPONENT_LIB} PRIVATE ESP32=1)
target_compile_definitions(${COMPONENT_LIB} PRIVATE EMBEDDED=1)
