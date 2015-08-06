#pragma once

#include "Matrix.hpp"

#include <boost/core/noncopyable.hpp>

class Playfield : private boost::noncopyable {
 public:
  Playfield();

  void update();
  void draw();

  Matrix<int> &matrix() { return matrix_; };

 private:
  Matrix<int> matrix_;
};
