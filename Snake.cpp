//
// snake.cpp for qsd in /home/saysan_j/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Tue Mar 24 12:26:42 2015 Jean-Paul SAYSANA
// Last update Sun Mar 29 14:51:38 2015 Jonathan Quach
//

#include <iostream>
#include "Snake.hpp"

Snake::Snake(int const &_x, int const &_y, IGui *_gui)
  : x(_x), y(_y), direction(LEFT), snakeSize(4), gui(_gui)
{
  body.push_back(Position(x / 2 , y / 2));
  body.push_back(Position(x / 2 - 1, y / 2));
  body.push_back(Position(x / 2 - 2, y / 2));
  body.push_back(Position(x / 2 - 3, y / 2));
  for (std::list<Position>::iterator it = body.begin(); it != body.end(); it++)
    {
      std::cout << it->getX() << " " << it->getY() << std::endl;
      gui->drawSquare(it->getX(), it->getY(), BODY);
    }
  std::cout << "hello " << std::endl;
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
