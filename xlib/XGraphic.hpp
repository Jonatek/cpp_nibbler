//
// XGraphic.hpp for qsd in /home/saysan_j/cpp_nibbler/xlib
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Sun Apr  5 05:29:48 2015 Jean-Paul SAYSANA
// Last update Sun Apr  5 10:21:37 2015 Jean-Paul SAYSANA
//

#ifndef _XGRAPHIC_HPP
# define _XGRAPHIC_HPP

#include <SDL/SDL.h>
#include <string>
#include <vector>
#include "../IGui.hpp"
#include "../ErrorException.hpp"
#include "../Event.hpp"
#include "../Map.hpp"
#include <X11/Xlib.h>

class		XGraphic : public IGui
{
private:
  Display *d;
  int s;
  Window w;
  XEvent e;

public:
  XGraphic();
  virtual ~XGraphic();

  virtual void createWindow(int, int);
  virtual EventType updateEvent();
  virtual void drawSquare(int, int, ObjectType);
  virtual void removeSquare(int, int);
};

extern "C"
{
  IGui *create_lib_instance();
}

#endif
