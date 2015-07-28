#pragma once

class Pieces {
 public:
  static int block_type(int piece, int rotation, int x, int y);
  static int x_initial_position(int piece, int rotation);
  static int y_initial_position(int piece, int rotation);
};
