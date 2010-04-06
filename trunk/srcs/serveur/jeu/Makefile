##
##
##
##
##

NAME			= debug_jeu
SRCS			= main.c

OBJS			= $(SRCS:.c=.o)
CC			= gcc
RM			= rm -rf
CFLAGS			+= -W -Wall -ansi -pedantic -g3

$(NAME)			: $(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all			: $(NAME)

clean			:
			$(RM) $(OBJS)
			$(RM) *~
			$(RM) \#*\#

fclean			: clean
			$(RM) $(NAME)

re			: fclean all