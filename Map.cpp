//
// Map.cpp for Map.cpp in /home/han_d/Github/cpp_nibbler
// 
// Made by Daniel Han
// Login   <han_d@epitech.net>
// 
// Started on  Thu Apr  2 15:42:47 2015 Daniel Han
// Last update Thu Apr  2 15:48:29 2015 Daniel Han
//

#include <stdlib.h>
#include "Map.hpp"

//
// Coplien Form
//
Map::Map(int caseX, int caseY)
{
  this->_objects.clear();
  this->_caseX = caseX;
  this->_caseY = caseY;
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
void Map::initMap(int caseX, int caseY)
{
  initWall(caseX, caseY);
  initSnake(caseX, caseY);
  addRandomObject(FOOD);
}

void Map::initWall(int caseX, int caseY)
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
	    _objects.push_back(NONE);
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

void Map::initSnake(int caseX, int caseY)
{
  int	pos = (caseY / 2) * _caseX + (caseX / 2);

  this->_objects[pos] = HEAD;
  this->_objects[pos + 1] = BODY;
  this->_objects[pos + 2] = BODY;
}

//
// Get/Add/Remove Object
//
Map::ObjectType Map::getObject(int x, int y) const
{
  return (this->_objects[y * this->_caseX + x]);
}

void Map::addRandomObject(ObjectType object)
{
  int	pos;
  int	deathdoor = 4242;

  pos = rand() % (this->_caseX + this->_caseY);
  while (this->_objects[pos] == NONE)
    {
      pos = rand() % (this->_caseX + this->_caseY);
      --deathdoor;
    }
  this->_objects[pos] = object;
}

bool Map::addObject(int x, int y, ObjectType object)
{
  int	pos = y * this->_caseX + x;

  if (this->_objects[pos] == NONE)
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
      this->_objects[pos] = NONE;
    }
  else
    this->_objects[pos] = NONE;
}
