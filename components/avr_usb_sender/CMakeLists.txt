add_library(
        AVR_USB_SENDER
        ${CMAKE_CURRENT_SOURCE_DIR}/src/AvrUartSender.cpp
)


target_link_libraries(AVR_USB_SENDER PUBLIC CORE)

target_include_directories(
        AVR_USB_SENDER
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include

)