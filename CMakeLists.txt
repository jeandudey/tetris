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
