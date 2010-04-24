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

void		change_player_pos(t_game *game, char **av, t_pos pos, int p_id)
{
  t_player	*prec;
  t_player	*cur;
  t_case	*t_case;

  if (game->map.t_case[pos.y][pos.x].player->id == p_id)
    {
      t_case = &game->map.t_case[pos.y][pos.x];
      t_case->player = t_case->player->next_pc;
      cur = game->map.t_case[pos.y][pos.x].player;
    }
  else
    {
      prec = 0;
      cur = game->map.t_case[pos.y][pos.x].player;
      while (cur)
	{
	  if (cur->id == p_id)
	    {
	      prec->next_pc = cur->next_pc;
	      break;
	    }
	  else
	    {
	      prec = cur;
	      cur = cur->next_pc;
	    }
	}
    }
  if (game->map.t_case[atoi(av[2])][atoi(av[3])].player)
    {
      prec = game->map.t_case[atoi(av[2])][atoi(av[3])].player;
      while (prec->next_pc)
	prec = prec->next_pc;
      prec->next_pc = cur;
      prec->next_pc->sens = atoi(av[4]);
    }
  else
    {
      game->map.t_case[atoi(av[2])][atoi(av[3])].player = cur;
      game->map.t_case[atoi(av[2])][atoi(av[3])].player->sens = atoi(av[4]);
    }
}

void		player_pos(t_game *game, char **av)
{
  int		p_id;
  t_player	*player;
  t_pos		pos;

  pos.x = -1;
  pos.y = -1;
  player = game->player;
  p_id = atoi(&av[1][1]);
  while (player)
    {
      if (player->id == p_id)
	{
	  pos.x = player->pos.x;
	  pos.y = player->pos.y;
	}
      player = player->next_pg;
    }
  if (pos.x > 0 && pos.y > 0)
    change_player_pos(game, av, pos, p_id);
}

void		player_level(t_game *game, char **av)
{
  t_player	*player;

  player = game->player;
  if (player)
    {
      while (player->next_pg && player->id != atoi(&av[1][1]))
	player = player->next_pg;
      if (player->id == atoi(&av[1][1]))
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
      while (player->next_pg && player->id != atoi(&av[1][1]))
	player = player->next_pg;
      if (player->id == atoi(&av[1][1]))
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

void		player_die(t_game *game, char **av)
{
  game = game;
  av = av;
}
