add_executable(sdlwrapper ../src/SDLWrapper.cc SDLWrapper.cc)
target_link_libraries(sdlwrapper
  gtest
  ${TETRIS_LIBRARIES}
)

add_test(SDLWrapper sdlwrapper)
