//
// IGui.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Tue Mar 24 20:34:14 2015 Jonathan Quach
// Last update Sun Apr  5 07:11:23 2015 Daniel Han
//

#ifndef _IGUI_HPP_
# define _IGUI_HPP_

#include "Event.hpp"

typedef enum
  {
    NOTHING,
    WALL,
    BLOCK,
    HEAD,
    BODY,
    FOOD,
    POISON
  } ObjectType;

class IGui
{
public:
  virtual ~IGui() {};

public:
  virtual void createWindow(int const, int const) = 0;
  virtual void drawSquare(int const, int const y, ObjectType const) = 0;
  virtual void removeSquare(int const, int const) = 0;
  virtual EventType updateEvent() = 0;
  // virtual void clearWindow() = 0;
  // virtual void drawWindow() = 0;

};

#endif /* !_IGUI_HPP_ */
