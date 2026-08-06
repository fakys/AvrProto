cmake_minimum_required(VERSION 3.28)
project(avr_proto)

set(CMAKE_C_COMPILER avr-gcc)
set(MCU atmega328p)
set(F_CPU 16000000UL)

#x86 или AVR
set(ARCHITECTURE_NAME x86)


if (ARCHITECTURE_NAME STREQUAL "x86")
    set(CMAKE_CXX_COMPILER g++)
    set(CMAKE_ASM_COMPILER gcc)
    add_definitions(-DX86_ARCHITECTURE=1)

elseif (ARCHITECTURE_NAME STREQUAL "AVR")
    set(CMAKE_CXX_COMPILER avr-g++)
    set(CMAKE_ASM_COMPILER avr-gcc)
    set(CMAKE_OBJCOPY avr-objcopy)
    set(CMAKE_SIZE avr-size)
    set(USE_UART 1)

    add_definitions(-D__AVR_ATmega328P__=1)
    add_definitions(-DF_CPU=16000000UL)
    set(CMAKE_CXX_FLAGS "-mmcu=${MCU} -DF_CPU=${F_CPU} -Os")
    set(CMAKE_C_FLAGS "-mmcu=${MCU} -DF_CPU=${F_CPU} -Os")
    set(CMAKE_EXE_LINKER_FLAGS "-mmcu=${MCU}")

    add_definitions(-DAVR_ARCHITECTURE=1)
endif ()



add_definitions(-DAVR_PROTO_V1=1)
#По умолчанию один
add_definitions(-DSENDER_ID=1)


add_subdirectory(./components/core)
add_subdirectory(./components/avr_usb_sender)
add_subdirectory(components/avr_proto_v1)



add_executable(arduino main.cpp)

target_link_libraries(arduino PUBLIC CORE)
target_link_libraries(arduino PUBLIC AVR_USB_SENDER)
target_link_libraries(arduino PUBLIC AVR_PROTO)

target_include_directories(arduino PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (ARCHITECTURE_NAME STREQUAL "AVR")
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O ihex -R .eeprom
        $<TARGET_FILE:${PROJECT_NAME}>
        ${PROJECT_NAME}.hex
        COMMENT "Converting to HEX format"
)
endif ()