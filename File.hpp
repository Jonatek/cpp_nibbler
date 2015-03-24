//
// File.hh for File.hh in /home/han_d/Github/cpp_nibbler
// 
// Made by Daniel Han
// Login   <han_d@epitech.net>
// 
// Started on  Tue Mar 24 14:23:35 2015 Daniel Han
// Last update Tue Mar 24 14:46:02 2015 Daniel Han
//

#ifndef		FILE_HPP_
# define	FILE_HPP_

class		File
{
private:
  int x_map;
  int y_map;
  int x_snake;
  int y_snake;
  int x_food;
  int y_food;

public:
  File();
  ~File();
  File(File const &);
  File &operator=(File const &);

};

#endif	/*	!FILE_HPP_	*/
