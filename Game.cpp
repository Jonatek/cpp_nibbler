//
// Game.cpp for qsd in /home/saysan_j/Desktop/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Thu Apr  2 16:45:00 2015 Jean-Paul SAYSANA
// Last update Sun Apr  5 11:42:39 2015 Jonathan Quach
//

#include "Game.hpp"

//
// Coplien form
//
Game::Game(int const winX, int const winY, int const x, int const y, IGui *gui)
  : _winX(winX), _winY(winY), _x(x), _y(y), _gui(gui), _map(_x, _y, _gui)
{
  this->_loop = true;
  this->_gui->createWindow(_winX, _winY);
}

Game::~Game()
{
  std::cout << "GAME DESTROYED" << std::endl;
}

//
// The Game
//
void Game::playGame()
{
  Snake snake(this->_x, this->_y, this->_gui);

  this->_map.drawObjects();
  snake.addSnakeInMap(_map);
  while (this->_loop)
    {
      this->handleInput(snake);
      if (snake.move(_ev.getEventType(), _map) == QUIT)
	this->_loop = false;
      usleep(snake.getSpeed());
    }
  delete _gui;
}

void Game::handleInput(Snake & snake)
{
  EventType input;

  this->_ev.setEventType(this->_gui->updateEvent());
  input = this->_ev.getEventType();
  if (input == QUIT)
    this->_loop = false;
  else if (input == SPACE || input == GOD_MODE || input == FOOD_PUSH)
    updateGame(snake, input);
}

void Game::updateGame(Snake & snake, EventType const input)
{
  if (input == SPACE)
    {
      snake.setSpeed(snake.getSpeed() - 5000);
      this->_ev.setOldEvent();
    }
  else if (input == GOD_MODE)
    {
      snake.setGodMode();
      this->_ev.setOldEvent();
    }
  else if (input == FOOD_PUSH)
    {
      this->_map.addRandomObject(FOOD, true);
      this->_ev.setOldEvent();
    }
}
