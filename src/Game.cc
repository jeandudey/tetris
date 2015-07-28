#include "Game.hpp"
#include "Pieces.hpp"

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

Game::Game(Board *board, SDLRenderer *renderer, int screen_height)
    : board_(board),
      pos_x(0),
      pos_y(0),
      piece(0),
      next_pos_x_(0),
      next_pos_y_(0),
      next_piece_(0),
      next_rotation_(0),
      renderer_(renderer),
      screen_height_(screen_height)
{}

int Game::get_rand(int a, int b)
{
    boost::random::mt19937 gen;
    boost::random::uniform_int_distribution<> dist(a, b);
    return dist(gen);
}

void Game::init_game()
{
    piece = get_rand(0, 6);
    rotation = get_rand(0, 3);

    pos_x = (10 / 2) + Pieces::x_initial_position (piece, rotation);
    pos_y = Pieces::y_initial_position (piece, rotation);

    next_piece_ = get_rand(0, 6);
    next_rotation_ = get_rand(0, 3);
    next_pos_x_ = 10 + 5;
    next_pos_y_ = 5;
}

void Game::create_new_piece()
{
    piece = next_piece_;
    rotation = next_rotation_;
    pos_x = (10 / 2) + Pieces::x_initial_position(piece, rotation);
    pos_y = Pieces::y_initial_position(piece, rotation);

    next_piece_ = get_rand(0, 6);
    next_rotation_ = get_rand(0, 3);
}

void Game::draw_piece(int piece, int rotation, int x, int y)
{
    int pixels_x = board_->x_pos_in_pixels(x);
    int pixels_y = board_->y_pos_in_pixels(y);

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            switch (Pieces::block_type(piece, rotation, x, y))
            {
                case 1:
                    renderer_->set_draw_color(0, 255, 0, 255);
                    break;

                case 2:
                    renderer_->set_draw_color(0, 0, 255, 255);
                    break;
            }

            if (Pieces::block_type(piece, rotation, x, y) != 0) {
                SDL_Rect block;
                block.x = pixels_x + x * 16;
                block.y = pixels_y + y * 16;
                block.w = 16;
                block.h = 16;

                renderer_->draw_rectangle(&block);
            }
        }
    }
}

void Game::draw_scene()
{
    draw_piece(pos_x, pos_y, piece, rotation);
    draw_piece(next_pos_x_, next_pos_y_, next_piece_, next_rotation_);
}
