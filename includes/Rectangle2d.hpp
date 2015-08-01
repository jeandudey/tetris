#pragma once

#include "SDLWrapper.hpp"
#include "GLEWWrapper.hpp"
#include "Vector2.hpp"

struct Rectangle2d {
 public:
  typedef Vector2f Position;
  typedef Vector2f Size;
  Rectangle2d(const Position &position, const Size &size);

  void update(const Position &position, const Size &size);
  void draw();

  Position position;
  Size size;
};
