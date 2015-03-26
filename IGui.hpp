//
// IGui.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Tue Mar 24 20:34:14 2015 Jonathan Quach
// Last update Thu Mar 26 23:40:06 2015 Jonathan Quach
//

#ifndef _IGUI_HPP_
# define _IGUI_HPP_

#include "Event.hpp"

class IGui
{
public:
  virtual ~IGui() {};

  virtual void createWindow(const int &x, const int &y) = 0;
  // virtual void drawSquare() = 0;
  virtual void updateEvent(Event &) = 0;
  // virtual void clearWindow() = 0;
  // virtual void drawWindow() = 0;
};

#endif
