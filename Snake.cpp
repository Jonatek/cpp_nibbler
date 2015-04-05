//
// snake.cpp for in /home/saysan_j/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Tue Mar 24 12:26:42 2015 Jean-Paul SAYSANA
// Last update Sun Apr  5 07:26:03 2015 Daniel Han
//

#include <iostream>
#include <cstdlib>
#include "Snake.hpp"

//
// Coplien form
//
Snake::Snake(int const _x, int const _y, IGui *_gui)
  : god_mode(false), x(_x), y(_y), size(4), speed(100000), gui(_gui)
{
  this->body.push_back(Position(x / 2 , y / 2));
  this->body.push_back(Position(x / 2 - 1, y / 2));
  this->body.push_back(Position(x / 2 - 2, y / 2));
  this->body.push_back(Position(x / 2 - 3, y / 2));
  for (std::list<Position>::iterator it = this->body.begin();
       it != this->body.end(); ++it)
    {
      // std::cout << it->getX() << " " << it->getY() << std::endl;
      this->gui->drawSquare(it->getX(), it->getY(), BODY);
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

//
// Getters & Setters
//
int Snake::getSize() const
{
  return (this->size);
}

int Snake::getSpeed() const
{
  return (this->speed);
}

void Snake::setSpeed(int const new_speed)
{
  if (this->speed < MAX_SPEED)
    this->speed = MAX_SPEED;
  else
    this->speed = new_speed;
}

void Snake::setGodMode()
{
  if (this->god_mode == false)
    this->god_mode = true;
  else
    this->god_mode = false;
}

//
// Display/Modify Snake
//
void Snake::addSnakeInMap(Map & map)
{
  map.addObject(x / 2, y / 2, HEAD);
  map.addObject(x / 2 - 1, y / 2, BODY);
  map.addObject(x / 2 - 2, y / 2, BODY);
  map.addObject(x / 2 - 3, y / 2, BODY);
}

void Snake::growUp(int const _x, int const _y, Map &map)
{
  Position head(_x, _y);

  // std::cout << "MMMMMMMMMMIIIIIAAAAAAAMMMMM" << std::endl;
  this->size += 1;
  setSpeed(this->speed - 5000);
  this->body.push_front(head);
  this->gui->drawSquare(_x, _y, BODY);
  map.addObject(_x, _y, HEAD);
}

EventType Snake::checkObject(Map & map)
{
  int _x = this->body.begin()->getX();
  int _y = this->body.begin()->getY();
  ObjectType obj;

  obj = map.getObject(_x, _y);
  // std::cout << "OBJ X =  " << _x << " OBJ Y = " << _y << std::endl;
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

EventType Snake::move(EventType const direction, Map & map)
{
  Position head;

  if (direction == NONE || direction == PAUSE)
    return (NONE);
  else if (direction == RIGHT)
    head = *(body.begin()) + Position(1, 0);
  else if (direction == LEFT)
    head = *(body.begin()) + Position(-1, 0);
  else if (direction == UP)
    head = *(body.begin()) + Position(0, -1);
  else if (direction == DOWN)
    head = *(body.begin()) + Position(0, 1);
  else
    head = *(body.begin());

  this->gui->removeSquare((body.back()).getX(), (body.back()).getY());
  map.removeObject((body.back()).getX(), (body.back()).getY());

  this->body.pop_back();
  this->body.push_front(head);

  if (direction != NONE)
    {
      if (checkObject(map) == QUIT)
	return QUIT;
    }

  map.addObject(head.getX(), head.getY(), HEAD);

  // map.checkFood();

  this->gui->drawSquare((body.begin())->getX(), (body.begin())->getY(), BODY);
  return NONE;
}
