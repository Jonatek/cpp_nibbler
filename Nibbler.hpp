//
// Nibbler.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Tue Mar 24 14:46:15 2015 Jonathan Quach
// Last update Tue Mar 24 20:59:59 2015 Jonathan Quach
//

#ifndef _NIBBLER_HPP_
#define _NIBBLER_HPP_

#include <cstdlib>
#include <string>
#include <vector>
#include <dlfcn.h>
#include <sstream>
#include <iostream>

class Nibbler
{
private:
  int	_winX;
  int	_winY;
  int	_caseX;
  int	_caseY;
  // Map	*_map;

public:
  Nibbler(const std::vector<std::string> &argv);
  ~Nibbler();
};

#endif
