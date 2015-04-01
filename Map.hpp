//
// Map.hpp for Map.hpp in /home/han_d/Github/cpp_nibbler
// 
// Made by Daniel Han
// Login   <han_d@epitech.net>
// 
// Started on  Wed Apr  1 14:23:42 2015 Daniel Han
// Last update Wed Apr  1 15:14:13 2015 Daniel Han
//

#ifndef MAP_HPP_
# define MAP_HPP_

#include <vector>

class Map
{
public:
  enum ObjectType
    {
      NONE,
      WALL,
      FOOD
    };

private:
  std::vector<ObjectType> _objects;
  int _caseX;

public:
  Map(int, int);
  Map(Map const &);
  Map & operator=(Map const &);
  ~Map();

public:
  void initMap(int, int);
  ObjectType getObject(int, int) const;
  bool addObject(int, int, ObjectType);
  void removeObject(int, int);

};

#endif /* !MAP_HPP_ */
