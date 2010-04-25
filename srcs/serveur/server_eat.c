/*
** server_eat for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Apr 16 15:18:56 2010 francois1 ancel
** Last update Sat Apr 24 05:49:11 2010 Florian Chanioux
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#if defined (__FreeBSD__)
# include <sys/select.h>
#endif

#include "serveur/define.h"
#include "my_list.h"
#include "serveur/t_struct.h"
#include "s_cbuf.h"
#include "cbuf_io.h"
#include "s_vector.h"
#include "serveur/t_packet.h"
#include "serveur/t_svr_stc.h"
#include "serveur/server_action.h"
#include "serveur/server_kick.h"
#include "serveur/server_eat.h"
#include "serveur/server_debug.h"
#include "serveur/server_graph.h"
#include "serveur/eat.h"
#include "serveur/time_fct.h"
#include "serveur/communication.h"

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

int		server_eat(t_svr_vector *vec, t_packet *pak, t_game *game)
{
  if (try_eat(game, pak->player_id) == EXIT_FAILURE)
    {
      sock_write(pak->player_id, "mort\n");
      printf("player %i died, eat is essential to live\n", pak->player_id);
      gh_fct(vec, game, pak->player_id, pdi);
      delete_eat(vec, pak->player_id);
      server_kick(vec, pak, game);
      return (EXIT_FAILURE);
    }
  printf("player %i eat\n", pak->player_id);
  delete_eat(vec, pak->player_id);
  create_eat(vec, pak->player_id);
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
