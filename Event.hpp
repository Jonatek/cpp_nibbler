//
// Event.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Thu Mar 26 19:40:57 2015 Jonathan Quach
// Last update Thu Mar 26 23:42:55 2015 Jonathan Quach
//

#ifndef _EVENT_HPP
# define _EVENT_HPP

typedef enum
  {
    NONE,
    LEFT,
    RIGHT,
    ENTER,
    QUIT,
    PAUSE
  } EventType;

class Event
{
public:
  Event();
  ~Event();

  EventType getEventType() const;
  void setEventType(const EventType &);

private:
  EventType _event;
};

#endif
