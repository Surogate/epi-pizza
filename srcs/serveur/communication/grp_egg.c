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

char		*grp_fork(t_game *game, int id_player)
{
  t_player	*player;
  t_player	ref;

  ref.player_id = id_player;
  player = my_l_find(game->player, &ref, find_player);
  return (pfk(NULL, player));
}

char		*grp_fork_end(t_player *player, t_eggs *egg)
{
  char		*msg;

  msg = enw(NULL, player->player_id, egg);
  return (msg);
}

char		*grp_egg_hatch(t_eggs *egg)
{
  char		*msg;

  msg = eht(NULL, egg->id);
  return (msg);
}

char		*grp_egg_die(t_eggs *egg)
{
  char		*msg;

  msg = edi(NULL, egg);
  return (msg);  
}
