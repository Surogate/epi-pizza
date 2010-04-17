##
## Makefile for  in /home/Ayden/Epitech/my_ftp
##
## Made by Florian Chanioux
## Login   <chanio_f@epitech.net>
##
## Started on  Thu Mar  4 18:50:14 2010 Florian Chanioux
## Last update Sat Apr 17 19:46:48 2010 Florian Chanioux
##

STAG		= $(shell uname -s)
STAG		!= uname -s
MTAG		= $(shell uname -m)
MTAG		!= uname -m

TAG		= $(MTAG)-$(STAG)


############### PROJECT ###############

NAME		= zappy


############### DIRECTORIES ###############

DIR_SRC		= ./srcs/
DIR_INC		= ./inc/
DIR_LIB		= ./lib/


############### FILES ###############

SRC		= \
		$(DIR_SRC)main.c		\
		$(DIR_SRC)xsdl.c		\
		$(DIR_SRC)key.c			\
		$(DIR_SRC)init.c		\
		$(DIR_SRC)initgl.c		\
		$(DIR_SRC)mainloop.c		\
		$(DIR_SRC)camera.c		\
		$(DIR_SRC)interaction.c		\
		$(DIR_SRC)mouse.c		\
		$(DIR_SRC)draw_map.c		\
		$(DIR_SRC)draw_mob.c		\
		$(DIR_SRC)draw_gl.c		\
		$(DIR_SRC)test_opengl.c


SRC_INC		= \
		$(DIR_INC)/proto.h		\
		$(DIR_INC)/define.h		\
		$(DIR_INC)/struct.h


SRC_LIB		= \
		$(DIR_INC)libxfunc$_*.a		\
		$(DIR_INC)libmy_list_*.a		\


OBJ		= $(SRC:.c=.o)


############### FLAGS ###############
#########  DEFINES

DEFINE_i386-Darwin	=

DEFINE_i386-FreeBSD	= 

DEFINE_i686-Linux	= 

DEFINE			= $(DEFINE_$(TAG))


#########  INCLUDES

IFLAGS_i386-Darwin	= \
		-I$(HOME)/Library/Frameworks/SDL_ttf.framework/Headers	\
		-I$(HOME)/Library/Frameworks/SDL.framework/Headers	\
		-I/Library/Frameworks/SDL_ttf.framework/Headers		\
		-I/Library/Frameworks/SDL.framework/Headers

IFLAGS_i386-FreeBSD	=

IFLAGS_i686-Linux	=

IFLAGS			= $(IFLAGS_$(TAG)) -I$(DIR_INC) 


#########  LIBRARIES

LFLAGS_i386-Darwin	= \
			-framework SDL		\
			-framework GLUT		\
			-framework OpenGL	\
			-framework SDL_ttf

LFLAGS_i386-FreeBSD	= \
			-L/usr/local/lib -Wl,-rpath,/usr/local/lib	\
			-lSDL -lpthread -lSDL_ttf

LFLAGS_i686-Linux	= \
			`sdl-config --cflags --libs` \
			-lSDL -lSDL_ttf  -lGL -lGLU -lglut

LFLAGS			= -L$(DIR_LIB) $(LFLAGS_$(TAG))


#########  COMPILE FLAGS

CFLAGS			+= -g3 -W -Wall -ansi -pedantic $(DEFINE) $(IFLAGS)


############### BINARIES ###############

CC_FreeBSD	= gcc
CC_SunOS	= /usr/sfw/bin/gcc
CC_Linux	= gcc
CC_Darwin	= gcc -arch i386
CC		= $(CC_$(STAG))

RM		= rm -f
CD		= cd
ETAGS		= etags
CP		= cp
ECHO_FreeBSD	= echo -e
ECHO_SunOS	= echo -e
ECHO_Linux	= echo -e
ECHO_Darwin	= echo
ECHO		= $(ECHO_$(STAG))


############### COLORS ###############

END	= \033[m
RED	= \033[31m
GREEN	= \033[32m
CYAN	= \033[36m
GREY	= \033[37m


############### COMMANDS ###############

all		: $(NAME)

$(NAME)		: $(OBJ)
	@$(ECHO) "$(CYAN)[LINKING]: $(NAME)$(END)"
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)
	@$(ECHO) "$(GREEN)[LINKING] - DONE$(END)"

tags		:
	@$(ECHO) "$(CYAN)[TAGGING]$(END)"
	$(ETAGS) $(SRC_INC) $(SRC)
	@$(ECHO) "$(GREEN)[TAGGING] - DONE$(END)"

tar		:
	@$(ECHO) "$(CYAN)[TAR]$(END)"
	tar -cf $(NAME).tar.gz		\
		Makefile		\
		$(SRC_INC)		\
		$(SRC_LIB)		\
		$(SRC)
	@$(ECHO) "$(CYAN)[TAR] - DONE$(END)"


############### SUFFIXIES ###############

.SUFIXIES	: .c .o
.c.o		:
	@$(ECHO) "$(GREY)[OBJ]"
	$(CC) $(CFLAGS) -c $< -o $@
	@$(ECHO) "[OBJ] -DONE$(END)"


############### CLEAN OPTION ###############

clean		:
	@$(ECHO) "$(RED)[CLEAN]"
	$(RM) $(OBJ)
	@$(ECHO) "$(GREEN)[CLEAN] -DONE$(END)"

fclean		: clean
	@$(ECHO) "$(RED)[FCLEAN]"
	$(RM) $(NAME)
	@$(ECHO) "$(GREEN)[FCLEAN] -DONE$(END)"

cleanall	:fclean
	@$(ECHO) "$(RED)[CLEANALL]"
	$(RM) $(DIR_SRC)*~
	$(RM) $(DIR_INC)*~
	$(RM) *~
	$(RM) TAGS
	@$(ECHO) "$(GREEN)[CLEANALL] -DONE$(END)"




re		:fclean	all

############### CLEAN OPTION ###############

.PHONY		:$(NAME) all .c.o library clean fclean re cleanall

#EOF
