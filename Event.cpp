//
// Event.cpp for  in /home/quach_a/Lab/cpp_nibbler
//
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
//
// Started on  Thu Mar 26 19:53:00 2015 Jonathan Quach
// Last update Sun Apr  5 06:54:50 2015 Daniel Han
//

#include <iostream>
#include "Event.hpp"

//
// Coplien form
//
Event::Event() :
  _event(NONE), _old(NONE)
{
}

Event::Event(Event const & other)
{
  this->_event = other._event;
  this->_old = other._old;
}

Event & Event::operator=(Event const & other)
{
  if (this != &other)
    {
      this->_event = other._event;
      this->_old = other._old;
    }
  return (*this);
}

Event::~Event()
{
}

//
// Getter
//
EventType Event::getEventType() const
{
  return (this->_event);
}

//
// Setters : use input to modify event
//
void Event::setOldEvent()
{
  this->_event = this->_old;
}

void Event::snakeStartMoving(EventType const input)
{
  if (input == ENTER)
    this->_event = RIGHT;
  else if (input == QUIT)
    this->_event = QUIT;
}

void Event::setNewDirection(EventType const direction)
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

void Event::gameToPause()
{
  if (this->_event != PAUSE)
    {
      this->_old = this->_event;
      this->_event = PAUSE;
    }
  else
    this->_event = this->_old;
}

void Event::gameInPause(EventType const input)
{
  if (input == PAUSE || input == ENTER)
    this->_event = this->_old;
  else if (input == QUIT)
    this->_event = QUIT;
}

void Event::tempInput(EventType const input)
{
  this->_old = this->_event;
  this->_event = input;
}

void Event::setEventType(EventType const type)
{
  if (this->_event == NONE)
    snakeStartMoving(type);
  if (this->_event == PAUSE)
    gameInPause(type);
  else if (type == LEFT || type == RIGHT)
    setNewDirection(type);
  else if (type == PAUSE)
    gameToPause();
  else if (type == SPACE || type == GOD_MODE || type == FOOD_PUSH)
    tempInput(type);
  else if (type == QUIT)
    this->_event = QUIT;
}
