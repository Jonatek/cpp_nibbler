//
// Map.cpp for Map.cpp in /home/han_d/Github/cpp_nibbler
// 
// Made by Daniel Han
// Login   <han_d@epitech.net>
// 
// Started on  Thu Apr  2 15:42:47 2015 Daniel Han
// Last update Sun Apr  5 03:41:40 2015 Daniel Han
//

#include <stdlib.h>
#include "Map.hpp"
#include "Position.hpp"

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
  int	i = 0;

  initWall(caseX, caseY);
  addRandomObject(FOOD, false);
  while (i < ((caseX * caseY) / 100))
    {
      addRandomObject(WALL, false);
      ++i;
    }
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

//
// Get/Add/Remove Object
//
ObjectType Map::getObject(int x, int y) const
{
  return (this->_objects[y * this->_caseX + x]);
}

void Map::addRandomObject(ObjectType object, bool draw)
{
  Position      pos(rand() % this->_caseX, rand() % this->_caseY);
  int	        x;
  int		y;
  int		deathdoor = 500;

  x = pos.getX();
  y = pos.getY();
  while (this->_objects[y * this->_caseX + x] != NOTHING)
    {
      pos.setX(rand() % this->_caseX);
      pos.setY(rand() % this->_caseY);
      x = pos.getX();
      y = pos.getY();
      --deathdoor;
    }
  this->_objects[y * this->_caseX + x] = object;
  if (draw == true)
    this->_gui->drawSquare(x, y, FOOD);
}

bool Map::addObject(int x, int y, ObjectType object)
{
  int	pos = y * this->_caseX + x;

  std::cout << "pos ----> " << pos << " x : " << x << " y : " << y << " caseX : " << _caseX << std::endl;
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
      this->_objects[pos] = NOTHING;
      if (rand() % 3 == 0)
	addRandomObject(POISON, true);
    }
  else
    this->_objects[pos] = NOTHING;
}

void	Map::drawObjects()
{
  int	y;
  int	x;

  y = 0;
  while (y < _caseY)
    {
      x = 0;
      while (x < _caseX)
	{
	  if (getObject(x, y) == WALL)
	    _gui->drawSquare(x, y, WALL);
	  else if (getObject(x, y) == FOOD)
	    _gui->drawSquare(x, y, FOOD);
	  ++x;
	}
      ++y;
    }
}
