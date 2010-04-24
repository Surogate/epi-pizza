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

void		init_map(t_game *game, char **av)
{
  int		ac;

  ac = 0;
  while (av[ac])
    ac++;
  if (ac > 2)
    if (atoi(av[1]) && atoi(av[2]))
      {
	game->info.size_w = atoi(av[1]);
	game->info.size_h = atoi(av[2]);
      }
}

void		put_to_case(t_game *game, char **av)
{
  int		ac;
  int		x;
  int		y;
  int		n_obj;

  ac = 0;
  while (av[ac])
    ac++;
  if (ac > 10)
    {
      x = atoi(av[1]);
      y = atoi(av[2]);
      n_obj = 0;
      while (n_obj < 7)
	{
	  game->map.t_case[y][x].obj[n_obj] = atoi(av[3 + n_obj]);
	  n_obj++;
	}
    }
}

void		team_name(t_game *game, char **av)
{

  game = game;
  av = av;
}

t_player	*new_player(char **av)
{
  t_player	*player;

  player = 0;
  player = xmalloc(sizeof(*player));
  if (player)
    {
      player->id = atoi(&av[1][1]);
      player->pos.x = atoi(av[2]);
      player->pos.y = atoi(av[3]);
      player->sens = atoi(av[4]);
      player->lv = atoi(av[5]);
      strcpy(player->team, av[6]);
      player->next_pc = 0;
      player->next_pg = 0;
    }
  return (player);
}

void		player_connect(t_game *game, char **av)
{
  t_player	*player;
  t_player	*temp;

  player = game->player;
  if (player)
    {
      while (player->next_pg)
	player = player->next_pg;
      player->next_pg = new_player(av);
      player = player->next_pg;
    }
  else
    {
      game->player = new_player(av);
      player = game->player;
    }
  temp = game->map.t_case[player->pos.y][player->pos.x].player;
  if (temp)
    {
      while (temp->next_pc)
	temp = temp->next_pc;
      temp->next_pc = player;
    }
  else
    game->map.t_case[player->pos.y][player->pos.x].player = player;
}
