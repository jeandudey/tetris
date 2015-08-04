#include "Rectangle2d.hpp"

Rectangle2d::Rectangle2d(const Position &position, const Size &size)
    : position_(position),
      size_(size)
{
}

void Rectangle2d::color(const float r, const float b, const float g)
{
    r_ = r;
    b_ = b;
    g_ = g;
}

void Rectangle2d::update(const Position &position, const Size &size)
{
    position_ = position;
    size_ = size;
}

void Rectangle2d::draw()
{
    glColor3f(r_, b_, g_);

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
