//
// NcursesGraphic.cpp for NcursesGraphic.cpp in /home/han_d/Github/cpp_nibbler
// 
// Made by Daniel Han
// Login   <han_d@epitech.net>
// 
// Started on  Sat Apr  4 17:05:34 2015 Daniel Han
// Last update Sun Apr  5 11:44:38 2015 Jonathan Quach
//

#include <iostream>
#include "NcursesGraphic.hpp"

NcursesGraphic::NcursesGraphic()
{
  initscr();
  keypad(stdscr, true);
  noecho();
  nodelay(stdscr, TRUE);
  curs_set(0);
  start_color();
  has_colors();
  init_pair(1, COLOR_BLACK, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLACK, COLOR_MAGENTA);
  init_pair(5, COLOR_RED, COLOR_BLACK);
  refresh();
}

NcursesGraphic::~NcursesGraphic()
{
  if (this->_window != NULL)
    delwin(this->_window);
  endwin();
  std::cout << "destroyed window " << std::endl;
}

void NcursesGraphic::createWindow(int x, int y)
{
  this->_window = newwin(y * 20, x * 20, 0, 0);
  wrefresh(this->_window);
}

void NcursesGraphic::drawSquare(int x, int y, ObjectType type)
{
  if (type == HEAD)
    mvwaddch(this->_window, y, x, 'O');
  else if (type == BODY)
    mvwaddch(this->_window, y, x, 'o');
  else if (type == WALL)
    mvwaddch(this->_window, y, x, '#');
  else if (type == FOOD)
    mvwaddch(this->_window, y, x, '@');
  else
    mvwaddch(this->_window, y, x, ' ');
  wrefresh(this->_window);
}

void NcursesGraphic::removeSquare(int x, int y)
{
  mvwaddch(this->_window, y, x, ' ');
}

EventType NcursesGraphic::updateEvent()
{
  int	ch;

  ch = getch();
  // std::cout << "ch == " << ch << std::endl;
  switch (ch)
    {
    case KEY_LEFT:
      return LEFT;
    case KEY_RIGHT:
      return RIGHT;
    case 10: // ENTER
      return ENTER;
    case 27:
      return QUIT;
    case 32:
      return SPACE;
    case 112:
      return PAUSE;
    case 103:
      return GOD_MODE;
    case 102:
      return FOOD_PUSH;
    }
  return NONE;
}

extern "C"
{
  IGui *create_lib_instance()
  {
    return new NcursesGraphic;
  }
}
