//
// Map.cpp for Map.cpp in /home/han_d/Github/cpp_nibbler
// 
// Made by Daniel Han
// Login   <han_d@epitech.net>
// 
// Started on  Thu Apr  2 15:42:47 2015 Daniel Han
// Last update Fri Apr  3 18:54:45 2015 Daniel Han
//

#include <stdlib.h>
#include "Map.hpp"

//
// Coplien Form
//
Map::Map(int caseX, int caseY, IGui *gui)
{
  this->_objects.clear();
  this->_caseX = caseX;
  this->_caseY = caseY;
  this->_gui = gui;
  initMap(caseX, caseY);
}

Map::Map(Map const & other)
{
  this->_objects = other._objects;
}

Map & Map::operator=(Map const & other)
{
  if (this != &other)
    this->_objects = other._objects;
  return (*this);
}

Map::~Map()
{
  this->_objects.clear();
}

//
// Init Map
//
void	Map::initMap(int caseX, int caseY)
{
  initWall(caseX, caseY);
  initSnake(caseX, caseY);
  addRandomObject(FOOD);
}

void	Map::initWall(int caseX, int caseY)
{
  int	x;

  x = 0;
  while (x < caseX)
    {
      _objects.push_back(WALL);
      ++x;
    }
  --caseY;
  while (caseY > 1)
    {
      x = 0;
      while (x < caseX)
	{
	  if (x == 0 || x == (caseX - 1))
	    _objects.push_back(WALL);
	  else
	    _objects.push_back(NOTHING);
	  ++x;
	}
      --caseY;
    }
  x = 0;
  while (x < caseX)
    {
      _objects.push_back(WALL);
      ++x;
    }
}

void	Map::initSnake(int caseX, int caseY)
{
  int	pos = (caseY / 2) * _caseX + (caseX / 2);

  this->_objects[pos] = HEAD;
  this->_objects[pos + 1] = BODY;
  this->_objects[pos + 2] = BODY;
}

//
// Get/Add/Remove Object
//
ObjectType Map::getObject(int x, int y) const
{
  return (this->_objects[y * this->_caseX + x]);
}

void Map::addRandomObject(ObjectType object)
{
  int	pos;
  int	deathdoor = 4242;

  pos = rand() % (this->_caseX + this->_caseY);
  while (this->_objects[pos] == NOTHING)
    {
      pos = rand() % (this->_caseX + this->_caseY);
      --deathdoor;
    }
  this->_objects[pos] = object;
}

bool Map::addObject(int x, int y, ObjectType object)
{
  int	pos = y * this->_caseX + x;

  if (this->_objects[pos] == NOTHING)
    {
      this->_objects[pos] = object;
      return true;
    }
  else
    return false;
}

void Map::removeObject(int x, int y)
{
  int	pos = y * this->_caseX + x;

  if (this->_objects[pos] == FOOD)
    {
      addObject(x, y, FOOD);
      this->_objects[pos] = NOTHING;
    }
  else
    this->_objects[pos] = NOTHING;
}

int	Map::getX(int pos)
{
  return (pos / this->_caseY);
}

int	Map::getY(int pos)
{
  return (pos % this->_caseY);
}

void	Map::drawObjects()
{
  int	y = 0;
  int	x;

  while (y < _caseY)
    {
      x = 0;
      while (x < _caseX)
	{
	  if (getObject(x, y) == HEAD || getObject(x, y) == BODY)
	    _gui->drawSquare(x, y, BODY);
	  std::cout << "x : " << x << std::endl;
	  ++x;
	}
      std::cout << "GROSSE PUTE" << std::endl;
      std::cout << "y : " << y << std::endl;
      ++y;
    }
  // for (std::vector<ObjectType>::iterator it = _objects.begin(); it != _objects.end(); ++it)
  //   {
  //     _gui->drawSquare(, , getObject(getY(i), getY(i)));
  //     ++i;
  //   }
}
