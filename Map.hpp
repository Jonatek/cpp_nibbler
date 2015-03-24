//
// Map.hpp for Map.hpp in /home/han_d/Github/cpp_nibbler
// 
// Made by Daniel Han
// Login   <han_d@epitech.net>
// 
// Started on  Tue Mar 24 15:28:51 2015 Daniel Han
// Last update Tue Mar 24 15:38:27 2015 Daniel Han
//

#ifndef		MAP_HPP_
# define	MAP_HPP_

class		Map
{
private:
  std::vector<std::string> _map;

public:
  Map(int x, int y);
  ~Map();
  Map(Map const &);
  Map &operator=(Map const &);

};

#endif	/*	!MAP_HPP_	*/
