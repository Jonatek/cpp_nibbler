//
// Exception.cpp for Exception.cpp in /home/han_d/Github/cpp_nibbler
// 
// Made by Daniel Han
// Login   <han_d@epitech.net>
// 
// Started on  Tue Mar 24 15:01:57 2015 Daniel Han
// Last update Tue Mar 24 15:35:51 2015 Daniel Han
//

FileNameException::FileNameException()
{
  std::ostringstream oss;

  oss << "Error : invalid file name" << line + 
}

const char * FileNameException::what() const throw()
{
  return (this->_str.c_str());
}
