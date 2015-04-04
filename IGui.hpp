//
// IGui.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Tue Mar 24 20:34:14 2015 Jonathan Quach
// Last update Sat Apr  4 12:38:38 2015 Jonathan Quach
//

#ifndef _IGUI_HPP_
# define _IGUI_HPP_

#include "Event.hpp"

typedef enum
  {
    NOTHING,
    WALL,
    HEAD,
    BODY,
    FOOD
  } ObjectType;

class IGui
{
public:
  virtual ~IGui() {};

  virtual void createWindow(int x, int y) = 0;
  virtual void drawSquare(int x, int y, ObjectType) = 0;
  virtual void removeSquare(int x, int y) = 0;
  virtual EventType updateEvent() = 0;
  // virtual void clearWindow() = 0;
  // virtual void drawWindow() = 0;
};

#endif
