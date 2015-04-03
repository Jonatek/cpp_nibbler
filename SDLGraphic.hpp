//
// SDLGraphic.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Wed Mar 25 21:24:46 2015 Jonathan Quach
// Last update Fri Apr  3 17:16:37 2015 Jonathan Quach
//

#ifndef _SDLGRAPHIC_HPP
# define _SDLGRAPHIC_HPP

#include <SDL/SDL.h>
#include <string>
#include <vector>
#include "IGui.hpp"
#include "ErrorException.hpp"
#include "Event.hpp"
#include "Map.hpp"

class SDLGraphic : public IGui
{
private:
  SDL_Surface *_window;
  SDL_Surface *_backgroundTexture;
  SDL_Surface *_snakeTexture;
  SDL_Surface *_foodTexture;

public:
  SDLGraphic();
  virtual ~SDLGraphic();

  virtual void createWindow(int, int);
  virtual void updateEvent(Event &);
  virtual void drawSquare(int, int, ObjectType);
  virtual void removeSquare(int, int);
};

extern "C"
{
  IGui *create_lib_instance();
}

#endif
