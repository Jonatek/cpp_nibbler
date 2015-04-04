//
// Game.hpp for qsd in /home/saysan_j/Desktop/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Thu Apr  2 18:12:05 2015 Jean-Paul SAYSANA
// Last update Sat Apr  4 12:59:13 2015 Jonathan Quach
//

#ifndef GAME_HPP_
# define GAME_HPP_

#include <iostream>
#include "Map.hpp"
#include "IGui.hpp"
#include "Snake.hpp"
#include <unistd.h>

class Game
{
  //
  // Attributs
  //
private:
  // Snake _snake(int, int);
  int	_winX;
  int	_winY;
  int	_x;
  int	_y;
  IGui *_gui;
  Map _map;
  Event _ev;

  bool	_loop;

  //
  // Coplien form
  //
public:
  Game(int const, int const, int const, int const, IGui *);
  Game(Game const &);
  Game & operator=(Game const &);
  ~Game();

  void	updateGame();
  void  playGame();
  void	displayGame();
  void	move(EventType);

};

#endif /* !GAME_HPP_ */
