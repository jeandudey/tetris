#pragma once

#include "Board.hpp"
#include "SDLWrapper.hpp"

class Game {
 public:
  Game(Board *board, SDLRenderer *renderer, int screen_height);

  void draw_scene();
  void create_new_piece();

  int pos_x, pos_y;
  int piece, rotation;

 private:
  int screen_height_;
  int next_pos_x_,
      next_pos_y_;
  int next_piece_,
      next_rotation_;

  Board *board_;
  SDLRenderer *renderer_;

  static int get_rand(int a, int b);
  void init_game();
  void draw_piece(int x, int y, int piece, int rotation);
};
