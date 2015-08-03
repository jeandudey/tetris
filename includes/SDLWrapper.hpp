#pragma once

#include <SDL.h>
#include <string>

#include <boost/exception/all.hpp>
#include <boost/core/noncopyable.hpp>

struct sdl_error : virtual boost::exception, virtual std::exception { };
typedef boost::error_info<struct sdl_error_info, std::string> sdl_geterror;

class SDL : private boost::noncopyable {
 public:
  SDL(Uint32 flags = SDL_INIT_EVERYTHING);
  ~SDL();

  bool initialized() const { return initialized_; };

 private:
  bool initialized_;
};

class SDLWindow : private boost::noncopyable {
 public:
  SDLWindow(const std::string &title, int x, int y, int w, int h, Uint32 flags = SDL_WINDOW_SHOWN);

  SDL_Window *get();

  void swap();

  void close();
  int width() const;
  int height() const;

  bool created() const { return created_; }

 private:
  SDL_Window *window_;
  bool created_;
};

class SDLRenderer : private boost::noncopyable {
 public:
  SDLRenderer(SDLWindow &window, Uint32 flags = SDL_RENDERER_ACCELERATED);

  SDL_Renderer *get();

  void set_draw_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
  void draw_rectangle(const SDL_Rect *rect);
  void clear();

  bool created() const { return created_; }

  void destroy();

 private:
  SDL_Renderer *renderer_;
  bool created_;
};

class SDLGL : private boost::noncopyable {
 public:
  SDLGL(SDLWindow &window);

  SDL_GLContext get();

  static void set_attribute(SDL_GLattr attr, int value);
  bool swap_interval(int interval);

  bool created() const { return created_; }

 private:
  SDL_GLContext context_;
  bool created_;
};
