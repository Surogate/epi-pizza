##
## Makefile for project in /u/all/pierro_a/cu/travail/c/
##
## Made by frederic1 pierronnet
## Login   <pierro_a@epitech.net>
##
## Started on  Fri Mar 26 22:19:44 2010 frederic1 pierronnet
## Last update Wed Apr 14 15:03:57 2010 Florian Chanioux
##

NAME		= client_graphique
SRCS		= srcs/main.c		\
		  srcs/xsdl.c		\
		  srcs/key.c		\
		  srcs/init.c		\
		  srcs/display.c	\
		  srcs/glmain.c		\
		  srcs/interaction.c	\
		  srcs/mouse.c

OBJS		= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -fv
OSNAME		= $(shell uname -s)
OSNAME		!= uname -s
CFLAGS		= -W -Wall -Wextra -ansi -pedantic
LDFLAGS_Linux	=  `sdl-config --cflags --libs` -lSDL -lSDL_ttf  -lGL -lGLU -lglut 
LDFLAGS_FreeBSD	= -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lSDL -lpthread -lSDL_ttf

all		: $(NAME)

$(NAME)		: $(OBJS)
		$(CC) $(LDFLAGS_$(OSNAME)) -o $(NAME) $(OBJS)
.c.o		:
		$(CC) $(CFLAGS) -c -o $@ $<

clean		:
		$(RM) $(OBJS)

fclean		: clean
		$(RM) $(NAME)

re		: fclean all