//
// SDLGraphic.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Wed Mar 25 21:21:53 2015 Jonathan Quach
// Last update Thu Mar 26 23:51:27 2015 Jonathan Quach
//

#include "SDLGraphic.hpp"

SDLGraphic::SDLGraphic()
{

}

SDLGraphic::~SDLGraphic()
{
  // SDL_Quit();
}

void SDLGraphic::createWindow(const int &x, const int &y)
{
  // std::string err;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    throw ErrorException(std::string("Error SDL_Init : ") + SDL_GetError());

  // window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
  // 			     SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
  // 			     SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

  if ((_win = SDL_CreateWindow("Nibbler", 0, 0, x, y, SDL_WINDOW_SHOWN)) == NULL)
    throw ErrorException(std::string("Error SDL_CreateWindow : ") + SDL_GetError());
}

void SDLGraphic::updateEvent(Event &_newEvent)
{
  SDL_Event event;

  while (SDL_PollEvent(&event))
    {
      if (event.key.keysym.sym == SDLK_ESCAPE)
        _newEvent.setEventType(QUIT);
    }
}

extern "C"
{
  IGui *create_lib_instance()
  {
    return new SDLGraphic;
  }
}
