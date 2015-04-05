//
// Position.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Sat Mar 28 18:52:57 2015 Jonathan Quach
// Last update Sun Apr  5 07:08:51 2015 Daniel Han
//

#ifndef _POSITION_HPP_
# define _POSITION_HPP_

class Position
{
  //
  // Attributs
  //
private:
  int _x;
  int _y;

  //
  // Coplien form
  //
public:
  Position();
  Position(int const, int const);
  Position(Position const &);
  Position & operator=(Position const &);
  ~Position();

  //
  // Getters & Setters
  //
public:
  int getX() const;
  int getY() const;
  void setX(int const);
  void setY(int const);

  //
  // Operator +
  //
public:
  Position & operator+(Position const &);

};

#endif /* !_POSITION_HPP_ */
