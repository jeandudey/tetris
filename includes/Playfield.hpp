#pragma once

#include "Matrix.hpp"
#include "tetromino/Tetromino.hpp"

#include <boost/core/noncopyable.hpp>

class Playfield : private boost::noncopyable {
 public:
  Playfield();

  void update();
  void draw();

  void store_tetromino(Tetromino *tetromino);
  bool is_gameover();

  Matrix<int> &matrix() { return matrix_; };

 private:
  Matrix<int> matrix_;

  void delete_line(int line);
};
