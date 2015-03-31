//
// Position.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Sat Mar 28 18:48:44 2015 Jonathan Quach
// Last update Tue Mar 31 18:54:40 2015 Daniel Han
//

#include "Position.hpp"

Position::Position() :
  x(0), y(0)
{
}

Position::Position(int _x, int _y) :
  x(_x), y(_y)
{
}

Position::Position(Position const & other) :
  x(other.x), y(other.y)
{
}

Position::~Position()
{
}

Position & Position::operator=(Position const & other)
{
  if (this != &other)
    {
      x = other.x;
      y = other.y;
    }
  return *this;
}

int Position::getX() const
{
  return x;
}

int Position::getY() const
{
  return y;
}

void Position::setX(int _x)
{
  x = _x;
}

void Position::setY(int _y)
{
  y = _y;
}

Position & Position::operator+(Position const & other)
{
  Position *res = new Position(this->x + other.getX(), this->y + other.getY());
  return *res;
}
