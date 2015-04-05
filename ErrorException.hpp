//
// ErrorException.hpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Tue Mar 24 15:33:42 2015 Jonathan Quach
// Last update Sun Apr  5 06:40:06 2015 Daniel Han
//

#ifndef _EXECPTION_HPP_
#define _EXECPTION_HPP_

#include <string>
#include <exception>

class ErrorException : public std::exception
{
private:
  std::string _msg;

public:
  ErrorException(std::string const &) throw();
  virtual ~ErrorException() throw();
  virtual const char *what() const throw();

};

#endif /* !_EXECPTION_HPP_ */
