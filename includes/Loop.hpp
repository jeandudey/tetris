#pragma once

#include "SDLWrapper.hpp"
#include "Tetris.hpp"

#include <boost/core/noncopyable.hpp>

class Loop : private boost::noncopyable {
 public:
  Loop(SDLWindow &window);

  void run();

 private:
  SDLWindow &window_;
  Tetris game_;
};
