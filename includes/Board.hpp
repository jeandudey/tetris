#pragma once

class Board {
 public:
  Board(int screen_height);
  int x_pos_in_pixels(int pos);
  int y_pos_in_pixels(int pos);

  bool is_free_block(int x, int y);
  bool is_possible_movement(int x, int y, int piece, int rotation);
  void store_piece(int x, int y, int piece, int rotation);

  void delete_possible_lines();
  bool is_game_over();

 private:
  enum { POS_FREE, POS_FILLED };

  int board_[10][20];
  int screen_height_;

  void init_board();
  void delete_line(int y);
};
