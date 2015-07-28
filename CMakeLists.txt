cmake_minimum_required(VERSION 3.3)
project(tetris C CXX)

list(
  APPEND
    CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake/Modules"
)

include(AutoInclude)

add_subdirectory("src")

set(TETRIS_LIBRARIES "")
set(TETRIS_INCLUDE_DIRS "")

find_package(SDL2 REQUIRED)

if(SDL2_FOUND)
  list(
    APPEND
      TETRIS_LIBRARIES ${SDL2_LIBRARY}
  )

  list(
    APPEND
      TETRIS_INCLUDE_DIRS ${SDL2_INCLUDE_DIR}
  )
endif()

find_package(
  Boost
  REQUIRED
  COMPONENTS
    exception
    random
)

if(Boost_FOUND)
  list(
    APPEND
      TETRIS_LIBRARIES ${Boost_LIBRARIES}
  )

  list(
    APPEND
      TETRIS_INCLUDE_DIRS ${Boost_INCLUDE_DIRS}
  )
endif()

# Taken from StackOverflow:
# http://stackoverflow.com/questions/10851247/how-to-activate-c-11-in-cmake
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG(
  "-std=c++11"
  COMPILER_SUPPORTS_CXX11
)

CHECK_CXX_COMPILER_FLAG(
  "-std=c++0x"
  COMPILER_SUPPORTS_CXX0X
)

if(COMPILER_SUPPORTS_CXX11)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
  message(
    STATUS
    "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler."
  )
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weffc++")

include_directories(
  "includes"
  ${TETRIS_INCLUDE_DIRS}
)

add_executable(
  tetris
  ${SRCS}
)

target_link_libraries(
  tetris
  ${TETRIS_LIBRARIES}
)

enable_testing()
add_subdirectory("tests")
