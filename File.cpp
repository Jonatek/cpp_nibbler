//
// File.cpp for File.cpp in /home/han_d/Github/cpp_nibbler
// 
// Made by Daniel Han
// Login   <han_d@epitech.net>
// 
// Started on  Tue Mar 24 14:25:58 2015 Daniel Han
// Last update Sun Mar 29 18:25:41 2015 Jean-Paul SAYSANA
//

File::File()
{
}

File::~File()
{
}

File::File(File const &other)
{
  this->x_map = other.x_map;
  this->y_map = other.y_map;
  this->x_snake = other.x_snake;
  this->y_snake = other.y_snake;
  this->x_food = other.x_food;
  this->y_food = other.y_food;
}

File & File::operator=(File const &other)
{
  if (this != &other)
    {
      this->x_map = other.x_map;
      this->y_map = other.y_map;
      this->x_snake = other.x_snake;
      this->y_snake = other.y_snake;
      this->x_food = other.x_food;
      this->y_food = other.y_food;
    }
  return (*this);
}

bool File::parsingFile(char *filename)
{
  
}
