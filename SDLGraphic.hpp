//
// SDLGraphic.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Wed Mar 25 21:24:46 2015 Jonathan Quach
// Last update Thu Mar 26 22:00:58 2015 Jonathan Quach
//

#ifndef _SDLGRAPHIC_HPP
# define _SDLGRAPHIC_HPP

#include <SDL2/SDL.h>
#include <string>
#include "IGui.hpp"
#include "ErrorException.hpp"
#include "Event.hpp"

class SDLGraphic : public IGui
{
private:
  SDL_Window *_win;

public:
  SDLGraphic();
  ~SDLGraphic();

  virtual void createWindow(const int &x, const int &y);
  virtual void updateEvent(Event &);
};

#endif
