##
## Makefile for MakeFile in /u/all/chanio_f/cu
##
## Made by florian chanioux
## Login   <chanio_f@epitech.net>
##
## Started on  Mon Oct 19 11:33:57 2009 florian chanioux
## Last update Fri Apr  9 14:39:14 2010 Florian Chanioux
##

NAME		= libmylist_`uname -m`-`uname -s`.a

D_SRC		= srcs/
D_INC		= inc/

FILES_C 	= $(D_SRC)my_l_init.c		\
		  $(D_SRC)my_l_insert.c		\
		  $(D_SRC)my_l_rm_all.c		\
		  $(D_SRC)my_l_rm_iem.c		\
		  $(D_SRC)my_l_rm.c		\
		  $(D_SRC)my_l_sort.c		\
		  $(D_SRC)my_l_concat.c		\
		  $(D_SRC)my_l_size.c		\
		  $(D_SRC)my_l_apply.c		\
		  $(D_SRC)my_l_apply_iem.c	\
		  $(D_SRC)my_l_free.c		\
		  $(D_SRC)my_l_rev.c		\
		  $(D_SRC)my_l_iem.c		\
		  $(D_SRC)my_l_find.c		\

FILES_H		= my_list.h

FILES_O		= $(FILES_C:.c=.o)


ETAGS		= etags
CC		= gcc
AR		= ar
RANLIB		= ranlib
RM		= rm -f
CP		= cp
MV		= mv

INCLUDE		= -I. -I$(D_INC) -I$(MYHOME)/include/
CFLAGS		+= -W -Wall -ansi -pedantic $(INCLUDE)

##################################

.c.o		:
	$(CC) $(CFLAGS) $(MYLIB) -c $< -o $@

$(NAME)		: $(FILES_O)
	$(AR) r $(NAME) $(FILES_O)
	$(RANLIB) $(NAME)
	$(MV) $(NAME) ../

all		: $(NAME)

tags		:
	$(ETAGS) $(FILES_C) $(FILES_H)

clean		:
	$(RM) $(FILES_O)

fclean		: clean
	$(RM) ../$(NAME)

cleanall	: fclean
	$(RM) $(D_SRC)*~  $(D_SRC)\#*\#
	$(RM) $(D_INC)*~  $(D_INC)\#*\#
	$(RM) *~ \#*\#
	$(RM) .DS_Store
	$(RM) TAGS

re		: fclean all

.phony		: $(NAME) all clean fclean cleanall re tags lib
