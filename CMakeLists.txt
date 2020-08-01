cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_CXX_STANDARD 17)
project(matrix)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(matrix ${SOURCES})
target_link_libraries(matrix ${CURSES_LIBRARIES})