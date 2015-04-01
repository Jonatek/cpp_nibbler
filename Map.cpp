#include "Map.hpp"

Map::Map(int caseX, int caseY)
{
  this->_objects.clear();
  this->_caseX = caseX;
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

void Map::initMap(int caseX, int caseY)
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

Map::ObjectType Map::getObject(int x, int y) const
{
  return (this->_objects[y * this->_caseX + x]);
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
  this->_objects[y * this->_caseX + x] = NONE;
}
