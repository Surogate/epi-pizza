/*
** main for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr  5 18:15:36 2010 francois1 ancel
** Last update Wed Apr  7 15:32:49 2010 Florian Chanioux
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "define.h"
#include "s_cbuf.h"
#include "xfunc.h"
#include "my_list.h"
#include "define.h"
#include "t_struct.h"

t_card		card[M_CARD] =
{
  {1, 0},
  {1, 1},
  {0, 1},
  {-1, 1},
  {-1, 0},
  {-1, -1},
  {0, -1},
  {1, -1}
};

static t_map 	*init_case(t_game *game, int orient, int x, int y)
{
  if (x + card[orient].x < 0)
    x = game->server->height;
  else if (x + card[orient].x > game->server->height)
    x = 0;
  if (y + card[orient].y < 0)
    y = game->server->width;
  else if (y + card[orient].y > game->server->width)
    y = 0;
  return (&game->map[x][y]);
}

void		init_map(t_game *game)
{
  int		x;
  int		y;
  int		i;

  game->map = xmalloc(sizeof(game->map) * (game->server->height));
  y = -1;
  while (++y < game->server->width)
    game->map[y] = xmalloc(sizeof(game->map[y]) * (game->server->width));
  y = -1;
  while (++y < game->server->width)
  {
    x = -1;
    while (++y < game->server->height)
    {
      i = -1;
      while (++i < M_CARD)
	game->map[x][y].card[i] = init_case(game->map, i, x, y);
      game->map[x][y].cas = NULL;
    }
  }
}

t_server	*init_opt()
{
  t_server	*res;

  res = xmalloc(sizeof(*res));
  res->port = 0;
  res->height = 10;
  res->width = 10;
  res->teamname = NULL;
  res->nb_client = 0 ;
  res->delay = 0;
}

int main(int ac, char **av)
{
  /* init map*/
  /* init server */
  /* attendre qu'il se passe quelque chose */
  /* recup la chose */
  /* conditionner & envoie dans la partie */
  /* recuperer la reponse et la renvoyer */
  /* envoyer la map a l'affichage */
  /* retourner a l'attente */
  printf("hello world !\n");
  return (EXIT_SUCCESS);
}
