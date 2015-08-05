#pragma once

#include "Tetromino.hpp"
#include "OTetromino.hpp"
#include "ITetromino.hpp"
#include <boost/shared_ptr.hpp>

class TetrominoFactory {
 public:
  static boost::shared_ptr<Tetromino> create(const Tetromino::Type type)
  {
    if (type == Tetromino::Type::O)
        return boost::shared_ptr<Tetromino>(new OTetromino);
    else if (type == Tetromino::Type::I)
        return boost::shared_ptr<Tetromino>(new ITetromino);
  }
};
