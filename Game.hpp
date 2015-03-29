//
// Game.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Sat Mar 28 16:57:40 2015 Jonathan Quach
// Last update Sat Mar 28 19:55:56 2015 Jonathan Quach
//

#ifndef _GAME_HPP_
# define _GAME_HPP_

#include <string>
#include "IGui.hpp"
#include "Snake.hpp"

class Game
{
private:
  IGui *_gui;
  int	_width;
  int	_height;
  Snake _snake;
  EventType _direction;

public:
  Game(IGui *, int const &, int const &);
  ~Game();

  void startGame();
};

#endif
