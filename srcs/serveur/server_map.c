/*
** server_map.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Wed Apr  7 18:05:33 2010 Florian Chanioux
** Last update Thu Apr 15 18:01:49 2010 Florian Chanioux
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "define.h"
#include "xfunc.h"
#include "my_list.h"
#include "t_struct.h"

t_card		*tab_card()
{
  static t_card	card[M_CARD] = {
      {1, 0},
      {1, -1},
      {0, -1},
      {-1, -1},
      {-1, 0},
      {-1, 1},
      {0, 1},
      {1, 1}
    };
  return (card);
}

static void	init_case(t_case *the_case)
{
  int		alea;
  int		i;

  i = -1;
  while (++i < RESS_NUM)
  {
    alea = rand() % MAX_RESS;
    the_case->ress[i] = 0;
  }
  the_case->player = my_l_init();
}


static		t_map 	*init_card(t_game *game, int orient, int y, int x)
{
  int		xf;
  int		yf;
  t_card	*card;

  card = tab_card();
  yf = y + card[orient].y;
  xf = x + card[orient].x;
  if (xf < 0)
    xf = game->server.width - 1;
  else if (xf > game->server.width - 1)
    xf = 0;
  if (yf < 0)
    yf = game->server.height - 1;
  else if (yf > game->server.height - 1)
    yf = 0;
  return (&(game->map[yf][xf]));
}

void		init_map(t_game *game)
{
  int		x;
  int		y;
  int		i;
  t_map		*cas;

  srand(time(NULL));
  game->map = xmalloc(sizeof(*game->map) * (game->server.height));
  y = -1;
  while (++y < game->server.height)
    game->map[y] = xmalloc(sizeof(*game->map[y]) * (game->server.width));
  y = -1;
  while (++y < game->server.height)
    {
      x = -1;
      while (++x < game->server.width)
	{
	  i = -1;
	  cas = &(game->map[y][x]);
	  while (++i < M_CARD)
	    cas->card[i] = init_card(game, i, y, x);
	  init_case(&(cas->cas));
	  cas->cout = 0;
	}
    }
}

int		reload_ress(t_game *game)
{
  int		x;
  int		y;
  t_map		*cas;

   y = -1;
  while (++y < game->server.height)
    {
      x = -1;
      while (++x < game->server.width)
      {
	cas = &(game->map[y][x]);
	init_case(&(cas->cas));
      }
    }
  return (0);
}
