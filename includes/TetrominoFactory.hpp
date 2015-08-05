#pragma once

#include "Tetromino.hpp"
#include "OTetromino.hpp"
#include "ITetromino.hpp"
#include "JTetromino.hpp"
#include "LTetromino.hpp"
#include "STetromino.hpp"
#include "TTetromino.hpp"
#include "ZTetromino.hpp"
#include <boost/shared_ptr.hpp>

class TetrominoFactory {
 public:
  static boost::shared_ptr<Tetromino> create(const Tetromino::Type type)
  {
    if (type == Tetromino::Type::I)
        return boost::shared_ptr<Tetromino>(new ITetromino);
    else if (type == Tetromino::Type::J)
        return boost::shared_ptr<Tetromino>(new JTetromino);
    else if (type == Tetromino::Type::L)
        return boost::shared_ptr<Tetromino>(new LTetromino);
    else if (type == Tetromino::Type::O)
        return boost::shared_ptr<Tetromino>(new OTetromino);
    else if (type == Tetromino::Type::S)
        return boost::shared_ptr<Tetromino>(new STetromino);
    else if (type == Tetromino::Type::T)
        return boost::shared_ptr<Tetromino>(new TTetromino);
    else if (type == Tetromino::Type::Z)
        return boost::shared_ptr<Tetromino>(new ZTetromino);
  }
};
