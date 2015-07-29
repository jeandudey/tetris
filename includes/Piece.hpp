#pragma once

#include "Vector2.hpp"
#include "SDLWrapper.hpp"

#include <vector>
#include <boost/shared_array.hpp>

class Piece {
 public:
  enum class Type {
    Square = 0,
    Line,
    L,
    J,
    N,
    NMirrored,
    T
  };

  Piece(Type type);

  void draw(SDLRenderer &renderer, int rotation);

 private:
  std::vector<Vector2i> initial_positions_;
  std::vector< boost::shared_array<int> > rotations_;

  void create_square();
  void create_line();
  void create_l();
  void create_j();
  void create_n();
  void create_n_mirrored();
  void create_t();
};
