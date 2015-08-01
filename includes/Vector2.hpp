#pragma once

template<typename T>
struct Vector2 {
 public:
  Vector2()
    : x(0),
      y(0) {}

  Vector2(T x1, T y1)
    : x(x1),
      y(y1) {}

  using type = T;

  T x;
  T y;
};

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;
