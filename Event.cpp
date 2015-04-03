//
// Event.cpp for  in /home/quach_a/Lab/cpp_nibbler
//
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
//
// Started on  Thu Mar 26 19:53:00 2015 Jonathan Quach
// Last update Fri Apr  3 19:13:18 2015 Daniel Han
//

#include <iostream>
#include "Event.hpp"

Event::Event()
{
  this->_event = NONE;
}

Event::~Event()
{

}

EventType Event::getEventType() const
{
  return (this->_event);
}

void Event::snakeStartMoving(EventType input)
{
  if (input == ENTER)
    this->_event = LEFT;
  else if (input == QUIT)
    this->_event = QUIT;
}

void Event::setNewDirection(EventType direction)
{
  if (direction == LEFT)
    {
      if (this->_event == LEFT)
	this->_event = DOWN;
      else if (this->_event == RIGHT)
	this->_event = UP;
      else if (this->_event == UP)
	this->_event = LEFT;
      else if (this->_event == DOWN)
	this->_event = RIGHT;
    }
  else if (direction == RIGHT)
    {
      if (this->_event == LEFT)
	this->_event = UP;
      else if (this->_event == RIGHT)
	this->_event = DOWN;
      else if (this->_event == UP)
	this->_event = RIGHT;
      else if (this->_event == DOWN)
	this->_event = LEFT;
    }

}

void Event::setEventType(EventType type)
{
  if (this->_event == NONE)
    snakeStartMoving(type);
  else if (type == LEFT || type == RIGHT)
      setNewDirection(type);
  else if (type == PAUSE)
    {
      if (this->_event != PAUSE)
	{
	  this->_old = this->_event;
	  this->_event = PAUSE;
	}
      else
	this->_event = _old;
    }
  else if (type == QUIT)
    this->_event = QUIT;
  std::cout << "event updated : " << this->_event << std::endl;
}
