//
// Nibbler.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Tue Mar 24 15:05:43 2015 Jonathan Quach
// Last update Tue Mar 24 15:37:38 2015 Jonathan Quach
//

#include "Nibbler.hpp"
#include "Execption.hpp"

Nibbler::Nibbler(const std::vector<std::string> &argv)
  : _winX(1024), _winY(980)
{
  if (argv.size() != 4)
    throw Execption("Usage : " + av[0] +
		    " <width> <height> <lib_nibbler_XXX.so>");
}

Nibbler::~Nibbler()
{

}
