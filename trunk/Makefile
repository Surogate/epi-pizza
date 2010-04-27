##
## Makefile for  in /home/Ayden/Epitech/my_ftp
##
## Made by Florian Chanioux
## Login   <chanio_f@epitech.net>
##
## Started on  Thu Mar  4 18:50:14 2010 Florian Chanioux
## Last update Sat Apr 24 13:23:40 2010 Florian Chanioux
##

STAG		= $(shell uname -s)
STAG		!= uname -s
MTAG		= $(shell uname -m)
MTAG		!= uname -m

TAG		= $(MTAG)-$(STAG)

############### PROJECT

NAME		= zappi
NAME_S		= serveur
NAME_GR		= graphique


############### DIRECTORIES

DIR_SRC		= ./srcs/
DIR_INC		= ./inc/
DIR_LIB		= ./lib/

############### FILES

DIR_SRC_S	= $(DIR_SRC)serveur/
DIR_SRC_CO	= $(DIR_SRC)commun/
DIR_SRC_GR	= $(DIR_SRC)graphique/

DIR_INC_S	= $(DIR_INC)serveur/
DIR_INC_GR	= $(DIR_INC)graphique/

SRC_S		= \
		$(DIR_SRC_S)main.c			\
		$(DIR_SRC_S)server_map.c		\
		$(DIR_SRC_S)server_free.c		\
		$(DIR_SRC_S)test_map.c			\
		$(DIR_SRC_S)server_stt.c		\
		$(DIR_SRC_S)server_fct.c		\
		$(DIR_SRC_S)server_action.c		\
		$(DIR_SRC_S)server_kick.c		\
		$(DIR_SRC_S)server_eat.c		\
		$(DIR_SRC_S)server_plaction.c		\
		$(DIR_SRC_S)server_graph.c		\
		$(DIR_SRC_S)server_hatch.c		\
		$(DIR_SRC_S)server_insert_player.c	\
		$(DIR_SRC_S)server_ini.c		\
		$(DIR_SRC_S)server_debug.c		\
		$(DIR_SRC_S)server_ress.c		\
		$(DIR_SRC_S)server_born.c		\
		$(DIR_SRC_S)server_ending.c		\
		$(DIR_SRC_S)time_fct.c			\
		$(DIR_SRC_S)response.c			\
		$(DIR_SRC_S)player_debug.c		\
		$(DIR_SRC_S)instruction.c		\
		$(DIR_SRC_S)jeu/hatch.c			\
		$(DIR_SRC_S)jeu/incant.c		\
		$(DIR_SRC_S)jeu/instr_broadcast.c	\
		$(DIR_SRC_S)jeu/invent.c		\
		$(DIR_SRC_S)jeu/move.c			\
		$(DIR_SRC_S)jeu/connect_nbr.c		\
		$(DIR_SRC_S)jeu/view.c			\
		$(DIR_SRC_S)jeu/expulse.c		\
		$(DIR_SRC_S)jeu/instr_connect.c		\
		$(DIR_SRC_S)jeu/concatene_msg_view.c	\
		$(DIR_SRC_S)jeu/eat.c			\
		$(DIR_SRC_S)communication/grp_action.c	\
		$(DIR_SRC_S)communication/grp_connex.c	\
		$(DIR_SRC_S)communication/grp_egg.c	\
		$(DIR_SRC_S)communication/grp_ending.c	\
		$(DIR_SRC_S)communication/grp_move.c	\
		$(DIR_SRC_S)communication/grp_object.c	\
		$(DIR_SRC_S)communication/bct.c		\
		$(DIR_SRC_S)communication/msz_tna_pnw.c	\
		$(DIR_SRC_S)communication/pdr_pgt_pdi.c	\
		$(DIR_SRC_S)communication/pex_pbc_pix.c	\
		$(DIR_SRC_S)communication/ppo_plv_pin.c	\
		$(DIR_SRC_S)communication/pfk_ex.c	\
		$(DIR_SRC_S)communication/sx.c		\
		$(DIR_SRC_S)client_fct.c		\
		$(DIR_SRC_S)pars_main.c			\
		$(DIR_SRC_S)pars_init_teams.c		\
		$(DIR_SRC_S)pars_option.c		\
		$(DIR_SRC_S)pars_display.c		\
		$(DIR_SRC_S)pathfinding.c


SRC_INC_S	= \
		$(DIR_INC_S)client_fct.h		\
		$(DIR_INC_S)instruction.h		\
		$(DIR_INC_S)player_debug.h		\
		$(DIR_INC_S)server_ending.h		\
		$(DIR_INC_S)server_insert_player.h	\
		$(DIR_INC_S)t_game_stc.h		\
		$(DIR_INC_S)communication.h		\
		$(DIR_INC_S)pars_define.h		\
		$(DIR_INC_S)response.h			\
		$(DIR_INC_S)server_fct.h		\
		$(DIR_INC_S)server_kick.h		\
		$(DIR_INC_S)time_fct.h			\
		$(DIR_INC_S)count_player.h		\
		$(DIR_INC_S)pars_display.h		\
		$(DIR_INC_S)server_action.h		\
		$(DIR_INC_S)server_graph.h		\
		$(DIR_INC_S)server_map.h		\
		$(DIR_INC_S)t_packet.h			\
		$(DIR_INC_S)define.h			\
		$(DIR_INC_S)pars_init_teams.h		\
		$(DIR_INC_S)server_born.h		\
		$(DIR_INC_S)server.h			\
		$(DIR_INC_S)server_plaction.h		\
		$(DIR_INC_S)t_struct.h			\
		$(DIR_INC_S)eat.h			\
		$(DIR_INC_S)pars_main.h			\
		$(DIR_INC_S)server_debug.h		\
		$(DIR_INC_S)server_hatch.h		\
		$(DIR_INC_S)server_ress.h		\
		$(DIR_INC_S)t_svr_stc.h			\
		$(DIR_INC_S)game_cmd.h			\
		$(DIR_INC_S)pars_option.h		\
		$(DIR_INC_S)server_eat.h		\
		$(DIR_INC_S)server_ini.h		\
		$(DIR_INC_S)server_stt.h


SRC_CO		= \
		$(DIR_SRC_CO)cbuf/cbuf_io.c		\
		$(DIR_SRC_CO)cbuf/cbuf_new.c		\
		$(DIR_SRC_CO)cbuf/cbuf_debug.c		\
		$(DIR_SRC_CO)vector/vector_new.c	\
		$(DIR_SRC_CO)vector/llist_new.c		\
		$(DIR_SRC_CO)vector/llist_mod.c		\
		$(DIR_SRC_CO)vector/llist_access.c	\
		$(DIR_SRC_CO)vector/llist_sort.c	\
		$(DIR_SRC_CO)vector/llist_swap.c	\
		$(DIR_SRC_CO)vector/llist_del.c	\
		$(DIR_SRC_CO)count_player.c		\

SRC_INC_CO	= \
		$(DIR_INC)xfunc.h			\
		$(DIR_INC)my_list.h			\
		$(DIR_INC)cbuf_io.h			\
		$(DIR_INC)cbuf_define.h			\
		$(DIR_INC)s_cbuf.h			\
		$(DIR_INC)s_vector.h			\

SRC_GR		= \
		$(DIR_SRC_GR)main.c			\
		$(DIR_SRC_GR)init.c			\
		$(DIR_SRC_GR)mainloop.c			\
		$(DIR_SRC_GR)gl/g_load_image.c		\
		$(DIR_SRC_GR)gl/g_loadtexture.c		\
		$(DIR_SRC_GR)gl/g_3dsloader.c		\
		$(DIR_SRC_GR)gl/g_xsdl.c		\
		$(DIR_SRC_GR)gl/g_key.c			\
		$(DIR_SRC_GR)gl/g_init_load.c		\
		$(DIR_SRC_GR)gl/g_initgl.c		\
		$(DIR_SRC_GR)gl/g_CallList.c		\
		$(DIR_SRC_GR)gl/g_load_window.c		\
		$(DIR_SRC_GR)gl/g_camera.c		\
		$(DIR_SRC_GR)gl/g_interaction.c		\
		$(DIR_SRC_GR)gl/g_mouse.c		\
		$(DIR_SRC_GR)gl/g_write_screen.c	\
		$(DIR_SRC_GR)gl/g_draw_floor.c		\
		$(DIR_SRC_GR)gl/g_draw_map.c		\
		$(DIR_SRC_GR)gl/g_draw_mob.c		\
		$(DIR_SRC_GR)gl/g_draw_picking.c	\
		$(DIR_SRC_GR)gl/g_draw_picture.c	\
		$(DIR_SRC_GR)gl/g_draw_ressource.c	\
		$(DIR_SRC_GR)gl/g_draw_egg.c		\
		$(DIR_SRC_GR)gl/show_interface.c	\
		$(DIR_SRC_GR)gl/g_draw_interfaces.c	\
		$(DIR_SRC_GR)gl/epileptique_mode.c	\
		$(DIR_SRC_GR)gl/g_draw_gl.c		\
		$(DIR_SRC_GR)gl/g_test_opengl.c		\
		$(DIR_SRC_GR)gl/g_clic_mode.c		\
		$(DIR_SRC_GR)gl/g_position.c		\
		$(DIR_SRC_GR)actions/action.c		\
		$(DIR_SRC_GR)actions/com_serveur.c	\
		$(DIR_SRC_GR)actions/common_func.c	\
		$(DIR_SRC_GR)actions/egg.c		\
		$(DIR_SRC_GR)actions/info_player.c	\
		$(DIR_SRC_GR)actions/init_info.c	\
		$(DIR_SRC_GR)actions/object.c		\
		$(DIR_SRC_GR)reseau.c			\
		$(DIR_SRC_GR)random_func.c		\
		$(DIR_SRC_GR)split.c			\
		$(DIR_SRC_GR)gl/g_key_rotate.c		\
		$(DIR_SRC_GR)message_func.c		\
		$(DIR_SRC_GR)gl/g_key_move.c		\
		$(DIR_SRC_GR)gl/g_key_affich.c		\
		$(DIR_SRC_GR)connect.c

SRC_GR_Darwin	= \
		$(DIR_SRC_GR)SDLMain.m


SRC_INC_GR	= \
		$(DIR_INC_GR)proto.h			\
		$(DIR_INC_GR)define.h			\
		$(DIR_INC_GR)struct.h			\
		$(DIR_INC_GR)3dsloader.h		\
		$(DIR_INC_GR)SDLMain.h			\
		$(DIR_INC_GR)xsdl.h

SRC_LIB		= \
		$(DIR_INC)libxfunc$_*.a			\
		$(DIR_INC)libmy_list_*.a		\


OBJ_S		= $(SRC_S:.c=.o)
OBJ_CO		= $(SRC_CO:.c=.o)
OBJ_GR		= $(SRC_GR:.c=.o)
OBJ_Darwin	= $(SRC_GR_Darwin:.m=.o)


############### FLAGS ###############
#########  DEFINES

DEFINE_i386-Darwin	=

DEFINE_i386-FreeBSD	=

DEFINE_i686-Linux	= -D_XOPEN_SOURCE=500

DEFINE			= $(DEFINE_$(TAG))


#########  INCLUDES

IFLAGS_i386-Darwin	= \
		-I$(HOME)/Library/Frameworks/cocoa.framework/Headers	\
		-I$(HOME)/Library/Frameworks/SDL.framework/Headers	\
		-I$(HOME)/Library/Frameworks/SDL_image.framework/Headers\
		-I/Library/Frameworks/cocoa.framework/Headers		\
		-I/Library/Frameworks/SDL.framework/Headers		\
		-I/Library/Frameworks/SDL_image.framework/Headers

IFLAGS_i386-FreeBSD	=

IFLAGS_i686-Linux	=

IFLAGS			= \
			$(IFLAGS_$(TAG)) 	\
			-I$(DIR_INC)		\
			-I$(DIR_INC_GR)


#########  LIBRARIES

LFLAGS_i386-Darwin_$(NAME_GR)	= \
			-lxfunc_$(TAG)			\
			-lmylist_$(TAG)			\
			-framework SDL			\
			-framework SDL_image		\
			-framework Cocoa		\
			-framework GLUT			\
			-framework OpenGL

LFLAGS_i386-Darwin	= \
			-lxfunc_$(TAG)			\
			-lmylist_$(TAG)			\

LFLAGS_i386-FreeBSD_$(NAME_GR)	= \
			-lmylist_$(TAG)			\
			-lxfunc_$(TAG)			\
			`sdl-config --cflags --libs`	\
			-lSDL_image			\
			-lGL -lGLU -lglut		\
			-lpthread

LFLAGS_i386-FreeBSD	= \
			-lmylist_$(TAG)			\
			-lxfunc_$(TAG)			\

LFLAGS_i686-Linux_$(NAME_GR)	= \
			-lmylist_$(TAG)			\
			-lxfunc_$(TAG)			\
			`sdl-config --cflags --libs`	\
			-lSDL_image			\
			-lGL -lGLU -lglut

LFLAGS_i686-Linux	= \
			-lmylist_$(TAG)			\
			-lxfunc_$(TAG)			\

LFLAGS			= -L$(DIR_LIB) $(LFLAGS_$(TAG))
LFLAGS_$(NAME_GR)	= -L$(DIR_LIB) $(LFLAGS_$(TAG)_$(NAME_GR))

#########  COMPILE FLAGS

CFLAGS			+= -O3 -W -Wall -ansi -pedantic $(DEFINE) $(IFLAGS)

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

############### COLOR ###############

END	= \033[m
RED	= \033[31m
GREEN	= \033[32m
ORANGE	= \033[33m
BLUE	= \033[34m
PINK	= \033[35m
CYAN	= \033[36m
GREY	= \033[37m

############### COMMANDS ###############

all		: $(NAME_S) $(NAME_GR)

$(NAME_S)	: $(OBJ_S) $(OBJ_CO)
	@$(ECHO) "$(CYAN)[LINKING]: $(NAME_S)$(END)"
	$(CC) -o $(NAME_S) $(OBJ_S) $(OBJ_CO) $(LFLAGS)
	@$(ECHO) "$(GREEN)[LINKING] - DONE$(END)"

$(NAME_GR)	: $(OBJ_GR) $(OBJ_$(STAG)) $(OBJ_CO)
	@$(ECHO) "$(CYAN)[LINKING]: $(NAME_GR)$(END)"
	$(CC) -o $(NAME_GR) $(OBJ_CO) $(OBJ_$(STAG)) $(OBJ_GR) $(LFLAGS_$(NAME_GR))
	@$(ECHO) "$(GREEN)[LINKING] - DONE$(END)"

tags		:
	@$(ECHO) "$(CYAN)[TAGGING]$(END)"
	$(ETAGS) -o TAGS_$(NAME_S) $(SRC_INC_S) $(SRC_CO) $(SRC_S)
	$(ETAGS) -o TAGS_$(NAME_GR) $(SRC_INC_GR) $(SRC_GR)
	@$(ECHO) "$(GREEN)[TAGGING] - DONE$(END)"

tar		:
	@$(ECHO) "$(CYAN)[TAR]$(END)"
	tar -cf $(NAME).tar.gz		\
		Makefile		\
		$(SRC_INC)		\
		$(SRC_LIB)		\
		$(SRC_S)		\
		$(SRC_CO)		\
		$(SRC_GR)
	@$(ECHO) "$(CYAN)[TAR] - DONE$(END)"

############### SUFFIXIES

.SUFIXIES	: .c .o .m
.c.o		:
	@$(ECHO) "$(ORANGE)[OBJ]$(GREY)"
	$(CC) $(CFLAGS) -c $< -o $@
	@$(ECHO) "$(ORANGE)[OBJ] -DONE$(END)"

.m.o		:
	@$(ECHO) "$(ORANGE)[OBJ]$(GREY)"
	$(CC) $(CFLAGS) -c $< -o $@
	@$(ECHO) "$(ORANGE)[OBJ] -DONE$(END)"


############### CLEAN OPTION

clean		:
	@$(ECHO) "$(RED)[CLEAN]"
	$(RM) $(OBJ_S)
	$(RM) $(OBJ_CO)
	$(RM) $(OBJ_C)
	$(RM) $(OBJ_GR)
	$(RM) $(OBJ_$(STAG))
	@$(ECHO) "$(GREEN)[CLEAN] -DONE$(END)"

fclean		: clean
	@$(ECHO) "$(RED)[FCLEAN]"
	$(RM) $(NAME_C)
	$(RM) $(NAME_S)
	$(RM) $(NAME_GR)
	@$(ECHO) "$(GREEN)[FCLEAN] -DONE$(END)"

cleanall	: fclean
	@$(ECHO) "$(RED)[CLEANALL]"
	$(RM) $(DIR_SRC_S)*~
	$(RM) $(DIR_SRC_CO)*~
	$(RM) $(DIR_SRC_C)*~
	$(RM) $(DIR_SRC_GR)*~
	$(RM) $(DIR_INC)*~
	$(RM) *~
	$(RM) TAGS*
	@$(ECHO) "$(GREEN)[CLEANALL] -DONE$(END)"


###############OTHERS OPTION ###############

re		: fclean all

.PHONY		: $(NAME_C) $(NAME_S) $(NAME_GR) all .c.o library clean fclean re cleanall

#EOF
