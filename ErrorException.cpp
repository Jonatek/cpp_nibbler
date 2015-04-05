//
// ErrorException.cpp for  in /home/quach_a/Lab/cpp_nibbler
// 
// Made by Jonathan Quach
// Login  <jonathan.quach@epitech.eu>
// 
// Started on  Tue Mar 24 15:33:47 2015 Jonathan Quach
// Last update Sun Apr  5 06:12:23 2015 Daniel Han
//

#include "ErrorException.hpp"

ErrorException::ErrorException(std::string const & msg) throw()
{
  this->_msg = msg;
}

ErrorException::~ErrorException() throw()
{
}

const char *ErrorException::what() const throw()
{
  return this->_msg.c_str();
}
