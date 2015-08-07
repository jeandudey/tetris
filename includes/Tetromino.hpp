#pragma once

#include "GLEWWrapper.hpp"
#include "Rectangle2d.hpp"
#include "Color.hpp"
#include "Matrix.hpp"
#include <glm/glm.hpp>
#include <vector>

class Tetromino {
 public:
  typedef std::vector<std::vector<std::vector<int> > > RotationType;
  typedef glm::vec2 Position;

  enum class Type {
      I = 0,
      J,
      L,
      O,
      S,
      T,
      Z
  };

  enum class MovementType {
      Left = 0,
      Right,
      Advance,
      Rotate
  };

  explicit Tetromino()
    : current_rotation_(0),
      playfield_position_(),
      rotations_(4, std::vector<std::vector<int> >(5, std::vector<int>(5, 0))),
      color_(0.f, 0.f, 0.f) { }

  // Move tetromino on the x axis.
  void move(MovementType type)
  {
    if (type == MovementType::Left)
        playfield_position_.x -= 1;
    else if (type == MovementType::Right)
        playfield_position_.x += 1;
    else if (type == MovementType::Advance)
        playfield_position_.y += 1;
    else if (type == MovementType::Rotate)
        current_rotation_ = (current_rotation_ + 1) % 4;
  }

  // Return block type of the current rotation.
  int block_type(int rotation, int y, int x)
  {
    return rotations_[rotation][y][x];
  }

  glm::vec2 position()
  {
    return playfield_position_;
  }

  int rotation()
  {
    return current_rotation_;
  }

  bool is_possible_movement(MovementType type, Matrix<int> &matrix)
  {
    glm::vec2 playfield_position(playfield_position_);
    int rotation = current_rotation_;

    if (type == MovementType::Left)
        playfield_position.x -= 1;
    else if (type == MovementType::Right)
        playfield_position.x += 1;
    else if (type == MovementType::Advance)
        playfield_position.y += 1;
    else if (type == MovementType::Rotate)
        rotation = (rotation + 1) % 4;

    for (int x1 = playfield_position.x, x2 = 0; x1 < playfield_position.x + 5; x1++, x2++) {
        for (int y1 = playfield_position.y, y2 = 0; y1 < playfield_position.y + 5; y1++, y2++) {
            if (x1 < 0 ||
                x1 > matrix.width() - 1 ||
                y1 > matrix.height() - 1) {
                if (block_type(rotation, y2, x2) != 0)
                    return false;
            }

            if (y1 >= 0) {
                if (block_type(rotation, y2, x2) != 0 &&
                    matrix(x1, y1) != 0)
                    return false;
            }
        }
    }

    return true;
  }

  void draw()
  {
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            if (rotations_[current_rotation_][y][x] != 0) {
                Rectangle2d quad(Rectangle2d::Position((playfield_position_.x + x) * 32, (playfield_position_.y + y) * 32),
                                 Rectangle2d::Size(32, 32));

                if (rotations_[current_rotation_][y][x] == 2)
                    quad.color(1.f, 1.f, 1.f);
                else
                    quad.color(color_.r, color_.g, color_.b);

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
