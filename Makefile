##
## Makefile for  in /home/Ayden/Epitech/my_ftp
## 
## Made by Florian Chanioux
## Login   <chanio_f@epitech.net>
## 
## Started on  Thu Mar  4 18:50:14 2010 Florian Chanioux
## Last update Mon Apr 12 19:53:47 2010 Florian Chanioux
##

STAG	= 	$(shell uname -s)
STAG	!= 	uname -s
MTAG	= 	$(shell uname -m)
MTAG	!= 	uname -m

TAG	=	$(MTAG)-$(STAG)

############### PROJECT

NAME	=	zappi
NAME_C	=	client
NAME_S	=	serveur

############### DIRECTORIES

DIR_SRC	=	./srcs/
DIR_INC	=	./inc/
DIR_LIB	=	./lib/

############### FILES

DIR_SRC_S	=	$(DIR_SRC)serveur/
DIR_SRC_C	=	$(DIR_SRC)client/
DIR_SRC_CO	=	$(DIR_SRC)commun/


SRC_S	=	$(DIR_SRC_S)main.c			\
		$(DIR_SRC_S)server_map.c		\
		$(DIR_SRC_S)test_map.c			\
		$(DIR_SRC_S)server_stt.c		\
		$(DIR_SRC_S)server_fct.c		\
		$(DIR_SRC_S)server_ini.c		\
		$(DIR_SRC_S)instruction.c		\
		$(DIR_SRC_S)jeu/hatch.c			\
		$(DIR_SRC_S)jeu/incant.c		\
		$(DIR_SRC_S)jeu/instr_broadcast.c	\
		$(DIR_SRC_S)jeu/invent.c		\
		$(DIR_SRC_S)jeu/move.c			\
		$(DIR_SRC_S)jeu/view.c			\
		$(DIR_SRC_S)jeu/expulse.c		\
		$(DIR_SRC_S)jeu/instr_connect.c		\
		$(DIR_SRC_S)jeu/concatene_msg_view.c	\
		$(DIR_SRC_S)client_fct.c		\
		$(DIR_SRC_S)pars_main.c			\
		$(DIR_SRC_S)pars_init_teams.c		\
		$(DIR_SRC_S)pars_option.c		\
		$(DIR_SRC_S)pars_display.c		\


SRC_C	=	$(DIR_SRC_C)main.c


SRC_CO	=	$(DIR_SRC_CO)cbuf/cbuf_io.c		\
		$(DIR_SRC_CO)cbuf/cbuf_new.c		\
		$(DIR_SRC_CO)cbuf/cbuf_debug.c		\
		$(DIR_SRC_CO)vector/vector_new.c	\
		$(DIR_SRC_CO)vector/llist_new.c		\
		$(DIR_SRC_CO)vector/llist_mod.c		\
		$(DIR_SRC_CO)vector/llist_access.c	\


SRC_INC	=	$(DIR_INC)xfunc.h		\
		$(DIR_INC)my_list.h		\
		$(DIR_INC)server.h		\
		$(DIR_INC)server_map.h		\
		$(DIR_INC)t_struct.h		\
		$(DIR_INC)t_svr_stc.h		\
		$(DIR_INC)define.h		\
		$(DIR_INC)s_cbuf.h		\
		$(DIR_INC)s_vector.h		\
		$(DIR_INC)client_fct.h		\
		$(DIR_INC)server_fct.h		\
		$(DIR_INC)server_ini.h		\


SRC_LIB	=	$(DIR_INC)libxfunc$_*.a		\
		$(DIR_INC)libmy_list_*.a	\


OBJ_S	=	$(SRC_S:.c=.o)
OBJ_C	=	$(SRC_C:.c=.o)
OBJ_CO	=	$(SRC_CO:.c=.o)


############### FLAGS

DEFINE_i386-Darwin	=
DEFINE_i386-FreeBSD	=
DEFINE_i686-Linux	=
DEFINE			=	$(DEFINE_$(TAG))

LFLAGS_i386-Darwin	=	-lxfunc_$(TAG)				\
				-lmylist_$(TAG)

LFLAGS_i386-FreeBSD	=	-lxfunc_$(TAG)				\
				 `sdl-config --cflags --libs` -lSDL

LFLAGS_i686-Linux	=	-lxfunc_$(TAG)				\
				-lmylist_$(TAG)			\
				`sdl-config --cflags --libs` -lSDL

LFLAGS			=	-L$(DIR_LIB) $(LFLAGS_$(TAG))

IFLAGS		=	-I$(DIR_INC)
CFLAGS		+=	-g3 -W -Wall -ansi -pedantic $(DEFINE) $(IFLAGS)

############### BINARIES

CC_FreeBSD	=	gcc
CC_SunOS	=	/usr/sfw/bin/gcc
CC_Linux	=	gcc
CC_Darwin	=	gcc
CC		=	$(CC_$(STAG))

RM	=	rm -f
CD	=	cd
ETAGS	=	etags
CP	=	cp
ECHO	=	echo -e

############### COLOR

END	=	\033[m
RED	=	\033[31m
GREEN	=	\033[32m
CYAN	=	\033[36m
GREY	=	\033[37m

############### OTHERS

all	:	$(NAME_C) $(NAME_S)

$(NAME_C)	:	$(OBJ_C) $(OBJ_CO)
	@$(ECHO) "$(CYAN)[LINKING]: $(NAME_C)$(END)"
	$(CC) -o $(NAME_C) $(OBJ_C) $(OBJ_CO) $(LFLAGS)
	@$(ECHO) "$(GREEN)[LINKING] - DONE$(END)"

$(NAME_S)	:	$(OBJ_S) $(OBJ_CO)
	@$(ECHO) "$(CYAN)[LINKING]: $(NAME_S)$(END)"
	$(CC) -o $(NAME_S) $(OBJ_S) $(OBJ_CO) $(LFLAGS)
	@$(ECHO) "$(GREEN)[LINKING] - DONE$(END)"

tags	:
	@$(ECHO) "$(CYAN)[TAGGING]$(END)"
	$(ETAGS) $(SRC_INC) $(SRC_S) $(SRC_CO) $(SRC_C)
	@$(ECHO) "$(GREEN)[TAGGING] - DONE$(END)"

tar	:
	@$(ECHO) "$(CYAN)[TAR]$(END)"
	tar -cf $(NAME).tar.gz		\
	 	Makefile		\
		$(SRC_INC)		\
		$(SRC_LIB)		\
		$(SRC_S)		\
		$(SRC_CO)		\
		$(SRC_C)
	@$(ECHO) "$(CYAN)[TAR] - DONE$(END)"

############### SUFFIXIES

.SUFIXIES	:	.c .o
.c.o	:
	@$(ECHO) "$(GREY)[OBJ]"
	$(CC) $(CFLAGS) -c $< -o $@
	@$(ECHO) "[OBJ] -DONE$(END)"

############### CLEAN OPTION

clean	:
	$(RM) $(OBJ_C)
	$(RM) $(OBJ_CO)
	$(RM) $(OBJ_S)

fclean	:	clean
	$(RM) $(NAME_C)
	$(RM) $(NAME_S)

cleanall:	fclean
	$(RM) $(DIR_SRC_S)*~
	$(RM) $(DIR_SRC_CO)*~
	$(RM) $(DIR_SRC_C)*~
	$(RM) $(DIR_INC)*~
	$(RM) *~
	$(RM) TAGS

re	:	fclean	all

.PHONY	:	$(NAME_C) $(NAME_S) all .c.o library clean fclean re cleanall

#EOF