/*
** server_ress.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Wed Apr 14 16:37:56 2010 pierre1 boutbel
** Last update Sat Apr 24 05:49:10 2010 Florian Chanioux
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<time.h>
#include	<sys/time.h>

#include	"serveur/define.h"
#include	"xfunc.h"
#include	"my_list.h"
#include	"s_vector.h"
#include	"s_cbuf.h"
#include	"serveur/t_packet.h"
#include	"serveur/t_struct.h"
#include	"serveur/t_svr_stc.h"
#include	"serveur/server_graph.h"
#include	"serveur/communication.h"

static t_map	*find_case(t_game *game)
{
  static int	seed = 0;
  int		x;
  int		y;

  srandom(time(NULL) + seed);
  seed = random();
  x = random() % game->server.width;
  y = random() % game->server.height;
  return (&(game->map[y][x]));
}

void		generate_ress(t_game *game, t_svr_vector *vec)
{
  int		nb_ress_total;
  int		nb_ress[RESS_NUM] = {NB_RESS};
  t_map		*cur_case;
  int		i;

  i = -1;
  nb_ress_total = 0;
  while (++i != RESS_NUM)
    nb_ress_total = nb_ress_total + nb_ress[i];
  i = 0;
  while (--nb_ress_total >= 0)
    {
      cur_case = find_case(game);
      cur_case->cas.ress[i]++;
      nb_ress[i]--;
      if (nb_ress[i] == 0)
	i++;
    }
}

void		generate_food(t_game *game, t_svr_vector *vec)
{
  t_map		*cur_case;
  
  cur_case = find_case(game);
  cur_case->cas.ress[0]++;
  gh_broad(vec, bct(NULL, cur_case));
}

static t_map	*find_supp_case(t_game *game, int *i)
{
  t_map		*cur_case;
  int		lim_try;
  int		y;

  y = 0;
  cur_case = find_case(game);
  lim_try = game->server.height * game->server.width * 3;
  while (cur_case->cas.ress[*i] == 0)
    {
      cur_case = find_case(game);
      if (++y == lim_try)
	{
	  *i = *i +1;
	  y = 0;
	}
    }
  return (cur_case);
}

void		supp_ress(t_game *game, t_svr_vector *vec)
{
  int		nb_ress_total;
  int		nb_ress[RESS_NUM] = {NB_RESS};
  t_map		*cur_case;
  int		i;

  i = 0;
  nb_ress_total = 0;
  while (++i != RESS_NUM)
    nb_ress_total = nb_ress_total + nb_ress[i];
  i = 1;
  while (--nb_ress_total >= 0)
    {
      cur_case = find_supp_case(game, &i);
      if (i == RESS_NUM)
	break;
      cur_case->cas.ress[i]--;
      nb_ress[i]--;
      if (nb_ress[i] == 0)
	i++;
    }
}
