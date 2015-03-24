//
// ErrorException.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Tue Mar 24 15:33:47 2015 Jonathan Quach
// Last update Tue Mar 24 15:35:54 2015 Jonathan Quach
//

#include "ErrorException.hpp"

ErrorException::ErrorException(std::string const &msg) throw()
{
  _msg = msg;
}

ErrorException::~ErrorException() throw()
{

}

const char *ErrorException::what() const throw()
{
  return _msg.c_str();
}
