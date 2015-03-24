//
// main.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Tue Mar 24 10:13:04 2015 Jonathan Quach
// Last update Tue Mar 24 15:43:55 2015 Jonathan Quach
//

#include "Nibbler.hpp"

int		main(int ac, char **av)
{
  std::vector<std::string> argv;

  for (int i = 0; i < ac; i++)
    argv.push_back(std::string(av[i]));
  try
    {
      srand(time(NULL));
      Nibbler *nib = new Nibbler(argv);
    }
  catch (std::exception const &e)
    {
      std::cerr << e.what() << std::endl;
    }
  
  return 0;
}
