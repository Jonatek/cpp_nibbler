//
// main.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Tue Mar 24 10:13:04 2015 Jonathan Quach
// Last update Sun Apr  5 06:36:03 2015 Daniel Han
//

#include "Nibbler.hpp"

int main(int ac, char **av)
{
  std::vector<std::string> argv;

  for (int i = 0; i < ac; i++)
    argv.push_back(std::string(av[i]));
  try
    {
      srand(time(NULL));
      Nibbler *nib = new Nibbler(argv);
      nib->launchGame();
      dlclose(nib->getHandler());
    }
  catch (std::exception const & e)
    {
      std::cerr << e.what() << std::endl;
      return -1;
    }
  return 0;
}
