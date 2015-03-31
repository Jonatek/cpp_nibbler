#ifndef FOOD_HPP_
# define FOOD_HPP_

#include "Position.hpp"
#include "IObject.hpp"

class Food : public IObject
{
private:
  int _x;
  int _y;

public:
  Food();
  Food(Food const &);
  Food & operator=(Food const &);
  virtual ~Food();

public:
  virtual int getX() const;
  virtual int getY() const;
  virtual void setX(int);
  virtual void setY(int);

public:
  virtual Position & createRandomAtPos(int, int);

};

#endif /* !FOOD_HPP_ */
