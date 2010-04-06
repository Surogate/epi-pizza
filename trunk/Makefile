##
## Makefile for  in /home/Ayden/Epitech/my_ftp
## 
## Made by Florian Chanioux
## Login   <chanio_f@epitech.net>
## 
## Started on  Thu Mar  4 18:50:14 2010 Florian Chanioux
## Last update Tue Apr  6 15:00:13 2010 Florian Chanioux
##

STAG	= 	$(shell uname -s)
STAG	!= 	uname -s
MTAG	= 	$(shell uname -m)
MTAG	!= 	uname -m

TAG	=	$(MTAG)-$(STAG)

# PROJECT

NAME_C	=	client

NAME_S	=	serveur

# BINARIES

CC	=	gcc
RM	=	rm -f
CD	=	cd
ETAGS	=	etags
CP	=	cp

# COLOR

END	=	\033[m
RED	=	\033[31m
GREEN	=	\033[32m
CYAN	=	\033[36m
GREY	=	\033[37m

# DIRECTORIES

DIR_SRC	=	./srcs/
DIR_INC	=	./inc/
DIR_LIB	=	./lib/

# FILES

DIR_SRC_S	=	$(DIR_SRC)serveur/
DIR_SRC_C	=	$(DIR_SRC)client/
DIR_SRC_CO	=	$(DIR_SRC)commun/


SRC_S	=	$(DIR_SRC_S)main.c

SRC_C	=	$(DIR_SRC_C)main.c

SRC_CO	=	



OBJ_S	=	$(SRC_S:.c=.o)
OBJ_C	=	$(SRC_C:.c=.o)
OBJ_CO	=	$(SRC_CO:.c=.o)

# FLAGS

DEFINE_sun4u-SunOS	=
DEFINE_i386-FreeBSD	=
DEFINE_i686-Linux	=

LFLAGS_sun4u-SunOS	=
LFLAGS_i386-FreeBSD	=	`sdl-config --cflags --libs` -lSDL
LFLAGS_i686-Linux	=	`sdl-config --cflags --libs` -lSDL

LFLAGS		=	-L$(DIR_LIB) $(LFLAGS_$(TAG))
IFLAGS		=	-I$(DIR_INC)
CFLAGS		+=	-W -Wall -ansi -pedantic $(DEFINE_$(TAG)) $(IFLAGS)

# OTHERS

all	:	$(NAME_C) $(NAME_S)

$(NAME_C)	:	$(OBJ_C) $(OBJ_CO)
	@echo -e "$(CYAN)[LINKING]: $(NAME_C)$(END)"
	$(CC) -o $(NAME_C) $(OBJ_C) $(OBJ_CO) $(LFLAGS)
	@echo -e "$(GREEN)[LINKING] - DONE$(END)"

$(NAME_S)	:	$(OBJ_S) $(OBJ_CO)
	@echo -e "$(CYAN)[LINKING]: $(NAME_C)$(END)"
	$(CC) -o $(NAME_S) $(OBJ_S) $(OBJ_CO) $(LFLAGS)
	@echo -e "$(GREEN)[LINKING] - DONE$(END)"

tags	:
	@echo -e "$(CYAN)[TAGGING]$(END)"
	$(ETAGS) $(DIR_INC)*.h $(SRC_S) $(SRC_CO) $(SRC_C)
	@echo -e "$(GREEN)[TAGGING] - DONE$(END)"

.SUFIXIES	:	.c .o
.c.o	:
	@echo -e "$(GREY)[OBJ]"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "[OBJ] -DONE$(END)"

#CLEAN OPTION

clean	:
	$(RM) $(OBJ_C)
	$(RM) $(OBJ_CO)
	$(RM) $(OBJ_S)

fclean	:	clean
	$(RM) $(NAME_C)
	$(RM) $(NAME_S)

cleanall:	fclean
	@$(CD) $(DIR_INC); $(RM) *~
	@$(CD) $(DIR_SRC_C); $(RM) *~
	@$(CD) $(DIR_SRC_CO); $(RM) *~
	@$(CD) $(DIR_SRC_S); $(RM) *~
	$(RM) *~
	$(RM) TAGS

re	:	fclean	all

.PHONY	:	$(NAME_C) $(NAME_S) all .c.o library clean fclean re cleanall

#EOF