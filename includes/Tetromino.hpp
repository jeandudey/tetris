#pragma once

#include "GLEWWrapper.hpp"
#include "Rectangle2d.hpp"
#include "Color.hpp"
#include <glm/glm.hpp>
#include <vector>

class Tetromino {
 public:
  typedef std::vector<std::vector<std::vector<int> > > RotationType;
  typedef glm::vec2 Position;

  enum Type {
      I,
      O
  };

  explicit Tetromino()
    : current_rotation_(0),
      playfield_position_(),
      rotations_(4),
      color_(0.f, 0.f, 0.f)
  {
  }

  void draw()
  {
    glm::vec2 position(playfield_position_.x * 32, playfield_position_.y * 32);

    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            if (rotations_[current_rotation_][x][y] != 0)
            {
                Rectangle2d quad(Rectangle2d::Position((playfield_position_.x + x) * 32, (playfield_position_.y + y) * 32),
                                 Rectangle2d::Size(32, 32));

                quad.color(color_.r, color_.b, color_.g);

                quad.draw();
            }
        }
    }
  }

 protected:
  int current_rotation_;
  Position playfield_position_;
  RotationType rotations_;
  Color<float> color_;
};
