//
// NcursesGraphic.cpp for NcursesGraphic.cpp in /home/han_d/Github/cpp_nibbler
// 
// Made by Daniel Han
// Login   <han_d@epitech.net>
// 
// Started on  Sat Apr  4 17:05:34 2015 Daniel Han
// Last update Sun Apr  5 01:54:21 2015 Daniel Han
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
}

void NcursesGraphic::createWindow(int x, int y)
{
  this->_window = newwin(y * 20, x * 20, 0, 3);
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

EventType NcursesGraphic::updateEvent(Event & _newEvent)
{
  int	ch;

  ch = getch();
  switch (ch)
    {
    case KEY_LEFT:
      _newEvent.setEventType(LEFT);
      break;
    case KEY_RIGHT:
      _newEvent.setEventType(RIGHT);
      break;
    case KEY_ENTER:
      _newEvent.setEventType(ENTER);
      break;
    case 27:
      _newEvent.setEventType(QUIT);
      break;
    }
  return (_newEvent.getEventType());
}

extern "C"
{
  IGui *create_lib_instance()
  {
    return new NcursesGraphic;
  }
}
