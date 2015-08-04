#pragma once

#include "Tetromino.hpp"
#include "OTetromino.hpp"
#include <boost/shared_ptr.hpp>

class TetrominoFactory {
 public:
  static boost::shared_ptr<Tetromino> create(const Tetromino::Type type, int rotation, int initial_position)
  {
    if (type == Tetromino::Type::O)
        return boost::shared_ptr<Tetromino>(new OTetromino(rotation, initial_position));
  }
};
