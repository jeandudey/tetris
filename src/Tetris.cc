#include "Tetris.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

Tetris::Tetris(SDLWindow &window)
    : context_(window),
      window_(window),
      glew_(),
      quad_(Rectangle2d::Position(),
            Rectangle2d::Size(50, 50)),
      running_(false)
{
    context_.swap_interval(1);

    glm::vec2 wsize(window_.width(), window_.height());

    glViewport(0, 0, wsize.x, wsize.y);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glm::mat4 ortho = glm::ortho(0.f, wsize.x, wsize.y, 0.f);

    glMultMatrixf(glm::value_ptr(ortho));

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
