CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(scgms_rpi CXX C ASM)

SET(LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/Rpi/raspberrypi.ld")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0" )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g" )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall" )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-unknown-pragmas" )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wextra --specs=nosys.specs  -specs=nano.specs -nostartfiles" )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=armv6zk" )
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mtune=arm1176jzf-s" )

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra --specs=nosys.specs -nostartfiles -specs=nano.specs" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unknown-pragmas" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=armv6zk" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mtune=arm1176jzf-s" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions" )


set(CMAKE_C_COMPILER "/usr/lib/arm-none-eabi-new/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc")
set(CMAKE_ASM_COMPILER "/usr/lib/arm-none-eabi-new/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "/usr/lib/arm-none-eabi-new/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-g++")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L /usr/lib/gcc/arm-none-eabi/6.3.1 -lgcc")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${LINKER_SCRIPT}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L /usr/lib/arm-none-eabi-new/gcc-arm-none-eabi-10.3-2021.10/arm-none-eabi/lib")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lstdc++ -Wl,--strip-all")

INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS/Source/portable/GCC/RaspberryPi/")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS/Source/include/")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/Rpi/Drivers/")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/Rpi/")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/SmartCGMS/scgms/")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/SmartCGMS/")
INCLUDE_DIRECTORIES("${CMAKE_CURRENT_SOURCE_DIR}/filters")


FILE(GLOB_RECURSE freertos_src  
    "FreeRTOS/*.c"
    "FreeRTOS/*.h"
)

FILE(GLOB_RECURSE scgms
     "SmartCGMS/*.h"
     "SmartCGMS/*.cpp"
     "SmartCGMS/*.c"
)

FILE(GLOB_RECURSE filters
     "filters/*.h"
     "filters/*.cpp"
     "filters/*.c"
)

FILE(GLOB_RECURSE drivers  
    "Rpi/*.c"
    "Rpi/*.s"
    "Rpi/*.h"
)

ADD_EXECUTABLE(freertos "main.c" ${freertos_src} ${drivers} ${scgms} ${filters})
set_property(TARGET freertos PROPERTY CXX_STANDARD 17)

target_compile_definitions(freertos PRIVATE FREERTOS=1)
target_compile_definitions(freertos PRIVATE EMBEDDED=1)

