//
// Game.hpp for qsd in /home/saysan_j/Desktop/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Thu Apr  2 18:12:05 2015 Jean-Paul SAYSANA
// Last update Sun Apr  5 06:57:22 2015 Daniel Han
//

#ifndef _GAME_HPP_
# define _GAME_HPP_

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
  int _winX;
  int _winY;
  int _x;
  int _y;
  bool _loop;
  IGui *_gui;
  Map _map;
  Event _ev;

  //
  // Coplien form
  //
public:
  Game(int const, int const, int const, int const, IGui *);
  Game(Game const &);
  Game & operator=(Game const &);
  ~Game();

  //
  // The Game
  //
public:
  void playGame();
  void handleInput(Snake &);
  void updateGame(Snake &, EventType const);

};

#endif /* !_GAME_HPP_ */
