#include "rect.hpp"

#include <iostream>

int Rectangle::get_x() { return x_pos; }
int Rectangle::get_y() { return y_pos; }
int Rectangle::get_h() { return height; }
int Rectangle::get_w() { return width; }

bool Rectangle::set_x(int x) {
  x_pos = x;
  return true;
}
bool Rectangle::set_y(int y) {
  y_pos = y;
  return true;
}
bool Rectangle::set_h(int h) {
  height = h;
  return true;
}
bool Rectangle::set_w(int w) {
  width = w;
  return true;
}

int _max(int a, int b) { return (a > b ? a : b); }
int _min(int a, int b) { return (a > b ? b : a); }

Rectangle Rectangle::combination(Rectangle* rect1, Rectangle* rect2) {
  int max_x = _max(
      _max(rect1->get_x(), rect2->get_x()),
      _max(rect1->get_x() + rect1->get_w(), rect2->get_x() + rect2->get_w()));
  int min_x = _min(
      _min(rect1->get_x(), rect2->get_x()),
      _min(rect1->get_x() + rect1->get_w(), rect2->get_x() + rect2->get_w()));
  int max_y = _max(
      _max(rect1->get_y(), rect2->get_y()),
      _max(rect1->get_y() + rect1->get_h(), rect2->get_y() + rect2->get_h()));
  int min_y = _min(
      _min(rect1->get_y(), rect2->get_y()),
      _min(rect1->get_y() + rect1->get_h(), rect2->get_y() + rect2->get_h()));
  return Rectangle(max_x - min_x, max_y - min_y, min_x, min_y);
}

Rectangle Rectangle::intersection(Rectangle* rect1, Rectangle* rect2) {
  int max_x1 = _max(rect1->get_x(), rect1->get_x() + rect1->get_w());
  int min_x1 = _min(rect1->get_x(), rect1->get_x() + rect1->get_w());
  int max_x2 = _max(rect2->get_x(), rect2->get_x() + rect2->get_w());
  int min_x2 = _min(rect2->get_x(), rect2->get_x() + rect2->get_w());
  if ((min_x2 > max_x1) || (min_x1 > max_x2)) {
    return Rectangle();
  }
  int max_y1 = _max(rect1->get_y(), rect1->get_y() + rect1->get_h());
  int min_y1 = _min(rect1->get_y(), rect1->get_y() + rect1->get_h());
  int max_y2 = _max(rect2->get_y(), rect2->get_y() + rect2->get_h());
  int min_y2 = _min(rect2->get_y(), rect2->get_y() + rect2->get_h());
  if ((min_y2 > max_y1) || (min_y1 > max_y2)) {
    return Rectangle();
  }
  int x1 = _max(min_x1, min_x2);
  int x2 = _min(max_x1, max_x2);
  int y1 = _max(min_y1, min_y2);
  int y2 = _min(max_y1, max_y2);
  return Rectangle(y2 - y1, x2 - x1, x1, y1);
}

void Rectangle::show() {
  std::cout << "x: " << x_pos << " "
            << "y: " << y_pos << " "
            << "h: " << height << " "
            << "w: " << width << std::endl;
}

Rectangle::Rectangle() {
  x_pos = 0;
  y_pos = 0;
  height = 0;
  width = 0;
}
Rectangle::Rectangle(int h, int w) {
  x_pos = 0;
  y_pos = 0;
  height = h;
  width = w;
}
Rectangle::Rectangle(int h, int w, int x, int y) {
  x_pos = x;
  y_pos = y;
  height = h;
  width = w;
}
Rectangle::~Rectangle() {}