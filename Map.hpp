//
// Map.hpp for Map.hpp in /home/han_d/Github/cpp_nibbler
// 
// Made by Daniel Han
// Login   <han_d@epitech.net>
// 
// Started on  Wed Apr  1 14:23:42 2015 Daniel Han
// Last update Sun Apr  5 07:32:54 2015 Daniel Han
//

#ifndef _MAP_HPP_
# define _MAP_HPP_

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
  int _caseX;
  int _caseY;
  IGui *_gui;

  //
  // Coplien Form
  //
public:
  Map(int const, int const, IGui *);
  Map(Map const &);
  Map & operator=(Map const &);
  ~Map();

  //
  // Init Map
  //
public:
  void initMap(int const, int const);
  void initWall(int const, int const);
  void initRandomFood();
  void initRandomBlock(int const, int const);

  //
  // Get/Add/Remove/Draw Object
  //
public:
  ObjectType getObject(int const, int const) const;
  void addRandomObject(ObjectType const, bool const);
  bool addObject(int const, int const, ObjectType const);
  void removeObject(int const, int const);
  void drawObjects();

};

#endif /* !_MAP_HPP_ */
