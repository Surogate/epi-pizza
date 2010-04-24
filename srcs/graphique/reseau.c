/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Sat Apr 24 04:55:27 2010 Florian Chanioux
*/
#include	<stdio.h>
#include	<errno.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<sys/select.h>

#ifdef		__APPLE__
# include	"SDL.h"
# include	"SDL_ttf.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<SDL/SDL_ttf.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"
#include	"xfunc.h"
#include	"proto_actions.h"

void		wrong_func()
{
  printf("Unkwon function!\n");
}

void		bad_param()
{
  printf("bad param!\n");
}

t_msg		msg_lst[] =
  {
    {"msz", init_map},
    {"bct", put_to_case},
    {"tna", team_name},
    {"pnw", player_connect},
    {"ppo", player_pos},
    {"plv", player_level},
    {"pin", player_invent},
    {"pex", player_expulse},
    {"pbc", player_broadcast},
    {"pic", incant},
    {"pie", end_incant},
    {"pfk", player_fork},
    {"pdr", drop_item},
    {"pgd", take_item},
    {"pdi", player_die},
    {"enw", eggs_drop},
    {"eht", eggs_ready},
    {"ebo", eggs_to_player},
    {"edi", eggs_die},
    {"sgt", time_unite},
    {"seg", game_over},
    {"smg", server_msg},
    {"suc\n", wrong_func},
    {"sbp\n", bad_param},
    {0,0}
  };

void		traitement(t_game *game, char **av)
{
  int		i;
  int		ac;

  ac = 0;
  while (av[ac])
    ac++;
  i = 0;
  while (msg_lst[i].name)
    {
      if (!strncmp(msg_lst[i].name, av[0], 3))
	msg_lst[i].func(game, av, ac);
      i++;
    }
}
