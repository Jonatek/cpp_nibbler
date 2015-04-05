//
// snake.cpp for qsd in /home/saysan_j/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Tue Mar 24 12:26:42 2015 Jean-Paul SAYSANA
// Last update Sun Apr  5 05:52:09 2015 Daniel Han
//

#include <iostream>
#include <cstdlib>
#include "Snake.hpp"

Snake::Snake(int _x, int _y, IGui *_gui)
  : god_mode(false), x(_x), y(_y), size(4), speed(100000), gui(_gui)
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

Snake::Snake(Snake const & other)
{
  this->god_mode = other.god_mode;
  this->x = other.x;
  this->y = other.y;
  this->size = other.size;
  this->speed = other.speed;
  this->gui = other.gui;
}

Snake & Snake::operator=(Snake const & other)
{
  if (this != &other)
    {
      this->god_mode = other.god_mode;
      this->x = other.x;
      this->y = other.y;
      this->size = other.size;
      this->speed = other.speed;
      this->gui = other.gui;
    }
  return (*this);
}

Snake::~Snake()
{
}

int		Snake::getSize() const
{
  return (this->size);
}

int		Snake::getSpeed() const
{
  return (this->speed);
}

void		Snake::setSpeed(int new_speed)
{
  if (this->speed < MAX_SPEED)
    this->speed = MAX_SPEED;
  else
    this->speed = new_speed;
}

void		Snake::setGodMode()
{
  if (this->god_mode == false)
    this->god_mode = true;
  else
    this->god_mode = false;
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

  // std::cout << "MMMMMMMMMMIIIIIAAAAAAAMMMMM" << std::endl;

  this->size += 1;
  setSpeed(this->speed - 5000);
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
      // if (obj == WALL)
      // 	std::cout << "DIIIIIIIIIIIIIIIIIEEEEEE BITCH" << std::endl;
      // if (obj == BODY)
      // 	{
      // 	  std::cout << "x : " << _x << " y : " << _y << std::endl;
      // 	  std::cout << "SO DUMB" << std::endl;
      // 	}
      return QUIT;
    }
  else if (obj == BLOCK)
    {
      if (this->god_mode == false)
	return QUIT;
      return NONE;
    }
  else if (obj == FOOD)
    {
      growUp(_x, _y, map);
      map.addRandomObject(FOOD, true);
    }
  else if (obj == POISON)
    setSpeed(this->speed + 5000);
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
  else if (direction == NONE || direction == PAUSE)
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
