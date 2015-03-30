//
// Event.cpp for  in /home/quach_a/Lab/cpp_nibbler
//
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
//
// Started on  Thu Mar 26 19:53:00 2015 Jonathan Quach
// Last update Mon Mar 30 17:44:25 2015 Daniel Han
//

#include <iostream>
#include "Event.hpp"

Event::Event()
{
  _event = NONE;
}

Event::~Event()
{

}

EventType Event::getEventType() const
{
  return _event;
}

void Event::setEventType(const EventType & type)
{
  if (this->_event == NONE)
    this->_event = type;
  else if (type == LEFT)
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
  else if (type == RIGHT)
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
  else
    this->_event = type;
  std::cout << "event updated with " << this->_event << std::endl;
 // _event = type;
}
