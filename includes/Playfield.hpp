#pragma once

#include "Matrix.hpp"
#include "Tetromino.hpp"

#include <boost/core/noncopyable.hpp>

class Playfield : private boost::noncopyable {
 public:
  Playfield();

  void update();
  void draw();

  void store_tetromino(Tetromino *tetromino);

  Matrix<int> &matrix() { return matrix_; };

 private:
  Matrix<int> matrix_;
};
