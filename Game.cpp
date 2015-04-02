//
// Game.cpp for qsd in /home/saysan_j/Desktop/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Thu Apr  2 16:45:00 2015 Jean-Paul SAYSANA
// Last update Thu Apr  2 20:00:47 2015 Jean-Paul SAYSANA
//

#include "Game.hpp"

Game::Game(int winX, int winY, int x, int y, IGui *gui) // : _map(x, y) , _snake(x, y, _gui)
{
  Map	_map(x, y);

  this->_gui = gui;
  this->_loop = true;
  this->_gui->createWindow(winX, winY);
  this->updateGame(winX, winY, x, y);
}

Game	&Game::operator=(Game const &other)
{
  
}

Game::~Game()
{
  
}

void		Game::updateGame(int winX, int winY, int caseX, int caseY)
{
  Event		_ev;
  Snake		_snake(caseX, caseY, _gui);

  // Game _game(_gui, _caseX, _caseY);


  while (_loop)
    {
      // _game->startGame();
      _gui->updateEvent(_ev);
      if (_ev.getEventType() == QUIT)
  	_loop = false;
      // _game.move(_ev.getEventType());
      usleep(50000);
    }

}
