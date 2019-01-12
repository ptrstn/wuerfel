cmake_minimum_required(VERSION 3.9)
project(wuerfel)

set(CMAKE_SYSTEM_NAME Generic)

set(MCU atmega328p)
set(PROGRAMMER arduino)
set(PORT /dev/ttyUSB0)
set(BAUDRATE 57600)

set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_CXX_FLAGS "-mmcu=${MCU}")

add_compile_options("-Wall" "-Wextra" "-Wpedantic" "-Os")
add_definitions("-DF_CPU=16000000UL")

add_executable(${PROJECT_NAME}.elf main.cc)

add_custom_target(flash ALL
        DEPENDS ${PROJECT_NAME}.elf
        COMMAND avr-objcopy -j .text -j .data -O ihex  ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex)

set_directory_properties(PROPERTIES
        ADDITIONAL_MAKE_CLEAN_FILES ${PROJECT_NAME}.hex)

add_custom_target(burn
        DEPENDS flash
        COMMAND avrdude -p ${MCU} -c ${PROGRAMMER} -b ${BAUDRATE} -P ${PORT} -U flash:w:${PROJECT_NAME}.hex)