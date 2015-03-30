//
// SDLGraphic.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Wed Mar 25 21:21:53 2015 Jonathan Quach
// Last update Mon Mar 30 17:49:28 2015 Daniel Han
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
  _backgroundTexture = SDL_LoadBMP("./background.bmp");
  SDL_FillRect(_window, NULL, SDL_MapRGB(_window->format, 0, 0, 0));
  SDL_WM_SetCaption("Nibbler", NULL);
}

void SDLGraphic::updateEvent(Event &_newEvent)
{
  SDL_Event event;

  SDL_PollEvent(&event);
  switch (event.type)
    {
    case SDL_KEYDOWN:
      {
	if (event.key.keysym.sym == SDLK_ESCAPE)
	  _newEvent.setEventType(QUIT);
	if (event.key.keysym.sym == SDLK_LEFT)
	  _newEvent.setEventType(LEFT);
	if (event.key.keysym.sym == SDLK_RIGHT)
	  _newEvent.setEventType(RIGHT);
      }
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

void SDLGraphic::removeSquare(int const &x, int const &y)
{
  SDL_Rect pos;

  pos.x = x * 20;
  pos.y = y * 20;

  SDL_BlitSurface(_backgroundTexture, NULL, _window, &pos);
  SDL_Flip(_window);
}

extern "C"
{
  IGui *create_lib_instance()
  {
    return new SDLGraphic;
  }
}
