//
// Map.hpp for Map.hpp in /home/han_d/Github/cpp_nibbler
// 
// Made by Daniel Han
// Login   <han_d@epitech.net>
// 
// Started on  Wed Apr  1 14:23:42 2015 Daniel Han
// Last update Fri Apr  3 16:24:43 2015 Daniel Han
//

#ifndef MAP_HPP_
# define MAP_HPP_

#include <vector>
#include <iostream>
#include "IGui.hpp"

class Map
{
  //
  // Attributs
  //
private:
  std::vector<ObjectType> _objects;
  int		_caseX;
  int		_caseY;
  IGui		*_gui;

  //
  // Coplien Form
  //
public:
  Map(int, int, IGui *);
  Map(Map const &);
  Map & operator=(Map const &);
  ~Map();

  //
  // Init Map
  //
public:
  void initMap(int, int);
  void initWall(int, int);
  void initSnake(int, int);

  //
  // Get/Add/Remove Object
  //
public:
  ObjectType getObject(int, int) const;
  void addRandomObject(ObjectType);
  bool addObject(int, int, ObjectType);
  void removeObject(int, int);
  void drawObjects();
  int	getX(int);
  int	getY(int);
};

#endif /* !MAP_HPP_ */
