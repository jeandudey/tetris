#pragma once

template<typename T>
struct Color {
 public:
  Color(T r_, T g_, T b_)
    : r(r_), g(g_), b(b_) {}

  T r;
  T g;
  T b;
};
