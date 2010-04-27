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
#include	<string.h>
#include	<sys/types.h>
#include	<sys/select.h>

#ifdef		__APPLE__
# include	"SDL.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"
#include	"xfunc.h"

void		init_map(t_game *game, char **av, int ac)
{
  if (ac > 2)
    if (atoi(av[1]) && atoi(av[2]))
      {
	game->map.w = atoi(av[1]);
	game->map.h = atoi(av[2]);
      }
}

void		put_to_case(t_game *game, char **av, int ac)
{
  int		x;
  int		y;
  int		n_obj;

  if (ac > 9)
    {
      x = atoi(av[1]);
      y = atoi(av[2]);
      n_obj = 0;
      while (n_obj < 7)
	{	
	  game->map.t_case[y][x].obj[n_obj][2] = atoi(av[3 + n_obj]);
	  n_obj++;
	}
    }
}

void		team_name(t_game *game, char **av)
{
  t_team	*new;
  t_team	*tim;
  int		i;

  tim = game->team;
  new = xmalloc(sizeof(t_team));
  if (tim != NULL)
    {
      i = 1;
      while (tim->next != NULL)
	{
	  tim = tim->next;
	  i++;
	}
      tim->next = new;
      new->id = i + 1;
    }
  else
    {
      game->team = new;
      new->id = 1;
    }
  if (strlen(av[1]) < 50)
    strcpy(new->name, av[1]);
  puts(new->name);
  new->next = NULL;
}

static t_player	*new_player(char **av)
{
  t_player	*player;

  player = 0;
  player = xmalloc(sizeof(*player));
  if (player)
    {
      player->id = atoi(av[1]);
      player->pos.x = atoi(av[2]);
      player->pos.y = atoi(av[3]);
      player->sens = atoi(av[4]);
      player->lv = atoi(av[5]);
      player->next_pg = 0;
    }
  return (player);
}

char		*find_team_name(t_game *game, int id)
{
  t_team	*team;

  team = game->team;
  while (team)
    {
      if (team->id == id)
	return (team->name);
      team = team->next;
    }
  return (0);
}

int		find_team_id(t_game *game, char *name)
{
  t_team	*team;

  team = game->team;
  while (team)
    {
      if (!strcmp(team->name, name))
	return (team->id);
      team = team->next;
    }
  return (0);
}

void		player_connect(t_game *game, char **av, int ac)
{
  t_player	*player;

  if (ac > 5)
    {
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
      player->team = find_team_id(game, av[6]);
    }
}
