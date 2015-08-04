#pragma once

#include "Tetromino.hpp"

class OTetromino : public Tetromino {
 public:
  OTetromino(int rotation, int initial_position)
    : Tetromino(rotation, initial_position)
  {
    rotations_ = {
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 2, 1, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0}
            },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 2, 1, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0}
            },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 2, 1, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0}
            },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 2, 1, 0},
            {0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0}
        }
    };

    initial_positions_ = {
        glm::vec2(-2, -3),
        glm::vec2(-2, -3),
        glm::vec2(-2, -3),
        glm::vec2(-2, -3),
    };

    color_ = Color<float>(1.f, 0.f, 1.f);
  }
};
