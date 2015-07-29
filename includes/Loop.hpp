#pragma once

#include "SDLWrapper.hpp"
#include "Tetris.hpp"

#include <boost/exception/all.hpp>
#include <boost/core/noncopyable.hpp>

struct loop_error : virtual boost::exception, virtual std::exception { };
typedef boost::error_info<struct loop_error_info, std::string> loop_error_string;

class Loop : private boost::noncopyable {
 public:
  Loop(Tetris *game);

  void run();

 private:
  Tetris *game_;
};
