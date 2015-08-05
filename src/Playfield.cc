#include "Playfield.hpp"
#include "GLEWWrapper.hpp"
#include "Rectangle2d.hpp"
#include "TetrominoFactory.hpp"

#include <glm/glm.hpp>

Playfield::Playfield()
    : matrix_(10, 22, 0)
{
}


void Playfield::update()
{
}

void Playfield::draw()
{
    glBegin(GL_POINTS);

    glColor3f(1.f, 1.f, 1.f);

    for (int x = 0; x < matrix_.width(); ++x) {
        for (int y = 0; y < matrix_.height(); ++y) {
            glVertex2f(x * 32, y * 32);
        }
    }

    glEnd();

    for (int x = 0; x < matrix_.width(); x++) {
        for (int y = 0; y < matrix_.height(); y++) {
            if (matrix_(x, y) != 0) {
                Rectangle2d quad(Rectangle2d::Position(32 * x, 32 * y),
                                 Rectangle2d::Size(32, 32));

                quad.color(1.f, 0.f, 0.f);

                quad.draw();
            }
        }
    }

    auto tetromino = TetrominoFactory::create(Tetromino::Type::Z);

    tetromino->draw();
}
