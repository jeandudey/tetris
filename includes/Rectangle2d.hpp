#pragma once

#include "SDLWrapper.hpp"
#include "GLEWWrapper.hpp"

#include <glm/glm.hpp>

class Rectangle2d {
 public:
  typedef glm::vec2 Position;
  typedef glm::vec2 Size;

  Rectangle2d(const Position &position, const Size &size);

  void color(const float r, const float b, const float g);

  void update(const Position &position, const Size &size);
  void draw();

 private:
  float r_;
  float b_;
  float g_;

  Position position_;
  Size size_;
};
