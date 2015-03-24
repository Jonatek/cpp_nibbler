//
// snake.cpp for qsd in /home/saysan_j/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Tue Mar 24 12:26:42 2015 Jean-Paul SAYSANA
// Last update Tue Mar 24 14:47:02 2015 Jean-Paul SAYSANA
//

#include "Snake.hpp"

Snake::Snake()
{
  this->snakeSize = 3;
  this->direction = NONE;
}

void		Snake::growUp()
{
  this->snakeSize += 1;
}

void		Snake::moveUp()
{
  this->direction = UP;
}

void		Snake::moveDown()
{
  this->direction = DOWN;
}

void		Snake::moveLeft()
{
  this->direction = LEFT;
}

void		Snake::moveRight()
{
  this->direction = RIGHT;
}
