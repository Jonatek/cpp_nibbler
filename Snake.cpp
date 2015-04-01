//
// snake.cpp for qsd in /home/saysan_j/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Tue Mar 24 12:26:42 2015 Jean-Paul SAYSANA
// Last update Wed Apr  1 13:00:07 2015 Jean-Paul SAYSANA
//

#include <iostream>
#include "Snake.hpp"

Snake::Snake(int _x, int _y, int _winX, int _winY, IGui *_gui)
  : x(_x), y(_y), winX(_winX), winY(_winY), direction(RIGHT), snakeSize(4), gui(_gui)
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
}

void		Snake::growUp()
{
  this->snakeSize += 1;
}

void		Snake::moveLeft()
{
  if (direction == RIGHT)
    direction = UP;
  else if (direction == DOWN)
    direction = RIGHT;
  else if (direction == LEFT)
    direction = DOWN;
  else if (direction == UP)
    direction = LEFT;
  std::cout << "left" << std::endl;
}

void		Snake::moveRight()
{
  if (direction == UP)
    direction = RIGHT;
  else if (direction == RIGHT)
    direction = DOWN;
  else if (direction == DOWN)
    direction = LEFT;
  else if (direction == LEFT)
    direction = UP;
  std::cout << "right" << std::endl;
}

int		Snake::checkWall()
{
  if ((body.begin())->getX() == 0 ||
      (body.begin())->getY() == 0 ||
      (body.begin())->getX() == winX ||
      (body.begin())->getY() == winY)
    return (1);
  return (0);
}

int		Snake::move(EventType direction)
{
  Position head;

  if (direction == RIGHT)
    head = *(body.begin()) + Position(1, 0);
  else if (direction == LEFT)
    head = *(body.begin()) + Position(-1, 0);
  else if (direction == UP)
    head = *(body.begin()) + Position(0, -1);
  else if (direction == DOWN)
    head = *(body.begin()) + Position(0, 1);
  else
    head = *(body.begin());

  gui->removeSquare((body.back()).getX(), (body.back()).getY());

  body.pop_back();
  body.push_front(head);

  if (checkWall() == 1)
    return (1);
  gui->drawSquare((body.begin())->getX(), (body.begin())->getY(), BODY);

  // switch (direction)
  //   {
  //   case RIGHT:
  //     head = _snake.begin() + Coord(1, 0);
  //     break;
  // case UP:
  //   newHead = *(_snake.begin()) + Coord(0, -1);
  //   break;
  // case DOWN:
  //   newHead = *(_snake.begin()) + Coord(0, 1);
  //   break;
  // case LEFT:
  //   newHead = *(_snake.begin()) + Coord(-1, 0);
  //   break;
  // default:
  //   newHead = *(_snake.begin());
  // }
  return (0);
}
