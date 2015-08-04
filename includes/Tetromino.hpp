#pragma once

#include "GLEWWrapper.hpp"
#include "Rectangle2d.hpp"
#include "Color.hpp"
#include <glm/glm.hpp>
#include <vector>

class Tetromino {
 public:
  typedef std::vector<std::vector<std::vector<int> > > RotationType;

  enum Type {
      O
  };

  explicit Tetromino(int rotation, int initial_position)
    : current_rotation_(rotation),
      current_position_(initial_position),
      rotations_(4),
      initial_positions_(4),
      color_(0.f, 0.f, 0.f)
  {
  }

  void draw()
  {
    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            if (rotations_[current_rotation_][x][y] != 0)
            {
                Rectangle2d quad(Rectangle2d::Position(x * 32, y * 32),
                                 Rectangle2d::Size(32, 32));

                quad.color(color_.r, color_.b, color_.g);

                quad.draw();
            }
        }
    }
  }

 protected:
  int current_rotation_;
  int current_position_;
  RotationType rotations_;
  Color<float> color_;
  std::vector<glm::vec2> initial_positions_;
};
