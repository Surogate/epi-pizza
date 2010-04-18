/*
** eat.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur/jeu
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Wed Apr 14 13:18:39 2010 pierre1 boutbel
** Last update Sun Apr 18 12:19:52 2010 pierre1 boutbel
*/

#include	<sys/types.h>
#include	<string.h>
#include	<stdlib.h>

#include	"my_list.h"
#include	"define.h"
#include	"t_struct.h"
#include	"t_game_stc.h"
#include	"xfunc.h"
#include	"server_insert_player.h"

static int	find_player(void *ref, t_player *data)
{
  if ((int)ref == data->player_id)
    return (1);
  return (0);
}

int		try_eat(t_game *game, int id_player)
{
  t_player	*player;
  
  player = (t_player *)my_l_find(game->player, &id_player, find_player);
  if (player->ress[0] > 0)
    player->ress[0]--;
  else
    {
      rm_player(game, player->player_id);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

