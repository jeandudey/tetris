#include "Piece.hpp"

#include <iostream>

Piece::Piece(Type type)
    : initial_positions_(4),
      rotations_(4)
{
    switch (type) {
        case Type::Square:
            create_square();
            break;

        case Type::Line:
            create_line();
            break;

        case Type::L:
            create_l();
            break;

        case Type::J:
            create_j();
            break;

        case Type::N:
            create_n();
            break;

        case Type::NMirrored:
            create_n_mirrored();
            break;

        case Type::T:
            create_t();
            break;
    }
}

void Piece::draw(SDLRenderer &renderer, int rotation)
{
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            if (rotations_[rotation][x * y] != 0) {
                std::cout << "Hello, World" << std::endl;
                SDL_Rect block;
                block.x = x * 10;
                block.y = y * 10;
                block.w = 10;
                block.h = 10;

                renderer.draw_rectangle(&block);
            }
        }
    }
}

void Piece::create_square()
{
    initial_positions_[0] = Vector2i(-2, -3);
    initial_positions_[1] = Vector2i(-2, -3);
    initial_positions_[2] = Vector2i(-2, -3);
    initial_positions_[3] = Vector2i(-2, -3);

    boost::shared_array<int> array(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
            0, 0, 2, 1, 0,
            0, 0, 1, 1, 0,
            0, 0, 0, 0, 0
        }
    );

    for (int i = 0; i < rotations_.size(); i++)
        rotations_[i] = array;
}

void Piece::create_line()
{
    initial_positions_[0] = Vector2i(-2, -2);
    initial_positions_[1] = Vector2i(-2, -3);
    initial_positions_[2] = Vector2i(-2, -2);
    initial_positions_[3] = Vector2i(-2, -3);

    boost::shared_array<int> rot0(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
            0, 1, 2, 1, 1,
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    boost::shared_array<int> rot1(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 2, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 1, 0, 0
        }
    );

    boost::shared_array<int> rot2(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
            1, 1, 2, 1, 0,
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    boost::shared_array<int> rot3(new int[5 * 5]{
            0, 0, 1, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 2, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    rotations_[0] = rot0;
    rotations_[1] = rot1;
    rotations_[2] = rot2;
    rotations_[3] = rot3;
}

void Piece::create_l()
{
    initial_positions_[0] = Vector2i(-2, -3);
    initial_positions_[1] = Vector2i(-2, -3);
    initial_positions_[2] = Vector2i(-2, -3);
    initial_positions_[3] = Vector2i(-2, -2);

    boost::shared_array<int> rot0(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 2, 0, 0,
            0, 0, 1, 1, 0,
            0, 0, 0, 0, 0
        }
    );

    boost::shared_array<int> rot1(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
            0, 1, 2, 1, 0,
            0, 1, 0, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    boost::shared_array<int> rot2(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 1, 1, 0, 0,
            0, 0, 2, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    boost::shared_array<int> rot3(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 0, 1, 0,
            0, 1, 2, 1, 0,
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    rotations_[0] = rot0;
    rotations_[1] = rot1;
    rotations_[2] = rot2;
    rotations_[3] = rot3;
}

void Piece::create_j()
{
    initial_positions_[0] = Vector2i(-2, -3);
    initial_positions_[1] = Vector2i(-2, -2);
    initial_positions_[2] = Vector2i(-2, -3);
    initial_positions_[3] = Vector2i(-2, -3);

    boost::shared_array<int> rot0(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 2, 0, 0,
            0, 1, 1, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    boost::shared_array<int> rot1(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 1, 0, 0, 0,
            0, 1, 2, 1, 0,
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    boost::shared_array<int> rot2(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 1, 1, 0,
            0, 0, 2, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    boost::shared_array<int> rot3(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
            0, 1, 2, 1, 0,
            0, 0, 0, 1, 0,
            0, 0, 0, 0, 0
        }
    );

    rotations_[0] = rot0;
    rotations_[1] = rot1;
    rotations_[2] = rot2;
    rotations_[3] = rot3;
}

void Piece::create_n()
{
    initial_positions_[0] = Vector2i(-2, -3);
    initial_positions_[1] = Vector2i(-2, -3);
    initial_positions_[2] = Vector2i(-2, -3);
    initial_positions_[3] = Vector2i(-2, -2);

    boost::shared_array<int> rot0(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 0, 1, 0,
            0, 0, 2, 1, 0,
            0, 0, 1, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    boost::shared_array<int> rot1(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
            0, 1, 2, 0, 0,
            0, 0, 1, 1, 0,
            0, 0, 0, 0, 0
        }
    );

    boost::shared_array<int> rot2(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 1, 0, 0,
            0, 1, 2, 0, 0,
            0, 1, 0, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    boost::shared_array<int> rot3(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 1, 1, 0, 0,
            0, 0, 2, 1, 0,
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    rotations_[0] = rot0;
    rotations_[1] = rot1;
    rotations_[2] = rot2;
    rotations_[3] = rot3;
}

void Piece::create_n_mirrored()
{
    initial_positions_[0] = Vector2i(-2, -3);
    initial_positions_[1] = Vector2i(-2, -3);
    initial_positions_[2] = Vector2i(-2, -3);
    initial_positions_[3] = Vector2i(-2, -2);

    boost::shared_array<int> rot0(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 2, 1, 0,
            0, 0, 0, 1, 0,
            0, 0, 0, 0, 0
        }
    );

    boost::shared_array<int> rot1(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
            0, 0, 2, 1, 0,
            0, 1, 1, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    boost::shared_array<int> rot2(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 1, 0, 0, 0,
            0, 1, 2, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    boost::shared_array<int> rot3(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 1, 1, 0,
            0, 1, 2, 0, 0,
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    rotations_[0] = rot0;
    rotations_[1] = rot1;
    rotations_[2] = rot2;
    rotations_[3] = rot3;
}

void Piece::create_t()
{
    initial_positions_[0] = Vector2i(-2, -3);
    initial_positions_[1] = Vector2i(-2, -3);
    initial_positions_[2] = Vector2i(-2, -3);
    initial_positions_[3] = Vector2i(-2, -2);

    boost::shared_array<int> rot0(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 2, 1, 0,
            0, 0, 1, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    boost::shared_array<int> rot1(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0,
            0, 1, 2, 1, 0,
            0, 0, 1, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    boost::shared_array<int> rot2(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 1, 0, 0,
            0, 1, 2, 0, 0,
            0, 0, 1, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    boost::shared_array<int> rot3(new int[5 * 5]{
            0, 0, 0, 0, 0,
            0, 0, 1, 0, 0,
            0, 1, 2, 1, 0,
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 0
        }
    );

    rotations_[0] = rot0;
    rotations_[1] = rot1;
    rotations_[2] = rot2;
    rotations_[3] = rot3;
}
