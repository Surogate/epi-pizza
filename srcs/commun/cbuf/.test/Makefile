##
## Makefile for project in /u/all/ancel_a/cu/travail/c/
##
## Made by francois1 ancel
## Login   <ancel_a@epitech.net>
##
## Started on  Thu Mar 18 16:46:27 2010 francois1 ancel
## Last update Thu Mar 18 16:46:27 2010 francois1 ancel
##

NAME	= prog
CC	= gcc
RM	= rm -rf
SRCS	= cbuf_io.c		\
	cbuf_debug.c		\
	cbuf_new.c		\
	main.c

OBJS	= $(SRCS:.c=.o)
CFLAGS	= -W -Wall -Wextra -g3 -ansi
LDFLAGS	= -lc

$(NAME)	: $(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all