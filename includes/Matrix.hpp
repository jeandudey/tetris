#pragma once

template<typename T>
class Matrix {
 public:
  Matrix(int width, int height, T initial_value)
    : width_(width),
      height_(height),
      matrix_(nullptr)
  {
    matrix_ = new T[width_ * height_];

    for (int x = 0; x < width_; x++) {
        for (int y = 0; y < height_; y++) {
            matrix_[x + width_ * y] = initial_value;
        }
    }
  }

  ~Matrix()
  {
    delete[] matrix_;
  }

  // Get matrix value at the given x, y.
  T &operator()(int x, int y)
  {
      return matrix_[x + width_ * y];
  }

  int width() const
  {
      return width_;
  }

  int height() const
  {
      return height_;
  }

  using type = T;

 private:
  int width_;
  int height_;
  T *matrix_;
};
