/*
** serveur_map.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Wed Apr  7 18:05:33 2010 Florian Chanioux
** Last update Thu Apr  8 15:48:21 2010 Florian Chanioux
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "define.h"
#include "xfunc.h"
#include "my_list.h"
#include "t_struct.h"

t_card		card[M_CARD] =
{
  {1, 0},
  {1, -1},
  {0, -1},
  {-1, -1},
  {-1, 0},
  {-1, 1},
  {0, 1},
  {1, 1}
};

static t_map 	*init_case(t_game *game, int orient, int y, int x)
{
  int xf;
  int yf;

  yf = y + card[orient].y ;
  xf = x + card[orient].x ;
  if (xf < 0)
    xf = game->server.width - 1;
  else if (xf >= game->server.width)
    xf = 0;
  if (yf < 0)
    yf = game->server.height - 1;
  else if (yf >= game->server.height)
    yf = 0;
  printf("pos o x y: %i %i %i\n%x\n", orient, xf, yf, (int)&game->map[yf][xf]);
  return (&game->map[yf][xf]);
}

void		init_map(t_game *game)
{
  int		x;
  int		y;
  int		i;

  game->map = xmalloc(sizeof(game->map) * (game->server.height));
  y = -1;
  while (++y < game->server.height)
    game->map[y] = xmalloc(sizeof(game->map[y]) * (game->server.width));
  y = -1;
  while (++y < game->server.height)
  {
    x = -1;
    while (++x < game->server.width)
    {
      i = -1;
      printf("pos_c x y: %i %i\n%x\n", x, y, (int)&game->map[y][x]);
      while (++i < M_CARD)
	game->map[y][x].card[i] = init_case(game, i, y, x);
      game->map[y][x].cas = NULL;
    }
  }
}

void		test_aff_map(t_game *game)
{
  int		x;
  int		y;

  y = -1;
  while (++y < game->server.height)
  {
    x = -1;
    while (++x < game->server.width)
      printf("pos_c x y: %i %i\n%x\n", x, y, (int)&game->map[y][x]);
  }
}

void		test_map(t_game *game)
{
  int		i;
  int		x;
  int		y;

  y = -1;
  while (++y < game->server.height)
  {
    x = -1;
    while (++x < game->server.width)
    {
      i = -1;
      printf("pos: y=%i, x=%i\n", y, x);
      printf("case: %x\n{", (int)&game->map[y][x]);
      while (++i < M_CARD)
	printf("[%i, %x] ", i, (int)game->map[y][x].card[i]);
      printf("}\n");
    }
  }
}

void		free_map(t_game *game)
{
  int		y;

  y = 0;
  while (y < game->server.height)
  {
    free(game->map[y]);
    y++;
  }
  free(game->map);
}
