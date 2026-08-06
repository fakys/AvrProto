if (USE_UART)
    set(UART_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/AvrUartSender.cpp)
endif ()

add_library(
        AVR_USB_SENDER
        ${UART_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/X86UsbSender.cpp
)


target_link_libraries(AVR_USB_SENDER PUBLIC CORE)

target_include_directories(
        AVR_USB_SENDER
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include

)