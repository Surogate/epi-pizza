##
## Makefile for MakeFile in /u/all/chanio_f/cu
##
## Made by florian chanioux
## Login   <chanio_f@epitech.net>
##
## Started on  Mon Oct 19 11:33:57 2009 florian chanioux
## Last update Mon Apr 12 19:47:47 2010 Florian Chanioux
##

STAG		= $(shell uname -s)
STAG		!= uname -s
MTAG		= $(shell uname -m)
MTAG		!= uname -m

TAG		= $(MTAG)-$(STAG)

NAME		= libxfunc_$(TAG).a

D_SRC		= srcs/
D_INC		= inc/

FILES_C		= $(D_SRC)my_aff_err.c			\
		  $(D_SRC)xmalloc.c			\
		  $(D_SRC)xrealloc.c			\
		  $(D_SRC)xread.c			\
		  $(D_SRC)xwrite.c			\
		  $(D_SRC)xopen.c			\
		  $(D_SRC)xclose.c			\

FILES_H		= xfunc.h

FILES_O		= $(FILES_C:.c=.o)

ETAGS		= etags

CC_FreeBSD	= gcc
CC_SunOS	= /usr/sfw/bin/gcc
CC_Linux	= gcc
CC_Darwin	= gcc -arch i386
CC		= $(CC_$(STAG))

AR		= ar
RANLIB		= ranlib
RM		= rm -f
CP		= cp
MV		= mv

INCLUDE		= -I$(D_INC)
CFLAGS		+= -W -Wall -ansi -pedantic $(INCLUDE)

##################################

.c.o		:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		: $(FILES_O)
	$(AR) r $(NAME) $(FILES_O)
	$(RANLIB) $(NAME)
	$(MV) $(NAME) ../

all		: $(NAME)

tags		:
	$(ETAGS) $(FILES_C) $(D_INC)$(FILES_H)

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
