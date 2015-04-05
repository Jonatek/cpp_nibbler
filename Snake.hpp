//
// snake.hh for qsd in /home/saysan_j/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Tue Mar 24 12:26:40 2015 Jean-Paul SAYSANA
// Last update Sun Apr  5 05:52:16 2015 Daniel Han
//

#ifndef		SNAKE_HPP_
# define	SNAKE_HPP_

#include <list>
#include "Event.hpp"
#include "Position.hpp"
#include "IGui.hpp"
#include "Map.hpp"

#define MAX_SPEED 20000

class		Snake
{
private:
  bool		god_mode;
  int		x;
  int		y;
  int	        size;
  int		speed;
  IGui		*gui;
  std::list<Position> body;

public:
  Snake(int, int, IGui *);
  Snake(Snake const &);
  Snake &operator=(Snake const &);
  ~Snake();

  int		getSize() const;
  int		getSpeed() const;
  void		setSpeed(int);
  void		setGodMode();

  /******************************/
  /*		CHANGES		*/
  /******************************/

  void		growUp(int _x, int _y, Map &);
  void	        addSnakeInMap(Map &);

  /******************************/
  /*		MOVE		*/
  /******************************/

  EventType	move(EventType, Map &);
  EventType	checkObject(Map &);

};

#endif	/*	!SNAKE_HPP_	*/
