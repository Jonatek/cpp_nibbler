//
// Exception.hpp for Exception.hpp in /home/han_d/Github/cpp_nibbler
// 
// Made by Daniel Han
// Login   <han_d@epitech.net>
// 
// Started on  Tue Mar 24 14:53:20 2015 Daniel Han
// Last update Tue Mar 24 15:01:48 2015 Daniel Han
//

#ifndef EXCEPTION_HPP_
# define EXCEPTION_HPP_

class FileNameException : public std::exception
{
private:
std::string _str;

public:
FileNameException();
virtual ~FileNameException() throw() {}

public:
virtual const char *what() const throw();
};

#endif /* !EXCEPTION_HPP_ */
