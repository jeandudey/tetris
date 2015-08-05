#include "Rectangle2d.hpp"

Rectangle2d::Rectangle2d(const Position &position, const Size &size)
    : position_(position),
      size_(size)
{
}

void Rectangle2d::color(const float r, const float g, const float b)
{
    r_ = r;
    g_ = g;
    b_ = b;
}

void Rectangle2d::update(const Position &position, const Size &size)
{
    position_ = position;
    size_ = size;
}

void Rectangle2d::draw()
{
    glColor3f(r_, g_, b_);

    glBegin(GL_QUADS);

    // A
    glVertex2f(position_.x, position_.y);
    // B
    glVertex2f(position_.x + size_.x, position_.y);
    // C
    glVertex2f(position_.x + size_.x, position_.y + size_.y);
    // D
    glVertex2f(position_.x, position_.y + size_.y);

    glEnd();

    glColor3f(1.f, 1.f, 1.f);
}
