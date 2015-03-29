//
// SDLGraphic.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Wed Mar 25 21:24:46 2015 Jonathan Quach
// Last update Sun Mar 29 15:59:47 2015 Jonathan Quach
//

#ifndef _SDLGRAPHIC_HPP
# define _SDLGRAPHIC_HPP

#include <SDL/SDL.h>
#include <string>
#include "IGui.hpp"
#include "ErrorException.hpp"
#include "Event.hpp"

class SDLGraphic : public IGui
{
private:
  SDL_Surface *_window;
  // SDL_Surface *_backgroundTexture;
  SDL_Surface *_snakeTexture;
  // SDL_Surface *_foodTexture;

public:
  SDLGraphic();
  virtual ~SDLGraphic();

  virtual void createWindow(int const &x, int const &y);
  virtual void updateEvent(Event &);
  virtual void drawSquare(int const &x, int const &y, ElementType);
};

extern "C"
{
  IGui *create_lib_instance();
}

#endif
