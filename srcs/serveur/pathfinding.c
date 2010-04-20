/*
** pathfinding.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Thu Apr 15 18:04:21 2010 Florian Chanioux
** Last update Tue Apr 20 21:46:01 2010 Florian Chanioux
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "define.h"
#include "xfunc.h"
#include "my_list.h"
#include "t_struct.h"

# define	UP	(0)
# define	DOWN	(1)
# define	LEFT	(0)
# define	RIGHT	(1)

void		reset_pathfinding(t_game *game)
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
      cas->cout = 0;
    }
  }
}

static void	pathfinding_line(int ref, t_map *casemap)
{
  int		i;
  t_map		*cmap[2];

  cmap[RIGHT] = casemap;
  cmap[LEFT] = casemap;
  i = ref;
  do
  {
    cmap[RIGHT]->cout = i;
    cmap[LEFT]->cout = i;
    i++;
    cmap[RIGHT] = cmap[RIGHT]->card[M_E];
    cmap[LEFT] = cmap[LEFT]->card[M_O];
  }
  while (cmap[RIGHT] != cmap[LEFT] &&
	 (cmap[RIGHT]->cout == 0 || cmap[RIGHT]->cout == 0));
  if (cmap[RIGHT] == cmap[LEFT])
    cmap[LEFT]->cout = i;
}

void		pathfinding(t_map *cas)
{
  t_map		*cmap[2];
  int		ref;

  ref = 0;
  cmap[UP] = cas;
  cmap[DOWN] = cas;
  pathfinding_line(ref, cmap[DOWN]);
  do
  {
    cmap[UP]->cout = ref;
    cmap[DOWN]->cout = ref;
    pathfinding_line(ref, cmap[UP]);
    pathfinding_line(ref, cmap[DOWN]);
    cmap[UP] = cmap[UP]->card[M_N];
    cmap[DOWN] = cmap[DOWN]->card[M_S];
    ++ref;
  }
  while (cmap[UP] != cmap[DOWN] &&
	 (cmap[UP]->cout == 0 || cmap[DOWN]->cout == 0));
  if (cmap[UP] == cmap[DOWN])
    pathfinding_line(ref, cmap[DOWN]);
}

