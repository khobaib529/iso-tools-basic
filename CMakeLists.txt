cmake_minimum_required(VERSION 3.10)
project(ISO-tools-basic)


set(SOURCE_DIR src)
set(INCLUDE_DIR include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(read_iso
    ${SOURCE_DIR}/read_iso.cc
)
target_include_directories(read_iso PUBLIC ${INCLUDE_DIR})
