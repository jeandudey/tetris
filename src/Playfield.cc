#include "Playfield.hpp"
#include "GLEWWrapper.hpp"
#include "Rectangle2d.hpp"

#include <glm/glm.hpp>
#include <iostream>

Playfield::Playfield()
    : matrix_(10, 22, 0)
{
    matrix_(0, 0) = 1;
}


void Playfield::update()
{
}

void Playfield::draw()
{
    for (int x = 0; x < matrix_.width(); x++) {
        for (int y = 0; y < matrix_.height(); y++) {
            if (matrix_(x, y) != 0) {
                Rectangle2d block(Rectangle2d::Position(32 * x, 32 * y),
                                  Rectangle2d::Size(32, 32));

                block.color(1.f, 0.f, 0.f);

                block.draw();
            }
        }
    }
}
