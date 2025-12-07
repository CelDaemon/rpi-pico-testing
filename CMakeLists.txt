cmake_minimum_required(VERSION 3.27)

#set(PICO_BOARD pico2_w)

include(external/pico-sdk/pico_sdk_init.cmake)

project(pico_test)

set(FLASH_TARGET "" CACHE STRING "Which target to flash")

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

pico_sdk_init()

add_executable(lift lift.c)
target_link_libraries(lift pico_stdlib)
pico_add_extra_outputs(lift)

add_executable(button-blinky button-blinky.c)
target_link_libraries(button-blinky pico_stdlib)
pico_add_extra_outputs(button-blinky)

add_executable(light light.c)
target_link_libraries(light pico_stdlib hardware_adc)
pico_add_extra_outputs(light)
pico_enable_stdio_uart(light 1)
pico_enable_stdio_usb(light 1)

add_executable(volume volume.c)
target_link_libraries(volume pico_stdlib hardware_adc)
pico_add_extra_outputs(volume)
if(PICO_CYW43_SUPPORTED)
    add_subdirectory(networking)
endif()

if(FLASH_TARGET)
    add_custom_target(flash USES_TERMINAL DEPENDS ${FLASH_TARGET}
        COMMAND sudo mount /dev/sda1 /mnt/rpi
        COMMAND sudo cp "$<TARGET_FILE_DIR:${FLASH_TARGET}>/$<TARGET_FILE_BASE_NAME:${FLASH_TARGET}>.uf2" /mnt/rpi
        COMMAND sudo umount /dev/sda1
    )
endif()
