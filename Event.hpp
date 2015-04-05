//
// Event.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Thu Mar 26 19:40:57 2015 Jonathan Quach
// Last update Sun Apr  5 06:55:01 2015 Daniel Han
//

#ifndef _EVENT_HPP_
# define _EVENT_HPP_

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
  //
  // Attributs
  //
private:
  EventType _event;
  EventType _old;

  //
  // Coplien form
  //
public:
  Event();
  Event(Event const &);
  Event & operator=(Event const &);
  ~Event();

  //
  // Getter
  //
public:
  EventType getEventType() const;

  //
  // Setters : use input to modify event
  //
public:
  void setOldEvent();
  void snakeStartMoving(EventType const);
  void setNewDirection(EventType const);
  void gameToPause();
  void gameInPause(EventType const);
  void tempInput(EventType const);
  void setEventType(EventType const);

};

#endif /* !_EVENT_HPP_ */
