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

t_player	*find_player(t_game *game, int pid)
{
  t_player	*cur;

  cur = game->player;
  while (cur != NULL)
    {
      if (cur->id == pid)
	return (cur);
      cur = cur->next_pg;
    }
  return (NULL);
}
