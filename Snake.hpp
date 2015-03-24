//
// snake.hh for qsd in /home/saysan_j/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Tue Mar 24 12:26:40 2015 Jean-Paul SAYSANA
// Last update Tue Mar 24 14:47:06 2015 Jean-Paul SAYSANA
//

#ifndef		SNAKE_HPP_
# define	SNAKE_HPP_

class		Snake
{
private:
  int		direction;
  int		snakeSize;

public:
  Snake();
  ~Snake() {};
  Snake(Snake const &);
  Snake &operator=(Snake const &);

  /******************************/
  /*		CHANGES		*/
  /******************************/

  void		growUp();

  /******************************/
  /*		MOVE		*/
  /******************************/

  void		moveUp();
  void		moveDown();
  void		moveLeft();
  void		moveRight();

  enum direction
    {
      NONE,
      UP,
      RIGHT,
      DOWN,
      LEFT
    };
};

#endif	/*	!SNAKE_HPP_	*/
