//
// Game.hpp for qsd in /home/saysan_j/Desktop/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Thu Apr  2 18:12:05 2015 Jean-Paul SAYSANA
// Last update Sun Apr  5 03:53:02 2015 Daniel Han
//

#ifndef GAME_HPP_
# define GAME_HPP_

#include <unistd.h>
#include <iostream>
#include "Map.hpp"
#include "IGui.hpp"
#include "Snake.hpp"

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

  void	updateGame(Snake &);
  void  playGame();
  void	displayGame();
};

#endif /* !GAME_HPP_ */
