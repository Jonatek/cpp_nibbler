##
## Makefile for  in /home/quach_a/Lab/cpp_nibbler
## 
## Made by Jonathan Quach
## Login  <jonathan.quach@epitech.eu>
## 
## Started on  Tue Mar 24 09:55:00 2015 Jonathan Quach
## Last update Sun Apr  5 10:28:39 2015 Jean-Paul SAYSANA
##

CORE		= 	nibbler

CPPFLAGS	+= 	-W -Wall -Werror -Wextra -fPIC

CPP		= 	g++

CORE_SRC	= 	main.cpp \
			ErrorException.cpp \
			Nibbler.cpp \
			Event.cpp \
			Position.cpp \
			Map.cpp \
			Snake.cpp \
			Game.cpp

CORE_OBJ	= 	$(CORE_SRC:.cpp=.o)

SDL		=	lib_nibbler_sdl.so

SDLFLAGS	=	-lSDL

SDL_SRC		=	SDLGraphic.cpp \
			ErrorException.cpp \
			Event.cpp \

SDL_OBJ		=	$(SDL_SRC:.cpp=.o)

NCURSES		=	lib_nibbler_ncurses.so

NCURSESFLAG	=	-lncurses

NCURSES_SRC	=	NcursesGraphic.cpp \
			ErrorException.cpp \
			Event.cpp \

NCURSES_OBJ	=	$(NCURSES_SRC:.cpp=.o)

XLIB		=	lib_nibbler_xlib.so

XLIBFLAGS	=	-L/usr/X11/lib -lX11

XLIB_SRC	=	xlib/XGraphic.cpp \
			ErrorException.cpp \
			Event.cpp \

XLIB_OBJ	=	$(XLIB_SRC:.cpp=.o)

SHARED		=	-shared

RM		= 	rm -f

all		:	$(CORE) $(SDL) $(NCURSES) $(XLIB)

$(CORE)		: 	$(CORE_OBJ)
	 		$(CPP) -o $(CORE) $(CORE_OBJ) -ldl -g3

$(SDL)		:	$(SDL_OBJ)
			$(CPP) -o $(SDL) $(SDL_OBJ) $(SDLFLAGS) $(SHARED) -g3

$(NCURSES)	:	$(NCURSES_OBJ)
			$(CPP) -o $(NCURSES) $(NCURSES_OBJ) $(NCURSESFLAG) $(SHARED) -g3

$(XLIB)		:	$(XLIB_OBJ)
			$(CPP) -o $(XLIB) $(XLIB_OBJ) $(XLIBFLAGS) $(SHARED) -g3

clean		:
			$(RM) $(CORE_OBJ) $(SDL_OBJ) $(NCURSES_OBJ) $(XLIB_OBJ)

fclean		: 	clean
			$(RM) $(CORE) $(SDL) $(NCURSES)

re		: 	fclean all

.PHONY		: 	all clean fclean re
