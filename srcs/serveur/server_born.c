/*
** server_born.c for zappy in /u/all/boutbe_a/cu/rendu/c/projets/epi-pizza/srcs/serveur
** 
** Made by pierre1 boutbel
** Login   <boutbe_a@epitech.net>
** 
** Started on  Fri Apr 16 09:31:52 2010 pierre1 boutbel
** Last update Mon Apr 26 10:58:53 2010 pierre1 boutbel
*/

#include	<sys/time.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"my_list.h"
#include	"s_cbuf.h"
#include	"cbuf_define.h"
#include	"cbuf_io.h"
#include	"s_vector.h"
#include	"serveur/t_packet.h"
#include	"serveur/t_svr_stc.h"
#include	"serveur/define.h"
#include	"serveur/t_struct.h"
#include	"serveur/server_insert_player.h"
#include	"serveur/player_debug.h"

static int	find_player(void *ref, t_player *player)
{
  if (player && (ref == (t_player *)player->team) && (player->player_id < 0))
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

int		player_born(t_game *game, int id_player, int team, 
			    t_svr_vector *vec)
{
  t_player	*pl;

  if (game->player == NULL)
    {
      init_player(game, id_player, team, vec);
      return (1);
    }
  pl = my_l_find(game->player, &team, find_player);
  if (pl == NULL)
    {
      init_player(game, id_player, team, vec);
      return (1);
    }
  pl->player_id = id_player;
  return (2);
}
