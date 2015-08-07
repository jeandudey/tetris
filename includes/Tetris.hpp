#pragma once

#include "SDLWrapper.hpp"
#include "GLEWWrapper.hpp"
#include "Playfield.hpp"
#include "TetrominoFactory.hpp"
#include "Timer.hpp"

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
  Timer timer_;

  boost::shared_ptr<Tetromino> current_tetromino_;
  bool running_;
};
