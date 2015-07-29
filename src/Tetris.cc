#include "Tetris.hpp"

Tetris::Tetris(SDLWindow &window)
    : renderer_(window),
      running_(false)
{
    renderer_.set_draw_color(0, 0, 0, 255);
    renderer_.clear();

    running_ = true;
}

Tetris::~Tetris()
{
    renderer_.destroy();
}

void Tetris::handle_events()
{
}

void Tetris::update()
{
}

void Tetris::draw()
{
}
