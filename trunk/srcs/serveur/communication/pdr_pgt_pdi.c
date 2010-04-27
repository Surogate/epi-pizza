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

char		*pdr(char *msg, t_player *player, int ress)
{
  msg = xrealloc(msg, (xstrlen(msg) + 26) * sizeof(char));
  snprintf(msg + xstrlen(msg), 26, "pdr %i %i\n", player->player_id, 
	   ress);
  return (msg);
}

char		*pgt(char *msg, t_player *player, int ress)
{
  msg = xrealloc(msg, (xstrlen(msg) + 26) * sizeof(char));
  snprintf(msg + xstrlen(msg), 26, "pgt %i %i\n", player->player_id, 
	   ress);
  return (msg);
}

char		*pdi(char *msg, t_player *player)
{
  msg = xrealloc(msg, (xstrlen(msg) + 15) * sizeof(char));
  snprintf(msg + xstrlen(msg), 15, "pdi %i\n", player->player_id);
  return (msg);
}
