#include "Tetris.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <random>

Tetris::Tetris(SDLWindow &window)
    : context_(window),
      window_(window),
      glew_(),
      playfield_(),
      current_tetromino_(TetrominoFactory::random_tetromino()),
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

    timer_.start();

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

            case SDL_KEYDOWN:
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        if (current_tetromino_->is_possible_movement(
                            Tetromino::MovementType::Left,
                            playfield_.matrix()))
                            current_tetromino_->move(Tetromino::MovementType::Left);
                        break;

                    case SDLK_RIGHT:
                        if (current_tetromino_->is_possible_movement(
                            Tetromino::MovementType::Right,
                            playfield_.matrix()))
                            current_tetromino_->move(Tetromino::MovementType::Right);
                        break;

                    case SDLK_UP:
                        if (current_tetromino_->is_possible_movement(
                            Tetromino::MovementType::Rotate,
                            playfield_.matrix()))
                            current_tetromino_->move(Tetromino::MovementType::Rotate);
                        break;
                }
                break;
        }
    }
}

void Tetris::update()
{
    if (timer_.get_ticks() > 700) {
        if (current_tetromino_->is_possible_movement(
            Tetromino::MovementType::Advance,
            playfield_.matrix()))
            current_tetromino_->move(Tetromino::MovementType::Advance);

        timer_.start();
    }
}

void Tetris::draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    current_tetromino_->draw();
    playfield_.draw();
}
