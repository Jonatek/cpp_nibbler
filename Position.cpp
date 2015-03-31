//
// Position.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Sat Mar 28 18:48:44 2015 Jonathan Quach
// Last update Tue Mar 31 19:45:05 2015 Daniel Han
//

#include "Position.hpp"

Position::Position() :
  _x(0), _y(0)
{
}

Position::Position(int x, int y) :
  _x(_x), _y(_y)
{
}

Position::Position(Position const & other) :
  _x(getX()), _y(getY())
{
}

Position::~Position()
{
}

Position & Position::operator=(Position const & other)
{
  if (this != &other)
    {
      this->_x = other._x;
      this->_y = other._y;
    }
  return *this;
}

int Position::getX() const
{
  return this->_x;
}

int Position::getY() const
{
  return this->_y;
}

void Position::setX(int x)
{
  this->_x = x;
}

void Position::setY(int y)
{
  this->_y = y;
}

Position & Position::operator+(Position const & other)
{
  Position *res = new Position(getX() + other.getX(), getY() + other.getY());
  return *res;
}
