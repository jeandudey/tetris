#include "Rectangle2d.hpp"

Rectangle2d::Rectangle2d(const Position &pos, const Size &sz)
    : position(pos),
      size(sz)
{
}

void Rectangle2d::update(const Position &pos, const Size &sz)
{
    position = pos;
    size = sz;
}

void Rectangle2d::draw()
{
    glBegin(GL_QUADS);

    // A
    glVertex2f(position.x, position.y);
    // B
    glVertex2f(position.x + size.x, position.y);
    // C
    glVertex2f(position.x + size.x, position.y + size.y);
    // D
    glVertex2f(position.x, position.y + size.y);

    glEnd();
}
