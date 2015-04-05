//
// NcursesGraphic.hpp for NcursesGraphic.hpp in /home/han_d/Github/cpp_nibbler
// 
// Made by Daniel Han
// Login   <han_d@epitech.net>
// 
// Started on  Sat Apr  4 17:05:23 2015 Daniel Han
// Last update Sun Apr  5 11:32:07 2015 Jonathan Quach
//

#ifndef NCURSESGRAPHIC_HPP_
# define NCURSESGRAPHIC_HPP_

#include <ncurses.h>
// #include <curses.h>
#include "IGui.hpp"
#include "Event.hpp"
#include "ErrorException.hpp"

class NcursesGraphic : public IGui
{
  //
  // Attributs
  //
private:
  WINDOW *_window;

public:
  NcursesGraphic();
  virtual ~NcursesGraphic();

public:
  virtual void createWindow(int, int);
  virtual void drawSquare(int, int, ObjectType);
  virtual void removeSquare(int, int);
  virtual EventType updateEvent();
};

extern "C"
{
  IGui *create_lib_instance();
}

#endif /* !NCURSESGRAPHIC_HPP_ */
