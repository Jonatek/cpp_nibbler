//
// SDLGraphic.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Wed Mar 25 21:21:53 2015 Jonathan Quach
// Last update Sun Mar 29 16:28:39 2015 Jonathan Quach
//

#include <iostream>
#include "SDLGraphic.hpp"

SDLGraphic::SDLGraphic()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    throw ErrorException(std::string("Error SDL_Init : ")
			 + SDL_GetError());
}

SDLGraphic::~SDLGraphic()
{
  SDL_Quit();
}

void SDLGraphic::createWindow(int const &x, int const &y)
{
  // std::string err;

  // window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
  // 			     SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
  // 			     SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

  // if ((_mainWindow = SDL_CreateWindow("Nibbler", 0, 0, x, y,
  // 				      SDL_WINDOW_SHOWN)) == NULL)
  //   throw ErrorException(std::string("Error SDL_CreateWindow : ")
  // 			 + SDL_GetError());

  _window = SDL_SetVideoMode(x, y, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  _snakeTexture = SDL_LoadBMP("./snakepart.bmp");
  SDL_FillRect(_window, NULL, SDL_MapRGB(_window->format, 0, 0, 0));
  SDL_WM_SetCaption("Nibbler", NULL);
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

void SDLGraphic::drawSquare(int const &x, int const &y, ElementType type)
{
  SDL_Rect pos;

  pos.x = x * 20;
  pos.y = y * 20;

  std::cout << pos.x << " " << pos.y << std::endl;
  if (type == BODY)
    {
      SDL_BlitSurface(_snakeTexture, NULL, _window, &pos);
      // std::cout << "rendering "  << x << " " << y << std::endl;
      // SDL_RenderCopy(_mainRenderer, _snakeTexture, NULL, &pos);
    }
  SDL_Flip(_window);
}

extern "C"
{
  IGui *create_lib_instance()
  {
    return new SDLGraphic;
  }
}
