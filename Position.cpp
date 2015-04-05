//
// Position.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Sat Mar 28 18:48:44 2015 Jonathan Quach
// Last update Sun Apr  5 07:08:27 2015 Daniel Han
//

#include "Position.hpp"

Position::Position() :
  _x(0), _y(0)
{
}

Position::Position(int const x, int const y) :
  _x(x), _y(y)
{
}

Position::Position(Position const & other)
{
  this->_x = other._x;
  this->_y = other._y;
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

void Position::setX(int const x)
{
  this->_x = x;
}

void Position::setY(int const y)
{
  this->_y = y;
}

Position & Position::operator+(Position const & other)
{
  Position *res = new Position(getX() + other.getX(), getY() + other.getY());
  return *res;
}
