/*
** server_born.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Fri Apr 16 09:31:52 2010 pierre1 boutbel
** Last update Fri Apr 16 09:50:19 2010 pierre1 boutbel
*/

#include	<stdio.h>

#include	"define.h"
#include	"my_list.h"
#include	"t_struct.h"

static int	find_player(void *ref, t_player *player)
{
  if (ref == (t_player *)player->team && player->player_id < 0)
    return (1);
  return (0);
}

void		player_born(t_game *game, int id_player, int team)
{
  t_player	*pl;

  if (game->player == NULL)
    init_player(game, id_player, team);
  else
    {
      pl = my_l_find(game->player, team, find_player);
      if (pl == NULL)
	init_player(game, id_player, team);
      else
	pl->player_id = id_player;
    }
}
