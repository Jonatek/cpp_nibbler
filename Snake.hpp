//
// snake.hh for qsd in /home/saysan_j/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Tue Mar 24 12:26:40 2015 Jean-Paul SAYSANA
// Last update Tue Mar 31 17:13:44 2015 Jean-Paul SAYSANA
//

#ifndef		SNAKE_HPP_
# define	SNAKE_HPP_

#include <list>
#include "Event.hpp"
#include "Position.hpp"
#include "IGui.hpp"

class		Snake
{
private:
  int		x;
  int		y;
  EventType     direction;
  int		snakeSize;
  IGui		*gui;
  std::list<Position> body;

public:
  Snake(int const &, int const &, IGui *);
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

  // void		moveUp(Event const &);
  // void		moveDown(Event const &);
  void		moveLeft();
  void		moveRight();
  void		move(EventType);
};

#endif	/*	!SNAKE_HPP_	*/
