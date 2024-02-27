cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

# The name of the project
project(seven_segment_display)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# Executable name and source files
add_executable(clock
    ${CMAKE_CURRENT_LIST_DIR}/src/app.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/I2c.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Ht16k33.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Adc.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Time.cpp
)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

pico_enable_stdio_usb(clock 1)
pico_enable_stdio_uart(clock 0)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(clock pico_stdlib hardware_i2c hardware_adc)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(clock)
