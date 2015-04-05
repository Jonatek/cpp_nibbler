//
// SDLGraphic.cpp for  in /home/quach_a/Lab/cpp_nibbler
//
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
//
// Started on  Wed Mar 25 21:21:53 2015 Jonathan Quach
// Last update Sun Apr  5 11:33:49 2015 Jonathan Quach
//

#include <iostream>
#include "SDLGraphic.hpp"

SDLGraphic::SDLGraphic()
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    throw ErrorException(std::string("Error SDL_Init : ")
			 + SDL_GetError());
    // Init SDL_tff lib
  if (TTF_Init() == -1)
    throw ErrorException(std::string("Error TTF_Init : ")
  			 + SDL_GetError());
}

SDLGraphic::~SDLGraphic()
{
  SDL_Quit();
  std::cout << "SDL QUIT !!!" << std::endl;
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
  this->_snakeTexture = SDL_LoadBMP("./texture/snakepart.bmp");
  this->_backgroundTexture = SDL_LoadBMP("./texture/background.bmp");
  this->_wallTexture = SDL_LoadBMP("./texture/wall.bmp");
  this->_foodTexture = SDL_LoadBMP("./texture/food.bmp");
  SDL_FillRect(this->_window, NULL,
	       SDL_MapRGB(this->_window->format, 0, 0, 0));
  SDL_WM_SetCaption("Nibbler", NULL);


  // Load font
  // TTF_Font *font;

  // if ((font = TTF_OpenFont("./OpenSans-Light.ttf", 16)) == NULL)
  //   throw ErrorException(std::string("Error TTF_OpenFont :")
  // 			 + SDL_GetError());

  // // Write text
  // SDL_Surface *_text;
  // SDL_Color text_color = {255, 255, 255};
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
	if (event.key.keysym.sym == SDLK_SPACE) // 32
	  return SPACE;
	if (event.key.keysym.sym == SDLK_p) // 112
	  return PAUSE;
	if (event.key.keysym.sym == SDLK_g) // 103
	  return GOD_MODE;
	if (event.key.keysym.sym == SDLK_f) // 102
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
