//
// Position.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Sat Mar 28 18:48:44 2015 Jonathan Quach
// Last update Sat Mar 28 19:58:22 2015 Jonathan Quach
//

#include "Position.hpp"

Position::Position(int const &_x, int const &_y) :
  x(_x), y(_y)
{

}

Position::~Position()
{

}

int Position::getX() const
{
  return x;
}

int Position::getY() const
{
  return y;
}

void Position::setX(int const &_x)
{
  x = _x;
}

void Position::setY(int const &_y)
{
  y = _y;
}
