/*
** server_born.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Fri Apr 16 09:31:52 2010 pierre1 boutbel
** Last update Sun Apr 18 12:32:30 2010 pierre1 boutbel
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"define.h"
#include	"my_list.h"
#include	"t_struct.h"
#include	"server_insert_player.h"
#include	"player_debug.h"

static int	find_player(void *ref, t_player *player)
{
  if (player &&(ref == (t_player *)player->team) && (player->player_id < 0))
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

int		player_born(t_game *game, int id_player, int team)
{
  t_player	*pl;

  if (game->player == NULL)
    {
      init_player(game, id_player, team);
      return (1);
    }
  pl = my_l_find(game->player, &team, find_player);
  if (pl == NULL)
    {
      init_player(game, id_player, team);
      return (1);
    }
  pl->player_id = id_player;
  return (2);
}
