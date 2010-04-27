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

char		*bct(char *msg, t_map *map)
{
  int           i;

  i = -1;
  msg = xrealloc(msg, (xstrlen(msg) + 28 + (11 * RESS_NUM)) * sizeof(char));
  snprintf(msg + xstrlen(msg), 27, "bct %i %i", map->x, map->y);
  while (++i != RESS_NUM)
    snprintf(msg + xstrlen(msg), 11, " %i", map->cas.ress[i]);
  snprintf(msg + xstrlen(msg), 2, "\n");
  return (msg);
}
