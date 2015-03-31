//
// Position.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Sat Mar 28 18:52:57 2015 Jonathan Quach
// Last update Tue Mar 31 19:37:06 2015 Daniel Han
//

#ifndef _POSITION_HPP_
#define _POSITION_HPP_

class Position
{
private:
  int _x;
  int _y;

public:
  Position();
  Position(int, int);
  Position(Position const &);
  ~Position();
  Position & operator=(Position const &);

  int getX() const;
  int getY() const;
  void setX(int);
  void setY(int);

  Position & operator+(Position const &);

};

#endif
