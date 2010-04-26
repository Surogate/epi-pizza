/*
** concatene_msg_view.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur/jeu
**
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
**
** Started on  Wed Apr 14 13:18:55 2010 pierre1 boutbel
** Last update Sat Apr 24 05:50:01 2010 Florian Chanioux
*/

#include	<sys/types.h>
#include	<string.h>
#include	<stdio.h>
#include	<stdarg.h>

#include	"serveur/define.h"
#include	"my_list.h"
#include	"serveur/t_struct.h"
#include	"xfunc.h"

char		*ppo(char *msg, t_player *player)
{
  msg = xrealloc(msg, (xstrlen(msg) + 41) * sizeof(char));
  snprintf(msg + xstrlen(msg), 41, "ppo %i %i %i %i\n", player->player_id,
	   player->pos->x, player->pos->y, player->dir + 1);
  return (msg);
}

char		*plv(char *msg, t_player *player)
{
  msg = xrealloc(msg, (xstrlen(msg) + 19) * sizeof(char));
  snprintf(msg + xstrlen(msg), 19, "plv %i %i\n", player->player_id,
	   player->level);
  return (msg);
}

char		*pin(char *msg, t_player *player)
{
  int		i;

  i = -1;
  msg = xrealloc(msg, (xstrlen(msg) + 116) * sizeof(char));
  snprintf(msg + xstrlen(msg), 4, "plv %i %i %i", player->player_id,
	   player->pos->x, player->pos->y);
  while (++i != RESS_NUM)
    snprintf(msg + xstrlen(msg), 11, " %i", player->ress[i]);
  snprintf(msg + xstrlen(msg), 2, "\n");
  return (msg);
}
