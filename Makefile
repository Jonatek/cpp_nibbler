##
## Makefile for  in /home/quach_a/Lab/cpp_nibbler
## 
## Made by Jonathan Quach
## Login  <jonathan.quach@epitech.eu>
## 
## Started on  Tue Mar 24 09:55:00 2015 Jonathan Quach
## Last update Wed Mar 25 22:25:26 2015 Jonathan Quach
##

CORE		= 	nibbler

CPPFLAGS	+= 	-W -Wall -Werror -Wextra -fPIC

CPP		= 	g++

CORE_SRC	= 	main.cpp \
			ErrorException.cpp \
			Nibbler.cpp \

CORE_OBJ	= 	$(CORE_SRC:.cpp=.o)

SDL		=	lib_nibbler_sdl.so

SDLFLAGS	=	-lSDL2

SDL_SRC		=	SDLGraphic.cpp \
			ErrorException.cpp \

SDL_OBJ		=	$(SDL_SRC:.cpp=.o)

SHARED		=	-shared

RM		= 	rm -f

all:		$(CORE) $(SDL)

$(CORE): 	$(CORE_OBJ)
	 	$(CPP) -o $(CORE) $(CORE_OBJ) -ldl

$(SDL):		$(SDL_OBJ)
		$(CPP) -o $(SDL) $(SDL_OBJ) $(SDLFLAGS) $(SHARED)

clean:
		$(RM) $(CORE_OBJ) $(SDL_OBJ)

fclean: 	clean
		$(RM) $(CORE) $(SDL)

re: 		fclean all

.PHONY: 	all clean fclean re
