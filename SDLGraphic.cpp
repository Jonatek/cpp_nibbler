//
// SDLGraphic.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Wed Mar 25 21:21:53 2015 Jonathan Quach
// Last update Sun Apr  5 07:14:25 2015 Daniel Han
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

void SDLGraphic::createWindow(int const x, int const y)
{
  // std::string err;

  // window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
  // 			     SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
  // 			     SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

  // if ((_mainWindow = SDL_CreateWindow("Nibbler", 0, 0, x, y,
  // 				      SDL_WINDOW_SHOWN)) == NULL)
  //   throw ErrorException(std::string("Error SDL_CreateWindow : ")
  // 			 + SDL_GetError());

  this->_window = SDL_SetVideoMode(x, y, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  this->_snakeTexture = SDL_LoadBMP("./snakepart.bmp");
  this->_backgroundTexture = SDL_LoadBMP("./background.bmp");
  this->_wallTexture = SDL_LoadBMP("./wall.bmp");
  this->_foodTexture = SDL_LoadBMP("./food.bmp");
  SDL_FillRect(this->_window, NULL,
	       SDL_MapRGB(this->_window->format, 0, 0, 0));
  SDL_WM_SetCaption("Nibbler", NULL);
}

EventType SDLGraphic::updateEvent()
{
  SDL_Event event;

  SDL_PollEvent(&event);
  switch (event.type)
    {
    case SDL_KEYDOWN:
      {
	if (event.key.keysym.sym == SDLK_RETURN)
	  return ENTER;
	if (event.key.keysym.sym == SDLK_ESCAPE)
	  return QUIT;
	if (event.key.keysym.sym == SDLK_LEFT)
	  return LEFT;
	if (event.key.keysym.sym == SDLK_RIGHT)
	  return RIGHT;
	if (event.key.keysym.sym == SDLK_SPACE)
	  return SPACE;
	if (event.key.keysym.sym == SDLK_p)
	  return PAUSE;
	if (event.key.keysym.sym == SDLK_g)
	  return GOD_MODE;
	if (event.key.keysym.sym == SDLK_f)
	  return FOOD_PUSH;
      }
    }
  return NONE;
}

void SDLGraphic::drawSquare(int const x, int const y, ObjectType const type)
{
  SDL_Rect pos;

  pos.x = x * 20;
  pos.y = y * 20;

  // std::cout << pos.x << " " << pos.y << std::endl;
  if (type == BODY)
    {
      SDL_BlitSurface(_snakeTexture, NULL, _window, &pos);
      // std::cout << "rendering "  << x << " " << y << std::endl;
      // SDL_RenderCopy(_mainRenderer, _snakeTexture, NULL, &pos);
    }
  else if (type == WALL || type == BLOCK) // need something else
    SDL_BlitSurface(this->_wallTexture, NULL, this->_window, &pos);
  else if (type == FOOD || type == POISON) // need something else
    SDL_BlitSurface(this->_foodTexture, NULL, this->_window, &pos);
  else if (type == NOTHING)
    SDL_BlitSurface(this->_backgroundTexture, NULL, this->_window, &pos);
  SDL_Flip(this->_window);
}

void	SDLGraphic::removeSquare(int const x, int const y)
{
  SDL_Rect pos;

  pos.x = x * 20;
  pos.y = y * 20;

  SDL_BlitSurface(this->_backgroundTexture, NULL, this->_window, &pos);
  SDL_Flip(this->_window);
}

extern "C"
{
  IGui *create_lib_instance()
  {
    return new SDLGraphic;
  }
}
