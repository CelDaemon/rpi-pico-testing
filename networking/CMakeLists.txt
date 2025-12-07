add_executable(networking networking.c)
pico_set_lwip_httpd_content(networking PRIVATE "${CMAKE_CURRENT_LIST_DIR}/index.html")
target_link_libraries(networking
    pico_lwip
    pico_lwip_arch
    pico_cyw43_arch_lwip_threadsafe_background
    pico_lwip_http
    pico_stdlib
)
target_include_directories(networking PRIVATE ${PICO_LWIP_CONTRIB_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
pico_add_extra_outputs(networking)
pico_enable_stdio_uart(networking 1)
pico_enable_stdio_usb(networking 1)
