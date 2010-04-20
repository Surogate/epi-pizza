/*
** test_map.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr  9 15:22:12 2010 Florian Chanioux
** Last update Tue Apr 20 20:48:31 2010 Florian Chanioux
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "define.h"
#include "xfunc.h"
#include "my_list.h"
#include "t_struct.h"


void		test_aff_map(t_game *game)
{
  int		x;
  int		y;

  if (game->server.debug)
  {
    y = -1;
    while (++y < game->server.height)
    {
      x = -1;
      while (++x < game->server.width)
	printf("%p ", (void *)&(game->map[y][x]));
      printf("\n");
    }
  }
}

void		test_map(t_game *game)
{
  int		i;
  int		x;
  int		y;
  t_map		*cas;

  if (game->server.debug)
  {
    y = -1;
    while (++y < game->server.height)
    {
      x = -1;
      while (++x < game->server.width)
      {
	i = -1;
	printf("y: %i, x: %i case: %p\n", y, x, (void *)&(game->map[y][x]));
	cas = &(game->map[y][x]);
	while (++i < M_CARD)
	  printf("card : %i = %p\n", i, (void *)cas->card[i]);
	i = -1;
	printf("#cout : = %i\n\n", cas->cout);
	while (++i < RESS_NUM)
	  printf("##res : %i = %i\n", i, cas->cas.ress[i]);
	printf("#nb_player : = %i\n\n", my_l_size(cas->cas.player));
      }
    }
  }}

void		test_pathfinding_map(t_game *game)
{
  int		x;
  int		y;
  t_map		*cas;

  if (game->server.debug)
  {
    y = -1;
    while (++y < game->server.height)
    {
      x = -1;
      while (++x < game->server.width)
      {
	cas = &(game->map[y][x]);
	printf("%i ", cas->cout);
      }
      printf("\n");
    }
  }
}
