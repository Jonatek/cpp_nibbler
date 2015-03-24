##
## Makefile for  in /home/quach_a/Lab/cpp_nibbler
## 
## Made by Jonathan Quach
## Login  <jonathan.quach@epitech.eu>
## 
## Started on  Tue Mar 24 09:55:00 2015 Jonathan Quach
## Last update Tue Mar 24 15:36:52 2015 Jonathan Quach
##

NAME		= 	nibbler

CPPFLAGS	+= 	-W -Wall -Werror -Wextra

CPP		= 	g++

SRC		= 	main.cpp \
			ErrorException.cpp \
			Nibbler.cpp \

OBJ		= 	$(SRC:.cpp=.o)

RM		= 	rm -f

all:		$(NAME)

$(NAME): 	$(OBJ)
	 	$(CPP) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
