//
// snake.hh for qsd in /home/saysan_j/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Tue Mar 24 12:26:40 2015 Jean-Paul SAYSANA
// Last update Sat Apr  4 15:38:59 2015 Jonathan Quach
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

  void		move(EventType);
  void	        checkWall();

};

#endif	/*	!SNAKE_HPP_	*/
