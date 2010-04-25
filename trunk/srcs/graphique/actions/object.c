/*
** player.c for zappy in /u/all/pierro_a/cu/rendu/c/lemipc/screen
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

void		drop_item(t_game *game, char **av, int ac)
{
  t_player	*player;

  if (ac > 2)
    {
      player = game->player;
      while (player)
	{
	  if (player->id == atoi(&av[1][1]))
	    {
	      player->inventaire[atoi(av[2])]--;
	      game->map.t_case[player->pos.y][player->pos.x].obj[atoi(av[2])]++;
	    }
	  player = player->next_pg;
	}
    }
}

void		take_item(t_game *game, char **av, int ac)
{
  t_player	*player;

  if (ac > 2)
    {
      player = game->player;
      while (player)
	{
	  if (player->id == atoi(&av[1][1]))
	    {
	      player->inventaire[atoi(av[2])]++;
	      game->map.t_case[player->pos.y][player->pos.x].obj[atoi(av[2])]--;
	    }
	  player = player->next_pg;
	}
    }
}
