//
// Snake.hpp for Snake.hpp in /home/han_d/Github/cpp_nibbler
// 
// Made by Daniel Han
// Login   <han_d@epitech.net>
// 
// Started on  Sun Apr  5 07:25:22 2015 Daniel Han
// Last update Sun Apr  5 07:25:45 2015 Daniel Han
//

#ifndef _SNAKE_HPP_
# define _SNAKE_HPP_

#include <list>
#include "Event.hpp"
#include "Position.hpp"
#include "IGui.hpp"
#include "Map.hpp"

#define MAX_SPEED 20000

class Snake
{
  //
  // Attributs
  //
private:
  bool god_mode;
  int x;
  int y;
  int size;
  int speed;
  IGui *gui;
  std::list<Position> body;

  //
  // Coplien form
  //
public:
  Snake(int const, int const, IGui *);
  Snake(Snake const &);
  Snake &operator=(Snake const &);
  ~Snake();

  //
  // Getters & Setters
  //
public:
  int getSize() const;
  int getSpeed() const;
  void setSpeed(int const);
  void setGodMode();

  //
  // Display/Modify Snake
  //
public:
  void growUp(int const, int const, Map &);
  void addSnakeInMap(Map &);
  EventType move(EventType const, Map &);
  EventType checkObject(Map &);

};

#endif /* !_SNAKE_HPP_ */
