//
// Nibbler.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Tue Mar 24 15:05:43 2015 Jonathan Quach
// Last update Thu Apr  2 19:47:18 2015 Jean-Paul SAYSANA
//

#include <dlfcn.h>
#include "Nibbler.hpp"
#include "ErrorException.hpp"
#include "IGui.hpp"
#include "Event.hpp"
#include "Snake.hpp"
#include "Map.hpp"
#include "Game.hpp"

Nibbler::Nibbler(const std::vector<std::string> &argv)
  : _winX(1024), _winY(980), _loop(true)
{
  int width;
  int height;
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
  // void *dlopen(const char *filename, int flag)
  // dlopen loads the dynamic library file, and return an "opaque" handle
  // RTDL_LAZY -> lazy binding. Only resolve symbols as the code it need it is exec
  // RTDL_NOW -> all undefined symbols in the lib are resolved before dlopen return

  // char *dlerror(void)
  // return an human readeable string describing the most recent error
  // from dlopen, dlsym or dlclose. NULL if no error

  if ((_handle = dlopen(libName.c_str(), RTLD_LAZY)) == NULL)
    throw ErrorException(dlerror());

  // void *dlsym(void *handle, const char *symbol)
  // take handle and an symbol name, it return the address where the symbol is
  // loaded into memory. NULL in error, but it can also return NULL as a symbol
  // so it's not an error. call dlerror to check that.

  IGui *(*external_creator)();
  external_creator = reinterpret_cast<IGui* (*)()>(dlsym(_handle,
							 "create_lib_instance"));
  if (external_creator == NULL)
    {
      char *err = dlerror();
      throw ErrorException(std::string("Error searching for symbol : ") + err);
    }

   _gui = external_creator();
}

Nibbler::~Nibbler()
{

}

Nibbler::Nibbler(Nibbler const &other)
{
  this->_winX = other._winX;
  this->_winY = other._winY;
  this->_caseX = other._caseX;
  this->_caseY = other._caseY;
  this->_handle = other._handle;
  this->_gui = other._gui;
  this->_loop = other._loop;
}

Nibbler		&Nibbler::operator=(Nibbler const &other)
{
  if (this != &other)
    {
      this->_winX = other._winX;
      this->_winY = other._winY;
      this->_caseX = other._caseX;
      this->_caseY = other._caseY;
      this->_handle = other._handle;
      this->_gui = other._gui;
      this->_loop = other._loop;
    }
  return (*this);
}

void	Nibbler::loop()
{
  Event _ev;

  _gui->createWindow(_winX, _winY);
  // Game _game(_gui, _caseX, _caseY);
    
  Snake         _game(_caseX, _caseY, _gui);
  Map		_map(_caseX, _caseY);

  while (_loop)
    {
      // _game->startGame();

      _gui->updateEvent(_ev);
      if (_ev.getEventType() == QUIT)
        _loop = false;
      _game.move(_ev.getEventType());
      usleep(50000);
    }
}


/**
   afficher la map entiere
   je balance la map en param
   
 **/

void		Nibbler::launchGame()
{
  //loop();
  Game		game(_winX, _winY, _caseX, _caseY, _gui);
}

void		*Nibbler::getHandler() const
{
  return _handle;
}
