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

char		*sgt(char *msg, t_game *game)
{
  msg = xrealloc(msg, (xstrlen(msg) + 15) * sizeof(char));
  snprintf(msg + xstrlen(msg), 15, "sgt %i\n", game->server.delay);
  return (msg);
}

char		*seg(char *msg, int win_team)
{
  msg = xrealloc(msg, (xstrlen(msg) + 15) * sizeof(char));
  snprintf(msg + xstrlen(msg), 15, "seg %i\n", win_team);
  return (msg);
}

char		*smg(char *msg, char *serv_msg)
{
  msg = xrealloc(msg, (xstrlen(msg) + strlen(serv_msg) + 5) * sizeof(char));
  snprintf(msg + xstrlen(msg), 13, "smg %s\n", serv_msg);
  return (msg);
}

char		*suc(char *msg)
{
  msg = xrealloc(msg, (xstrlen(msg) + 4) * sizeof(char));
  snprintf(msg + xstrlen(msg), 4, "suc\n");
  return (msg);
}

char		*sbp(char *msg)
{
  msg = xrealloc(msg, (xstrlen(msg) + 3) * sizeof(char));
  snprintf(msg + xstrlen(msg), 3, "bp\n");
  return (msg);
}
