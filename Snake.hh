//
// snake.hh for qsd in /home/saysan_j/cpp_nibbler
// 
// Made by Jean-Paul SAYSANA
// Login   <saysan_j@epitech.net>
// 
// Started on  Tue Mar 24 12:26:40 2015 Jean-Paul SAYSANA
// Last update Tue Mar 24 13:08:46 2015 Jean-Paul SAYSANA
//

#ifndef		SNAKE_H_
# define	SNAKE_H_

class		Snake
{
private:
  int		direction;

public:
  Snake();
  ~Snake() {};
  Snake(Snake const &);
  Snake &operator=(Snake const &);

  /******************************/
  /*		CHANGES		*/
  /******************************/

  void		eatFruits();
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
      UP,
      DOWN,
      LEFT,
      RIGHT
    };

  /******************************/
  /*
  /******************************/

};

#endif	/*	!SNAKE_H_	*/
