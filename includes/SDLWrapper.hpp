#pragma once

#include <SDL.h>
#include <boost/exception/all.hpp>
#include <string>

struct sdl_error : virtual boost::exception, virtual std::exception { };
typedef boost::error_info<struct sdl_error_info, std::string> sdl_geterror;

class SDL {
 public:
  SDL(Uint32 flags = SDL_INIT_EVERYTHING);
  ~SDL();
};
