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
#include	<stdlib.h>

#include	"serveur/define.h"
#include	"my_list.h"
#include	"serveur/t_struct.h"
#include	"serveur/communication.h"
#include	"xfunc.h"

static int	find_player(t_player *ref, t_player *data)
{
  if (data && (ref->player_id == data->player_id))
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

char		*grp_player_die(int player_id)
{
  t_player	ref;

  ref.player_id = player_id;
  return (pdi(NULL, &ref));
}

char		*grp_party_end(int winner)
{
  return (seg(NULL, winner));
}

char		*grp_connex_player(t_game *game, int player_id)
{
  t_player	ref;
  t_player	*player;

  ref.player_id = player_id;
  player = my_l_find(game->player, &ref, find_player);
  return (pnw(NULL, player, game));
}
