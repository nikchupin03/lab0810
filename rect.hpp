#pragma once

#include <iostream>

template <typename T>
class Rectangle {
 private:
  T x_pos;
  T y_pos;
  int height;
  int width;

 public:
  const T get_x();
  const T get_y();
  const T get_h();
  const T get_w();

  bool set_x(T x);
  bool set_y(T y);
  bool set_h(T h);
  bool set_w(T w);

  friend Rectangle combination(Rectangle* rect1, Rectangle* rect2);
  friend Rectangle intersection(Rectangle* rect1, Rectangle* rect2);

  virtual void show();

  Rectangle();
  Rectangle(T h, T w);
  Rectangle(T h, T w, T x, T y);
  ~Rectangle();

  operator Rectangle() { return Rectangle(); }

};
