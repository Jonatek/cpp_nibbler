#ifndef GAME_HPP_
# define GAME_HPP_

#include "Map.hpp"
#include "IGui.hpp"

class Game
{
  //
  // Attributs
  //
private:
  Map _map;
  Snake _snake;
  IGui *_gui;

  //
  // Coplien form
  //
public:
  Game(int, int);
  Game(Game const &);
  Game & operator=(Game const &);
  ~Game();


};

#endif /* !GAME_HPP_ */
