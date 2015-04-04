//
// snake.cpp for qsd in /home/saysan_j/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Tue Mar 24 12:26:42 2015 Jean-Paul SAYSANA
// Last update Sat Apr  4 19:11:00 2015 Jonathan Quach
//

#include <iostream>
#include <cstdlib>
#include "Snake.hpp"

Snake::Snake(int _x, int _y, IGui *_gui)
  : x(_x), y(_y), snakeSize(4), gui(_gui)
{
  body.push_back(Position(x / 2 , y / 2));
  body.push_back(Position(x / 2 - 1, y / 2));
  body.push_back(Position(x / 2 - 2, y / 2));
  body.push_back(Position(x / 2 - 3, y / 2));
  for (std::list<Position>::iterator it = body.begin(); it != body.end(); ++it)
    {
      std::cout << it->getX() << " " << it->getY() << std::endl;
      gui->drawSquare(it->getX(), it->getY(), BODY);
    }
}

void		Snake::addSnakeInMap(Map &map)
{
  map.addObject(x / 2, y / 2, HEAD);
  map.addObject(x / 2 - 1, y / 2, BODY);
  map.addObject(x / 2 - 2, y / 2, BODY);
  map.addObject(x / 2 - 3, y / 2, BODY);
}

void		Snake::growUp(int _x, int _y, Map &map)
{
  Position	head(_x, _y);

  std::cout << "MMMMMMMMMMIIIIIAAAAAAAMMMMM" << std::endl;

  this->snakeSize += 1;
  body.push_front(head);
  gui->drawSquare(_x, _y, BODY);
  map.addObject(_x, _y, HEAD);
}

EventType	Snake::checkObject(Map &map)
{
  int		_x = body.begin()->getX();
  int		_y = body.begin()->getY();
  ObjectType	obj;

  obj = map.getObject(_x, _y);
  std::cout << "OBJ X =  " << _x << " OBJ Y = " << _y << std::endl;
  if (obj == WALL || obj == BODY || obj == HEAD)
    {
      if (obj == WALL)
	std::cout << "DIIIIIIIIIIIIIIIIIEEEEEE BITCH" << std::endl;
      if (obj == BODY)
      	{
      	  std::cout << "x : " << _x << " y : " << _y << std::endl;
      	  std::cout << "SO DUMB" << std::endl;
      	}
      return QUIT;
    }
  if (obj == FOOD)
    {
      if (obj == FOOD)
      	{
	  std::cout << "EAAAAATIIINNNG DAT SHIT" << std::endl;
	  growUp(_x, _y, map);

	  Position food(rand() % x, rand() % y);

	  while (map.addObject(food.getX(), food.getY(), FOOD) == false)
	    {
	      food.setX(rand() % x);
	      food.setY(rand() % y);
	    }
	  gui->drawSquare(food.getX(), food.getY(), FOOD);
	  std::cout << "-----------> SUCCESSFULLY ADD FOOD ON DAT FUCKING MAP"
		    << std::endl;
      	}
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
  else if (direction == NONE)
    return NONE;
  else
    head = *(body.begin());

  gui->removeSquare((body.back()).getX(), (body.back()).getY());
  map.removeObject((body.back()).getX(), (body.back()).getY());

  body.pop_back();
  body.push_front(head);

  if (direction != NONE)
    {
      if (checkObject(map) == QUIT)
	return QUIT;
    }

  map.addObject(head.getX(), head.getY(), HEAD);

  // map.checkFood();

  gui->drawSquare((body.begin())->getX(), (body.begin())->getY(), BODY);
  return NONE;
}
