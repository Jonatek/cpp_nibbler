//
// Game.hpp for qsd in /home/saysan_j/Desktop/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Thu Apr  2 18:12:05 2015 Jean-Paul SAYSANA
// Last update Thu Apr  2 19:46:59 2015 Jean-Paul SAYSANA
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
  // Map _map(int, int);
  // Snake _snake(int, int);

  IGui *_gui;
  bool	_loop;

  //
  // Coplien form
  //
public:
  Game(int, int, int, int, IGui *);
  Game(Game const &);
  Game & operator=(Game const &);
  ~Game();

private:
  void	updateGame(int, int, int, int);
  void  gamingOn();
  

};

#endif /* !GAME_HPP_ */
