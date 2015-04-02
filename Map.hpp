//
// Map.hpp for Map.hpp in /home/han_d/Github/cpp_nibbler
// 
// Made by Daniel Han
// Login   <han_d@epitech.net>
// 
// Started on  Wed Apr  1 14:23:42 2015 Daniel Han
// Last update Thu Apr  2 15:44:51 2015 Daniel Han
//

#ifndef MAP_HPP_
# define MAP_HPP_

#include <vector>

class Map
{
  //
  // Enum for ObjectType
  //
public:
  enum ObjectType
    {
      NONE,
      WALL,
      HEAD,
      BODY,
      FOOD
    };

  //
  // Attributs
  //
private:
  std::vector<ObjectType> _objects;
  int _caseX;
  int _caseY;

  //
  // Coplien Form
  //
public:
  Map(int, int);
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

};

#endif /* !MAP_HPP_ */
