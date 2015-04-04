//
// snake.hh for qsd in /home/saysan_j/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Tue Mar 24 12:26:40 2015 Jean-Paul SAYSANA
// Last update Sat Apr  4 16:15:09 2015 Daniel Han
//

#ifndef		SNAKE_HPP_
# define	SNAKE_HPP_

#include <list>
#include "Event.hpp"
#include "Position.hpp"
#include "IGui.hpp"
#include "Map.hpp"

class		Snake
{
private:
  int		x;
  int		y;
  int		snakeSize;
  IGui		*gui;
  std::list<Position> body;

public:
  Snake(int, int, IGui *);
  ~Snake() {};
  Snake(Snake const &);
  Snake &operator=(Snake const &);

  /******************************/
  /*		CHANGES		*/
  /******************************/

  void		growUp();

  /******************************/
  /*		MOVE		*/
  /******************************/

  EventType	move(EventType, Map &);
  EventType	checkObject(Map &);

};

#endif	/*	!SNAKE_HPP_	*/
