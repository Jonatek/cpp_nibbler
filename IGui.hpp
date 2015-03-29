//
// IGui.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Tue Mar 24 20:34:14 2015 Jonathan Quach
// Last update Sun Mar 29 19:35:36 2015 Jonathan Quach
//

#ifndef _IGUI_HPP_
# define _IGUI_HPP_

#include "Event.hpp"

class IGui
{
public:
  virtual ~IGui() {};

  virtual void createWindow(int const &x, int const &y) = 0;
  virtual void drawSquare(int const &x, int const &y, ElementType) = 0;
  virtual void removeSquare(int const &x, int const &y) = 0;
  virtual void updateEvent(Event &) = 0;
  // virtual void clearWindow() = 0;
  // virtual void drawWindow() = 0;
};

#endif
