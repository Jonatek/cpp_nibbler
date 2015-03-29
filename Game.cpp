//
// Game.cpp for  in /home/quach_a/Lab/cpp_nibbler
//
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
//
// Started on  Sat Mar 28 16:55:11 2015 Jonathan Quach
// Last update Sun Mar 29 19:14:34 2015 Jonathan Quach
//

#include "Game.hpp"
#include "Event.hpp"

Game::Game(IGui *gui, int const &width, int const &height) :
  _gui(gui), _width(width), _height(height), _snake(_width, _height, _gui)
{
  _direction = RIGHT;
}

Game::~Game()
{

}

void Game::makeSnakeMove(Event const &e)
{
  if (e.getEventType() == LEFT)
    _snake.moveLeft();
  if (e.getEventType() == RIGHT)
    _snake.moveRight();
  _snake.move();
}

void Game::startGame()
{

}
