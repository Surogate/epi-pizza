/*
** server_ress.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Wed Apr 14 16:37:56 2010 pierre1 boutbel
** Last update Thu Apr 15 16:27:05 2010 pierre1 boutbel
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

void		generate_bouffe(t_game *game)
{
  t_map		*cur_case;
  
  cur_case = find_case(game);
  cur_case->cas.ress[0]++;
}

/*
  Pour detecter si une ressource n'est plus presentesur la map, 
  on calcule une limite qui, si elle est franchi, arrete la boucle et passe 
  a la ressource suivante.
  Ce n'est pas optimal, puisque cette limite est basee sur la taille de la map,
  et ne prend pas en compte toutes les cases, seulement le nombre de cases.
  Pour faire les choses "bien", il faudrait : 
  parcourir la map a la recherche des pierres,
  sauvegarder toutes les cases qui contiennent des pierres
  en selectionner une aleatoirement, ou incrementer le i si aucune case ne 
    contient la ressource.
  Mais bon... c'est "un peu" lourd a mettre en place pour pas grand chose...
*/

static t_map	*find_supp_case(t_game *game, int *i)
{
  t_map		*cur_case;
  int		lim_try;
  int		y;
  
  y = 0;
  cur_case = find_case(game);
  lim_try = game->server.height * game->server.width * 2;
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


  /*
  double	lim;
  double	prob;
  double	perc;

  perc = 100;
  prob = (double)game->server.height * (double)game->server.width;
  lim = perc / prob;
  while (lim <= 1)
    {
      lim = lim *10;
      perc = perc * 10;
    }
  */
}

void		supp_ress(t_game *game)
{
  int		nb_ress_total;
  int		nb_ress[RESS_NUM] = {NB_RESS};
  t_map		*cur_case;
  int		i;

  /*
  double	lim;
  double	perc;

  perc = 100;
  lim = perc / (double)game->server.height * (double)game->server.width;
  while (lim <= 1)
    {
      lim = lim *10;
      perc = perc * 10;
    }
  */

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
