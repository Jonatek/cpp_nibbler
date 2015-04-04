//
// snake.cpp for qsd in /home/saysan_j/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Tue Mar 24 12:26:42 2015 Jean-Paul SAYSANA
// Last update Sat Apr  4 16:15:26 2015 Daniel Han
//

#include <iostream>
#include "Snake.hpp"

Snake::Snake(int _x, int _y, IGui *_gui)
  : x(_x), y(_y), snakeSize(4), gui(_gui)
{
  body.push_back(Position(x / 2 , y / 2));
  body.push_back(Position(x / 2 - 1, y / 2));
  body.push_back(Position(x / 2 - 2, y / 2));
  body.push_back(Position(x / 2 - 3, y / 2));
  body.push_back(Position(x / 2 - 4, y / 2));
  body.push_back(Position(x / 2 - 5, y / 2));
  body.push_back(Position(x / 2 - 6, y / 2));
  body.push_back(Position(x / 2 - 7, y / 2));
  for (std::list<Position>::iterator it = body.begin(); it != body.end(); ++it)
    {
      std::cout << it->getX() << " " << it->getY() << std::endl;
      gui->drawSquare(it->getX(), it->getY(), BODY);
    }
}

void		Snake::growUp()
{
  this->snakeSize += 1;
}

EventType	Snake::checkObject(Map &map)
{
  int		x = body.begin()->getX();
  int		y = body.begin()->getY();
  ObjectType	obj;

  obj = map.getObject(x, y);
  if (obj == WALL || obj == BODY)
    {
      std::cout << "DIIIIIIIIIIIIIIIIIEEEEEE BITCH" << std::endl;
      return QUIT;
    }
  return NONE;
}

EventType	 Snake::move(EventType direction, Map &map)
{
  Position head;

  if (direction == RIGHT)
    head = *(body.begin()) + Position(1, 0);
  else if (direction == LEFT)
    head = *(body.begin()) + Position(-1, 0);
  else if (direction == UP)
    head = *(body.begin()) + Position(0, -1);
  else if (direction == DOWN)
    head = *(body.begin()) + Position(0, 1);
  else
    head = *(body.begin());

  gui->removeSquare((body.back()).getX(), (body.back()).getY());

  body.pop_back();
  body.push_front(head);

  if (checkObject(map) == QUIT)
    return QUIT;
  gui->drawSquare((body.begin())->getX(), (body.begin())->getY(), BODY);
  return NONE;
}
