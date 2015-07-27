cmake_minimum_required(VERSION 3.3)
project(tetris CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake/Modules")

include(AutoInclude)

add_subdirectory("src")

add_executable(tetris ${SRCS})

enable_testing()

add_subdirectory("tests")
