/*
** server_eat for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Apr 16 15:18:56 2010 francois1 ancel
** Last update Fri Apr 16 18:49:52 2010 pierre1 boutbel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#if defined (__FreeBSD__)
# include <sys/select.h>
#endif

#include "define.h"
#include "my_list.h"
#include "t_struct.h"
#include "s_cbuf.h"
#include "cbuf_io.h"
#include "s_vector.h"
#include "t_packet.h"
#include "t_svr_stc.h"
#include "server_action.h"
#include "server_kick.h"
#include "server_eat.h"
#include "server_debug.h"
#include "server_graph.h"
#include "eat.h"
#include "time_fct.h"
#include "communication.h"

static int	find_eat_fct(t_packet *in, int *player_id)
{
  if ((in->type == 2) && (in->player_id == *player_id))
    return (1);
  return (0);
}

int		create_eat(t_svr_vector *vec, int player_id)
{
  t_packet	*pak;
  t_vector	*action;

  action = vec->action;
  pak = malloc(sizeof(*pak));
  if (pak)
    {
      pak->player_id = player_id;
      pak->type = 2;
      pak->duration = 126;
      timeend(&(pak->end), &(vec->slt->delay), pak->duration);
      pak->ac = 0;
      pak->ac_rep = 0;
      action->insert_sort(action, pak, sort_duration);
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int		server_eat(t_svr_vector *vec, int player_id, t_game *game)
{
  if (try_eat(game, player_id) == EXIT_FAILURE)
    {
      sock_write(player_id, "mort\n");
      printf("player %i died, eat is essential to live\n", player_id);
      gh_fct(vec, game, player_id, pdi);
      delete_eat(vec, player_id);
      server_kick(vec, player_id, game);
      return (EXIT_FAILURE);
    }
  printf("player %i eat\n", player_id);
  delete_eat(vec, player_id);
  create_eat(vec, player_id);
  return (EXIT_SUCCESS);
}

int		delete_eat(t_svr_vector *vec, int player_id)
{
  t_vector	*action;
  int		pos;

  action = vec->action;
  while ((pos = action->find_pos(action, &player_id, find_eat_fct)) >= 0)
    action->erase(action, pos, free);
  return (EXIT_SUCCESS);
}
