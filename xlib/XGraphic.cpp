//
// XGraphic.cpp for qsd in /home/saysan_j/cpp_nibbler/xlib
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Sun Apr  5 05:29:49 2015 Jean-Paul SAYSANA
// Last update Sun Apr  5 10:45:03 2015 Jean-Paul SAYSANA
//

#include <iostream>
#include "XGraphic.hpp"

XGraphic::XGraphic()
{
  if ((this->d = XOpenDisplay(NULL)) == NULL)
    throw ErrorException ("Can't display X server.");
  this->s = DefaultScreen(d);
}

XGraphic::~XGraphic()
{

}

void		XGraphic::createWindow(int x, int y)
{
  this->w = XCreateSimpleWindow(d, RootWindow(d, s), 0, 0, x, y, 10, WhitePixel(d, s), WhitePixel(d, s));
  Atom		delWindow = XInternAtom( d, "WM_DELETE_WINDOW", 0 );
  XSetWMProtocols(d , w, &delWindow, 1);
  XSelectInput(d, w, ExposureMask | KeyPressMask);
  XMapWindow(d, w);
  XNextEvent(d, &e);
}

EventType	XGraphic::updateEvent()
{
  if (XPending(this->d) > 0)
    {
      XNextEvent(d, &e);
      while (XPending(d) > 0)
	XNextEvent(this->d, &e);
      switch (XLookupKeysym(&e.xkey, 0))
	if(e.type == KeyPress)
	  {
	  case (65293): //ENTER
	    return (ENTER);
	  case (65363): //LEFT
	    return (LEFT);
	  case (65361): //RIGHT
	    return (RIGHT);
	  case (65307):
	    return (QUIT);
	  default:
	    return NONE;
	  }
    }
  return NONE;
}

void		XGraphic::drawSquare(int x, int y, ObjectType type)
{
  switch (type)
    {
    case HEAD:
    case BODY:
      XSetForeground(d, DefaultGC(d, s), 26112);
      break;
    case WALL:
    case BLOCK:
      XSetForeground(d, DefaultGC(d, s), 6684672);
      break;
    case FOOD:
    case POISON:
      XSetForeground(d, DefaultGC(d, s), 3381759);
      break;
    case NOTHING:
      XSetForeground(d, DefaultGC(d, s), 32000);
      break;
    }
  XFillArc(d, w, DefaultGC(d, s), x * 20, y * 20, 20, 20, 0, 360 * 64);
}

void		XGraphic::removeSquare(int x, int y)
{
  XSetForeground(d, DefaultGC(d, s), WhitePixel(d, s));
  XFillArc(d, w, DefaultGC(d, s), x * 20, y * 20, 20, 20, 0, 360 * 64);
}

extern "C"
{
  IGui *create_lib_instance()
  {
    return new XGraphic;
  }
}

