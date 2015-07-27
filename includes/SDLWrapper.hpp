#pragma once

#include <SDL.h>

// TODO: Use Boost.Exception to handle exceptions.

class SDL {
 public:
  SDL(Uint32 flags = SDL_INIT_EVERYTHING);
  ~SDL();

};
