#pragma once

#include <iostream>

class Rectangle {
 private:
  int x_pos;
  int y_pos;
  int height;
  int width;

 public:
  int get_x();
  int get_y();
  int get_h();
  int get_w();

  bool set_x(int x);
  bool set_y(int y);
  bool set_h(int h);
  bool set_w(int w);

  static Rectangle combination_static(Rectangle* rect1, Rectangle* rect2);
  Rectangle combination(Rectangle* rect);

  static Rectangle intersection_static(Rectangle* rect1, Rectangle* rect2);
  Rectangle intersection(Rectangle* rect);

  void show();

  Rectangle();
  Rectangle(int h, int w);
  Rectangle(int h, int w, int x, int y);
  ~Rectangle();
};
