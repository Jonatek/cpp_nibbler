#ifndef IOBJECT_HPP_
# define IOBJECT_HPP_

#include "Position.hpp"

class IObject
{
public:
  enum ObjectType
    {
      SNAKE,
      FOOD,
      WALL
    };

public:
  virtual ~IObject();

public:
  virtual int getX() const = 0;
  virtual int getY() const = 0;
  virtual void setX(int) = 0;
  virtual void setY(int) = 0;

public:
  virtual Position & createRandomAtPos(int, int) = 0;

};

#endif /* !IOBJECT_HPP_ */
