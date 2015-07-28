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

class SDLWindow {
 public:
  SDLWindow(const std::string &title, int x, int y, int w, int h, Uint32 flags = SDL_WINDOW_SHOWN);

  SDL_Window *get();

  void close();

 private:
  SDL_Window *window_;
};

class SDLRenderer {
 public:
  SDLRenderer(SDLWindow window, Uint32 flags = SDL_RENDERER_ACCELERATED);

  SDL_Renderer *get();

  void set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
  void draw_rectangle(const SDL_Rect *rect);
  void clear();

  void destroy();

 private:
  SDL_Renderer *renderer_;
};
