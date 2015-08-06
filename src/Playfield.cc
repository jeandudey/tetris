#include "Playfield.hpp"
#include "GLEWWrapper.hpp"
#include "Rectangle2d.hpp"
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

                quad.color(.7f, 0.f, 0.f);

                quad.draw();
            }
        }
    }
}

void Playfield::store_tetromino(Tetromino *tetromino)
{
    for (int x1 = tetromino->position().x, x2 = 0; x1 < tetromino->position().x + 5; x1++, x2++) {
        for (int y1 = tetromino->position().y, y2 = 0; y1 < tetromino->position().y + 5; y1++, y2++) {
            if (tetromino->block_type(tetromino->rotation(), y2, x2) != 0)
                matrix_(x1, y1) = 1;
        }
    }
}
