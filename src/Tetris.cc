#include "Tetris.hpp"

Tetris::Tetris(SDLWindow &window)
    : context_(window),
      window_(window),
      glew_(),
      quad_(Rectangle2d::Position(0.25f, 0.25f),
            Rectangle2d::Size(0.5f, 0.5f)),
      running_(false)
{
    context_.swap_interval(1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.f, 0.f, 0.f, 1.f);

    running_ = true;
}

Tetris::~Tetris()
{
}

void Tetris::handle_events()
{
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_QUIT:
                running_ = false;
                break;
        }
    }
}

void Tetris::update()
{
}

void Tetris::draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    quad_.draw();
}
