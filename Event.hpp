//
// Event.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Thu Mar 26 19:40:57 2015 Jonathan Quach
// Last update Sun Apr  5 05:35:47 2015 Daniel Han
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
    PAUSE,
    SPACE,
    GOD_MODE,
    FOOD_PUSH
  } EventType;

class Event
{
private:
  EventType _event;
  EventType _old;

public:
  Event();
  Event(Event const &);
  Event & operator=(Event const &);
  ~Event();

public:
  EventType getEventType() const;
  void setOldEvent();
  void snakeStartMoving(EventType);
  void setNewDirection(EventType);
  void gameToPause();
  void gameInPause(EventType);
  void tempInput(EventType);
  void setEventType(EventType);

};

#endif
