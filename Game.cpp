//
// Game.cpp for qsd in /home/saysan_j/Desktop/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Thu Apr  2 16:45:00 2015 Jean-Paul SAYSANA
// Last update Fri Apr  3 18:29:48 2015 Jonathan Quach
//

#include "Game.hpp"

Game::Game(int const winX, int const winY, int const x, int const y, IGui *gui)
  : _winX(winX), _winY(winY), _x(x), _y(y), _gui(gui), _map(_x, _y, _gui)
{
  this->_loop = true;
  this->_gui->createWindow(_winX, _winY);
}

Game	&Game::operator=(Game const &other)
{
}

Game::~Game()
{

}

void		Game::displayGame()
{
}

void		Game::playGame()
{
  Event		_ev;
  // Snake		_snake(this->_x, this->_y, this->_gui);

  while (this->_loop)
    {
      _map.drawObjects();
      // Game _game(_gui, _caseX, _caseY);
      // _game->startGame();
      this->updateGame(_ev);
      // _game.move(_ev.getEventType());
      usleep(50000);
    }
}

void		Game::updateGame(Event _ev)
{
  this->_gui->updateEvent(_ev);
  if (_ev.getEventType() == QUIT)
    this->_loop = false;
}
