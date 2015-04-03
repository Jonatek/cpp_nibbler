//
// Game.hpp for qsd in /home/saysan_j/Desktop/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Thu Apr  2 18:12:05 2015 Jean-Paul SAYSANA
// Last update Fri Apr  3 17:44:47 2015 Jonathan Quach
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
  Map _map;

  IGui *_gui;
  bool	_loop;

  //
  // Coplien form
  //
public:
  Game(int const, int const, int const, int const, IGui *);
  Game(Game const &);
  Game & operator=(Game const &);
  ~Game();

  void	updateGame(Event _ev);
  void  playGame();
  void	displayGame();

};

#endif /* !GAME_HPP_ */
