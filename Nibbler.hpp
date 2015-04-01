//
// Nibbler.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Tue Mar 24 14:46:15 2015 Jonathan Quach
// Last update Wed Apr  1 15:19:10 2015 Jonathan Quach
//

#ifndef _NIBBLER_HPP_
#define _NIBBLER_HPP_

#include <cstdlib>
#include <string>
#include <vector>
#include <dlfcn.h>
#include <sstream>
#include <iostream>

#include "IGui.hpp"

class Nibbler
{
private:
  int	_winX;
  int	_winY;
  int	_caseX;
  int	_caseY;
  void	*_handle;
  IGui	*_gui;
  bool	_loop;
  // Map	*_map;

public:
  Nibbler(const std::vector<std::string> &argv);
  ~Nibbler();
  Nibbler(Nibbler const &);
  Nibbler &operator=(Nibbler const &);

  void loop();
  void *getHandler() const;
};

#endif
