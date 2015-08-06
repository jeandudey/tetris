#pragma once

#include "Matrix.hpp"

class Playfield : private boost::noncopyable {
 public:
  Playfield();

  void update();
  void draw();

  Matrix<int> &matrix() { return matrix_; };

 private:
  Matrix<int> matrix_;
};
