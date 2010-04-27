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
#include	"serveur/communication.h"
#include	"xfunc.h"

char		*grp_get_object(t_player *player, int obj)
{
  char		*msg;

  msg = pgt(NULL, player, obj);
  msg = pin(msg, player);
  msg = bct(msg, player->pos);
  return (msg);
}

char		*grp_drop_object(t_player *player, int obj)
{
  char		*msg;

  msg = pdr(NULL, player, obj);
  msg = pin(msg, player);  
  msg = bct(msg, player->pos);
  return (msg);
}
