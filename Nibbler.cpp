//
// Nibbler.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Tue Mar 24 15:05:43 2015 Jonathan Quach
// Last update Wed Mar 25 22:26:25 2015 Jonathan Quach
//

#include <dlfcn.h>
#include "Nibbler.hpp"
#include "ErrorException.hpp"
#include "IGui.hpp"

Nibbler::Nibbler(const std::vector<std::string> &argv)
  : _winX(1024), _winY(980)
{
  int width;
  int height;
  void *dlHandle;
  std::string libName;
  std::stringstream ss;

  if (argv.size() != 4)
    throw ErrorException("Usage : " + argv[0] +
		    " <width> <height> <lib_nibbler_XXX.so>");
  ss.str(argv[1]);
  ss >> width;
  if (width < 5 || width > 100)
    throw ErrorException("Wrong size, <width> must be between 5 and 100");
  ss.clear();
  ss.str(argv[2]);
  ss >> height;
  if (height < 5 || height > 100)
    throw ErrorException("Wrong size, <height> must be between 5 and 100");
  _caseX = width;
  _caseY = height;
  ss.clear();
  ss.str(argv[3]);
  ss >> libName;

  // dl function
  if ((dlHandle = dlopen(libName.c_str(), RTLD_LAZY)) == NULL)
    throw ErrorException(dlerror());
  IGui *(*external_creator)();
  external_creator = reinterpret_cast<IGui* (*)()>(dlsym(dlHandle, "create_new_lib"));
  if (external_creator == NULL)
    {
      char *err = dlerror();
      throw ErrorException(std::string("Error searching for symbol : ") + err);
    }
  IGui *graphicLib = external_creator();
  graphicLib->createWindow(_winX, _winY);  
}

Nibbler::~Nibbler()
{

}
