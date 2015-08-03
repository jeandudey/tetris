#pragma once

#include <boost/core/noncopyable.hpp>
#include "Matrix.hpp"

class Playfield : private boost::noncopyable {
 public:
  Playfield();

  void update();
  void draw();

 private:
  Matrix<int> matrix_;
};
