//
// SDLGraphic.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Wed Mar 25 21:24:46 2015 Jonathan Quach
// Last update Sun Apr  5 11:36:35 2015 Jonathan Quach
//

#ifndef _SDLGRAPHIC_HPP_
# define _SDLGRAPHIC_HPP_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>
#include <vector>
#include "IGui.hpp"
#include "ErrorException.hpp"
#include "Event.hpp"
#include "Map.hpp"

class SDLGraphic : public IGui
{
  //
  // Attributs
  //
private:
  SDL_Surface *_window;
  SDL_Surface *_backgroundTexture;
  SDL_Surface *_wallTexture;
  SDL_Surface *_snakeTexture;
  SDL_Surface *_foodTexture;

public:
  SDLGraphic();
  virtual ~SDLGraphic();

public:
  virtual void createWindow(int const, int const);
  virtual EventType updateEvent();
  virtual void drawSquare(int const, int const, ObjectType const);
  virtual void removeSquare(int const, int const);

};

extern "C"
{
  IGui *create_lib_instance();
}

#endif /* !_SDL_GRAPHIC_HPP_ */
