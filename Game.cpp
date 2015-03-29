//
// Game.cpp for  in /home/quach_a/Lab/cpp_nibbler
//
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
//
// Started on  Sat Mar 28 16:55:11 2015 Jonathan Quach
// Last update Sat Mar 28 19:57:09 2015 Jonathan Quach
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

void Game::startGame()
{

}
