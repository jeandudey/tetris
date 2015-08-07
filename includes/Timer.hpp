#pragma once

#include "SDLWrapper.hpp"

class Timer {
 public:
  Timer();

  void start();
  void stop();
  void pause();
  void unpause();

  Uint32 get_ticks();

  bool started() const { return started_; }
  bool paused() const { return paused_; }

 private:
  Uint32 start_ticks_;
  Uint32 paused_ticks_;

  bool started_;
  bool paused_;
};
