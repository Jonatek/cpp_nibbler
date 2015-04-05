//
// Nibbler.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Tue Mar 24 14:46:15 2015 Jonathan Quach
// Last update Sun Apr  5 07:03:42 2015 Daniel Han
//

#ifndef _NIBBLER_HPP_
# define _NIBBLER_HPP_

#include <cstdlib>
#include <string>
#include <vector>
#include <dlfcn.h>
#include <sstream>
#include <iostream>
#include "IGui.hpp"
#include "Map.hpp"

class Nibbler
{
  //
  // Attributs
  //
private:
  int	_winX;
  int	_winY;
  int	_caseX;
  int	_caseY;
  void	*_handle;
  IGui	*_gui;
  bool	_loop;

  //
  // Coplien form
  //
public:
  Nibbler(std::vector<std::string> const & argv);
  Nibbler(Nibbler const &);
  Nibbler &operator=(Nibbler const &);
  ~Nibbler();

public:
  void launchGame();
  void *getHandler() const;

};

#endif /* !_NIBBLER_HPP_ */
