#include <stdlib.h>
#include "Food.hpp"

Food::Food() :
  _x(0), _y(0)
{
}

Food::Food(Food const & other)
{
  this->_x = other.getX();
  this->_y = other.getY();
}

Food & Food::operator=(Food const & other)
{
  if (this != &other)
    {
      this->_x = other.getX();
      this->_y = other.getY();
    }
}

Food::~Food()
{
}

int Food::getX() const
{
  return (this->_x);
}

int Food::getY() const
{
  return (this->_y);
}

void Food::setX(int x)
{
  this->_x = x;
}

void Food::setY(int y)
{
  this->_y = y;
}

Position & Food::createRandomAtPos(int caseX, int caseY)
{
  Position *food;

  if (this->_x == 0 && this->_y == 0)
    {
      setX(rand() % caseX);
      setY(rand() % caseY);
    }
  return *food;
}
