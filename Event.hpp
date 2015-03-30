//
// Event.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Thu Mar 26 19:40:57 2015 Jonathan Quach
// Last update Mon Mar 30 17:14:57 2015 Daniel Han
//

#ifndef _EVENT_HPP
# define _EVENT_HPP

typedef enum
  {
    NONE,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    ENTER,
    QUIT,
    PAUSE
  } EventType;

typedef enum
  {
    UNKNOW,
    WALL,
    HEAD,
    BODY
  } ElementType;

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
