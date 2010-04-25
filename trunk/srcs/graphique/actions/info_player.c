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

void		player_pos(t_game *game, char **av)
{
  t_player	*player;
  int		p_id;

  p_id = atoi(av[1]);
  player = game->player;
  while (player)
    {
      if (player->id == p_id)
	{
	  player->pos.x = atoi(av[2]);
	  player->pos.y = atoi(av[3]);
	  player->sens = atoi(av[4]);
	  break;
	}
      player = player->next_pg;
    }
}

void		player_level(t_game *game, char **av)
{
  t_player	*player;

  player = game->player;
  if (player)
    {
      while (player->next_pg && player->id != atoi(av[1]))
	player = player->next_pg;
      if (player->id == atoi(av[1]))
	player->lv = atoi(av[2]);
    }
}

void		player_invent(t_game *game, char **av)
{
  t_player	*player;
  int		n_obj;

  player = game->player;
  if (player)
    {
      while (player->next_pg && player->id != atoi(av[1]))
	player = player->next_pg;
      if (player->id == atoi(av[1]))
	{
	  n_obj = 0;
	  while (n_obj < 8)
	    {
	      player->inventaire[n_obj] = atoi(av[4 + n_obj]);
	      n_obj++;
	    }
	}
    }
}

void		player_die(t_game *game, char **av, int ac)
{
  t_player	*prec;
  t_player	*cur;

  if (ac > 1)
    {
      prec = 0;
      cur = game->player;
      while (cur)
	if (cur->id == atoi(av[1]))
	  {
	    if (prec)
	      prec->next_pg = cur->next_pg;
	    else
	      game->player = cur->next_pg;
	    prec = cur->next_pg;
	    free(cur);
	    cur = prec;
	    prec = 0;
	    /*anime?*/
	  }
	else
	  {
	    prec = cur;
	    cur = cur->next_pg;
	  }
    }
}
