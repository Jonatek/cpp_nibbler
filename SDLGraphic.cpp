//
// SDLGraphic.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Wed Mar 25 21:21:53 2015 Jonathan Quach
// Last update Wed Apr  1 10:54:22 2015 Jean-Paul SAYSANA
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

void SDLGraphic::createWindow(int x, int y)
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
  _wallTexture = SDL_LoadBMP("./wall.bmp");
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
	if (event.key.keysym.sym == SDLK_RETURN)
	  _newEvent.setEventType(ENTER);
	if (event.key.keysym.sym == SDLK_ESCAPE)
	  _newEvent.setEventType(QUIT);
	if (event.key.keysym.sym == SDLK_LEFT)
	  _newEvent.setEventType(LEFT);
	if (event.key.keysym.sym == SDLK_RIGHT)
	  _newEvent.setEventType(RIGHT);
      }
    }
}

void SDLGraphic::drawSquare(int x, int y, ElementType type)
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
  if (type == WALL)
    SDL_BlitSurface(_backgroundTexture, NULL, _window, &pos);
  SDL_Flip(_window);
}

void SDLGraphic::removeSquare(int x, int y)
{
  SDL_Rect pos;

  pos.x = x * 20;
  pos.y = y * 20;

  SDL_BlitSurface(_backgroundTexture, NULL, _window, &pos);
  SDL_Flip(_window);
}

void		SDLGraphic::makeWall(int x, int y)
{
  SDL_Rect	pos;

  pos.x = 0;
  pos.y = 0;
  for (pos.x = 0; pos.x < x - 19; ++pos.x)
    SDL_BlitSurface(_wallTexture, NULL, _window, &pos);
  for (pos.y = 0; pos.y < y - 19; ++pos.y)
    {
      SDL_BlitSurface(_wallTexture, NULL, _window, &pos);
      ++pos.y;
    }
  pos.x = 0;
  for (pos.y = 0; pos.y < y - 19; ++pos.y)
    {
      SDL_BlitSurface(_wallTexture, NULL, _window, &pos);
      ++pos.y;
    }
  for (pos.x = 0; pos.x < x; ++pos.x)
    {
      SDL_BlitSurface(_wallTexture, NULL, _window, &pos);
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
