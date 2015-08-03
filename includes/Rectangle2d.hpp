#pragma once

#include "SDLWrapper.hpp"
#include "GLEWWrapper.hpp"

#include <glm/glm.hpp>

struct Rectangle2d {
 public:
  typedef glm::vec2 Position;
  typedef glm::vec2 Size;
  Rectangle2d(const Position &position, const Size &size);

  void update(const Position &position, const Size &size);
  void draw();

  Position position;
  Size size;
};
