//
// Event.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Thu Mar 26 19:53:00 2015 Jonathan Quach
// Last update Thu Mar 26 20:01:50 2015 Jonathan Quach
//

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

void Event::setEventType(const EventType &_type)
{
  _event = _type;
}
