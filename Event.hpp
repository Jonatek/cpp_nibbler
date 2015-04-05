//
// Event.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Thu Mar 26 19:40:57 2015 Jonathan Quach
// Last update Sun Apr  5 04:21:26 2015 Daniel Han
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
    SPACE
  } EventType;

class Event
{
private:
  EventType _event;
  EventType _old;

public:
  Event();
  ~Event();

  EventType getEventType() const;
  void setOldEvent();
  void snakeStartMoving(EventType);
  void snakeSpeedBoost();
  void setNewDirection(EventType);
  void gameToPause();
  void gameInPause(EventType);
  void setEventType(EventType);

};

#endif
