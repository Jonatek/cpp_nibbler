//
// Position.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Sat Mar 28 18:48:44 2015 Jonathan Quach
// Last update Sun Mar 29 19:27:02 2015 Jonathan Quach
//

#include "Position.hpp"

Position::Position(int const &_x, int const &_y) :
  x(_x), y(_y)
{

}

Position::Position(Position const& other) :
  x(other.x), y(other.y)
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

Position &Position::operator=(Position const& other)
{
  if (this != &other)
    {
      x = other.x;
      y = other.y;
    }
  return *this;
}

Position &Position::operator+(Position const& other)
{
  Position *res = new Position(this->x + other.getX(), this->y + other.getY());
  return *res;
}
