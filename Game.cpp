//
// Game.cpp for qsd in /home/saysan_j/Desktop/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Thu Apr  2 16:45:00 2015 Jean-Paul SAYSANA
// Last update Sun Apr  5 04:04:21 2015 Daniel Han
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
  if (this != &other)
    this->_gui = other._gui;
  return (*this);
}

Game::~Game()
{
}

void		Game::displayGame()
{
}

void		Game::playGame()
{
  Snake		_snake(this->_x, this->_y, this->_gui);
  Event		quit;

  _snake.addSnakeInMap(_map);
  _map.drawObjects();
  while (this->_loop)
    {
      // Game _game(_gui, _caseX, _caseY);
      // _game->startGame();
      this->updateGame(_snake);
      if (_snake.move(_ev.getEventType(), _map) == QUIT)
	this->_loop = false;
      usleep(_snake.getSpeed());
    }
}

void		Game::updateGame(Snake & _snake)
{
  EventType	new_event;

  this->_ev.setEventType(this->_gui->updateEvent());
  new_event = this->_ev.getEventType();
  if (new_event == QUIT)
    this->_loop = false;
  else if (new_event == SPACE)
    {
      _snake.setSpeed(_snake.getSpeed() - 5000);
      this->_ev.setOldEvent();
    }
}
