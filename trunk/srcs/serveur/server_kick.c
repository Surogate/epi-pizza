/*
** server_kick for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Thu Apr 15 15:39:16 2010 francois1 ancel
** Last update Mon Apr 26 10:55:36 2010 pierre1 boutbel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>

#if defined (__FreeBSD__)
# include <sys/select.h>
#endif

#include "serveur/define.h"
#include "my_list.h"
#include "s_cbuf.h"
#include "cbuf_io.h"
#include "s_vector.h"
#include "serveur/t_packet.h"
#include "serveur/t_struct.h"
#include "serveur/t_svr_stc.h"
#include "serveur/server_action.h"
#include "serveur/server_fct.h"
#include "serveur/server_kick.h"
#include "serveur/server_eat.h"
#include "serveur/server_plaction.h"
#include "serveur/server_debug.h"
#include "serveur/time_fct.h"
#include "serveur/server_insert_player.h"
#include "serveur/server_ress.h"
#include "serveur/server_graph.h"
#include "serveur/communication.h"

int		find_kick_fct(t_packet *in, int *player_id)
{
  if ((in->type == 1) && (in->player_id == *player_id))
    return (1);
  return (0);
}

int		create_kick(t_svr_vector *vec, int player_id, int time)
{
  t_packet	*pak;
  t_vector	*action;

  action = vec->action;
  pak = malloc(sizeof(*pak));
  if (pak)
    {
      pak->player_id = player_id;
      pak->type = 1;
      gettimeofday(&(pak->end), NULL);
      pak->end.tv_sec += time;
      pak->duration = time;
      pak->ac = 0;
      pak->ac_rep = -1;
      pak->graph_rep = NULL;
      action->insert_sort(action, pak, sort_duration);
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int		server_kick(t_svr_vector *vec, t_packet *pak, t_game *game)
{
  int		pos;
  t_select	*slt_par;
  int		id;

  slt_par = vec->slt;
  id = pak->player_id;
  if (id > 0)
    {
      pos = vec->client->find_pos(vec->client, &(pak->player_id), 
				  player_id_find);
      if (pos >= 0)
	{
	  printf("player %i ass kicked\n", id);
	  gh_broad(vec, grp_player_die(game, pak->player_id));
	  rm_player(game, id);
	  supp_ress(game, vec);
	  delete_kick(vec, id);
	  delete_eat(vec, id);
	  delete_plaction(vec, id);
	  FD_CLR(id, &(slt_par->fd_read));
	  vec->client->erase(vec->client, pos, free_client);
	  return (EXIT_SUCCESS);
	}
      fprintf(stderr, "player %i unknow\n", pak->player_id);
    }
  else
    {
      delete_kick(vec, id);
      delete_eat(vec, id);
      rm_player(game, id);
      printf("l'oeuf a moisie\n");
      return (EXIT_SUCCESS);
    }
  delete_kick(vec, pak->player_id);
  return (EXIT_FAILURE);
}

void		delete_kick(t_svr_vector *vec, int player_id)
{
  t_vector	*action;
  int		pos;

  action = vec->action;
  while ((pos = action->find_pos(action, &player_id, find_kick_fct)) >= 0)
    {
      action->erase(action, pos, free);
    }
}
