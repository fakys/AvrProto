add_library(
        AVR_PROTO
        ${CMAKE_CURRENT_SOURCE_DIR}/src/AvrProto.cpp
)

target_link_libraries(AVR_PROTO PUBLIC CORE)

target_include_directories(
        AVR_PROTO
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/include
)