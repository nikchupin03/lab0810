#include <iostream>

#include "rect.hpp"

int menu() {
  std::cout << "Выберите один из вариантов:\n 1. "
               "Изменить характеристику прямоугольника\n 2. Получить "
               "характеристику прямоугольника\n 3. Получить пересечение "
               "прямоугольников\n 4. Получить прямоугольник вмещающий оба\n 0. "
               "Завершить\n>> "
            << std::flush;
  char buf = 0;
  std::cin >> buf;
  std::cin.ignore();
  return int(buf - '0');
}

void change(Rectangle* rect1, Rectangle* rect2) {
  std::cout << "  Выберите прямоугольник (1/2)\n  >> " << std::flush;
  char buf = 0;
  int buf_int = 0;
  std::cin >> buf;
  std::cin.ignore();
  Rectangle* rect = NULL;
  if (buf == '1') {
    rect = rect1;
  } else if (buf == '2') {
    rect = rect2;
  } else {
    std::cout << "  Такого прямоугольника нет\n";
    return;
  }
  std::cout << "  Выберите характеристику (h/w/x/y)\n  >> " << std::flush;
  std::cin >> buf;
  std::cin.ignore();
  std::cout << "  Введите значение\n  >> " << std::flush;
  std::cin >> buf_int;
  std::cin.ignore();
  switch (buf) {
    case 'h':
      rect->set_h(buf_int);
      std::cout << "h = " << rect->get_h() << std::endl;
      break;
    case 'w':
      rect->set_w(buf_int);
      std::cout << "w = " << rect->get_w() << std::endl;
      break;
    case 'x':
      rect->set_x(buf_int);
      std::cout << "x = " << rect->get_x() << std::endl;
      break;
    case 'y':
      rect->set_y(buf_int);
      std::cout << "y = " << rect->get_y() << std::endl;
      break;

    default:
      break;
  }
}
void get(Rectangle* rect1, Rectangle* rect2) {
  std::cout << "  Выберите прямоугольник (1/2)\n  >> " << std::flush;
  char buf = 0;
  std::cin >> buf;
  std::cin.ignore();
  Rectangle* rect = NULL;
  if (buf == '1') {
    rect = rect1;
  } else if (buf == '2') {
    rect = rect2;
  } else {
    std::cout << "  Такого прямоугольника нет\n";
    return;
  }
  std::cout << "  Выберите характеристику (h/w/x/y)\n  >> " << std::flush;
  std::cin >> buf;
  std::cin.ignore();
  switch (buf) {
    case 'h':
      std::cout << "h = " << rect->get_h() << std::endl;
      break;
    case 'w':
      std::cout << "w = " << rect->get_w() << std::endl;
      break;
    case 'x':
      std::cout << "x = " << rect->get_x() << std::endl;
      break;
    case 'y':
      std::cout << "y = " << rect->get_y() << std::endl;
      break;

    default:
      std::cout << "  Такой характеристики нет\n";
      break;
  }
}
void inter(Rectangle* rect1, Rectangle* rect2) {
  std::cout << "  Пересечение прямоугольников 1 и 2: " << std::flush;
  Rectangle rect = rect1->intersection(rect2);
  rect.show();
}
void comb(Rectangle* rect1, Rectangle* rect2) {
  std::cout << "  Объединение прямоугольников 1 и 2: " << std::flush;
  Rectangle rect = rect1->combination(rect2);
  rect.show();
}

int main() {
  int run = true;
  int menu_choose = -1;
  int buf = 0;
  Rectangle rect1;
  Rectangle rect2;
  while (run) {
    switch (menu()) {
      case 0:
        run = false;
        break;
      case 1:
        change(&rect1, &rect2);
        break;
      case 2:
        get(&rect1, &rect2);
        break;
      case 3:
        inter(&rect1, &rect2);
        break;
      case 4:
        comb(&rect1, &rect2);
        break;
    }
  }

  return 0;
}