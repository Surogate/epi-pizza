##
## Makefile for project in /u/all/pierro_a/cu/travail/c/
##
## Made by frederic1 pierronnet
## Login   <pierro_a@epitech.net>
##
## Started on  Fri Mar 26 22:19:44 2010 frederic1 pierronnet
## Last update Sun Apr  4 22:27:28 2010 frederic1 pierronnet
##

NAME		= interface
SRCS		= main.c
OBJS		= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -rf
OSNAME		= $(shell uname -s)
OSNAME		!= uname -s
CFLAGS		= -W -Wall -Wextra -ansi -pedantic -I. -Imenu -D_BSD_SOURCE -D_SVID_SOURCE -D_XOPEN_SOURCE -D_ISOC99_SOURCE
LDFLAGS_Linux	= -lSDLmain -lSDL -lSDL_ttf -lm
LDFLAGS_FreeBSD	= -L/usr/local/lib -Wl,-rpath,/usr/local/lib -lSDL -lpthread -lSDL_ttf -lm

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