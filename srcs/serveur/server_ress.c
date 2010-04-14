/*
** server_ress.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Wed Apr 14 16:37:56 2010 pierre1 boutbel
** Last update Wed Apr 14 17:20:27 2010 pierre1 boutbel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<time.h>

#include	"define.h"
#include	"xfunc.h"
#include	"my_list.h"
#include	"t_struct.h"

static t_map	*find_case(t_game *game)
{
  static int	seed = 0;
  int		x;
  int		y;

  srandom(time(NULL) + seed);
  seed = random();
  x = random() % game->server.width;
  y = random() % game->server.height;

  /*S'assurer que l'on a bien y x pour la map*/

  return (&(game->map[y][x]));
}

void		generate_ress(t_game *game)
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
