#include "Board.hpp"
#include "Pieces.hpp"

Board::Board(int screen_height)
    : screen_height_(screen_height)
{
    for (int x = 0; x < 10; x++)
        for (int y = 0; y < 20; x++)
            board_[x][y] = POS_FREE;
}

void Board::store_piece(int x, int y, int piece, int rotation)
{
    for (int x1 = x, x2 = 0; x1 < x + 5; x1++, x2++)
    {
        for (int y1 = y, y2 = 0; y1 < y + 5; y1++, y2++)
        {
            if (Pieces::block_type(piece, rotation, x2, y2) != 0)
                board_[x1][y1] = POS_FILLED;
        }
    }
}

bool Board::is_game_over()
{
    for (int x = 0; x < 10; x++) {
        if (board_[x][0] == POS_FILLED)
            return true;
    }

    return false;
}

void Board::delete_line(int y)
{
    for (int y1 = y; y1 > 0; y1--)
    {
        for (int x = 0; x < 20; x++)
            board_[x][y1] = board_[x][y1 - 1];
    }
}

void Board::delete_possible_lines()
{
    for (int y = 0; y < 20; y++) {
        int x = 0;
        while (x < 10)
        {
            if (board_[x][y] != POS_FILLED)
                break;
            x++;
        }

        if (x == 10)
            delete_line(y);
    }
}

bool Board::is_free_block(int x, int y)
{
    return (board_[x][y] == POS_FREE);
}

int Board::x_pos_in_pixels(int pos)
{
    return ( ( 320 - (16 * (10 / 2)) ) + (pos * 16) );
}

int Board::y_pos_in_pixels(int pos)
{
    return ( (screen_height_ - (16 * 20)) + (pos * 16) );
}

bool Board::is_possible_movement(int x, int y, int piece, int rotation)
{
    for (int x1 = x, x2 = 0; x1 < x + 5; x1++, x2++)
    {
        for (int y1 = y, y2 = 0; y1 < y + 5; y1++, y2++)
        {
            if (x1 < 0 || x1 > 10  - 1 || y1 > 20 - 1) {
                if (Pieces::block_type(piece, rotation, x2, y2) != 0)
                    return false;
            }

            if (y1 >= 0) {
                if (Pieces::block_type(piece, rotation, x2, y2) != 0 &&
                    !is_free_block(x1, y1))
                    return false;
            }
        }
    }

    // No collision
    return true;
}
