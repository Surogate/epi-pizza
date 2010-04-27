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

static char	*print_player(char *msg, t_game *game)
{
  t_player	*player;
  t_list	*list;

  list = game->player;
  while (list->data != NULL)
    {
      player = (t_player *)list->data;
      msg = pnw(msg, player, game);
      list = list->next;
    }
  return (msg);
}

static char	*print_eggs(char *msg, t_game *game)
{
  t_list	*list;
  t_eggs	*egg;

  list = game->eggs;
  while (list->data != NULL)
    {
      egg = (t_eggs *)list->data;
      msg = enw(msg, egg->father, egg);
      list = list->next;
    }
  return (msg);
}

char		*grp_connex_monit(t_game *game)
{
  int		x;
  int		y;
  char		*msg;

  msg = NULL;
  msg = msz(msg, game);
  y = -1;
  while (++y < game->server.height)
    {
      x = -1;
      while (++x < game->server.width)
	msg = bct(msg, game->map[y] + x);
    }
  msg = tna(msg, game);
  msg = print_player(msg, game);
  msg = print_eggs(msg, game);
  return (msg);
}

char		*grp_connex_zombie(t_game *game, t_player *player, t_eggs *egg)
{
  char		*msg;

  msg = NULL;
  msg = ebo(msg, egg);
  msg = pnw(msg, player, game);
  return (msg);
}
