cmake_minimum_required(VERSION 3.27)

set(PCIO_BOARD pico_w)

include(external/pico-sdk/pico_sdk_init.cmake)

project(pico_test)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

pico_sdk_init()

add_executable(lift
    lift.c
)

target_link_libraries(lift pico_stdlib)
add_executable(button-blinky
    button-blinky.c
)

target_link_libraries(button-blinky pico_stdlib)
add_executable(light
    light.c
)


target_link_libraries(light pico_stdlib hardware_adc)
pico_enable_stdio_usb(light 1)
pico_enable_stdio_uart(light 1)

pico_add_extra_outputs(lift button-blinky light)


