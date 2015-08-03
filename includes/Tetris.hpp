#pragma once

#include "SDLWrapper.hpp"
#include "GLEWWrapper.hpp"
#include "Playfield.hpp"

class Tetris : private boost::noncopyable {
 public:
  Tetris(SDLWindow &window);
  ~Tetris();

  void handle_events();
  void update();
  void draw();

  bool running() const { return running_; };

 private:
  SDLGL context_;
  SDLWindow &window_;
  GLEW glew_;
  Playfield playfield_;
  bool running_;
};
