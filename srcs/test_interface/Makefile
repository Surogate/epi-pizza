##
## Makefile for project in /u/all/pierro_a/cu/travail/c/
##
## Made by frederic1 pierronnet
## Login   <pierro_a@epitech.net>
##
## Started on  Fri Mar 26 22:19:44 2010 frederic1 pierronnet
## Last update Sun Apr  4 22:27:28 2010 frederic1 pierronnet
##

NAME		= client_graphique
SRCS		= srcs/main.c		\
		  srcs/xsdl.c		\
		  srcs/key.c		\
		  srcs/init.c		\
		  srcs/display.c	\
		  srcs/mouse.c
OBJS		= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -fv
OSNAME		= $(shell uname -s)
OSNAME		!= uname -s
CFLAGS		= -W -Wall -Wextra -ansi -pedantic
LDFLAGS_Linux	= -lSDLmain -lSDL -lSDL_ttf -lm
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