/*
** server_plaction for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Apr 17 10:23:48 2010 francois1 ancel
** Last update Sat Apr 24 05:49:10 2010 Florian Chanioux
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
#include "s_cbuf.h"
#include "cbuf_io.h"
#include "s_vector.h"
#include "serveur/t_packet.h"
#include "serveur/t_struct.h"
#include "serveur/t_svr_stc.h"
#include "serveur/server_action.h"
#include "serveur/server_fct.h"
#include "serveur/server_debug.h"
#include "serveur/instruction.h"
#include "serveur/client_fct.h"
#include "serveur/time_fct.h"
#include "serveur/server_hatch.h"
#include "serveur/server_graph.h"
#include "serveur/server_plaction.h"

int			find_act_fct(t_packet *in, int *player_id)
{
  if ((in->type == 0) && (in->player_id == *player_id))
    return (1);
  return (0);
}

int			create_plaction(t_svr_vector *vec, t_client *cli,
					t_select *slt)
{
  t_vector		*action;
  t_packet		*pak;

  pak = cli->packet + (cli->cons % 10);
  debug_packet(pak, "plaction cree");
  if (pak->duration)
    {
      action = vec->action;
      timeend(&(pak->end), &(slt->delay), pak->duration);
      action->insert_sort(action, pak, sort_duration);
      llist_display(action, debug_packet);
    }
  else
    free_packet(cli);
  return (EXIT_SUCCESS);
}

int			exec_plaction(t_svr_vector *vec, t_packet *pak,
				      t_game *game)
{
  t_client	*cli;

  cli = pak->player;
  treatment_intr(game, pak);
  if (pak->type < 0)
    create_hatch(vec, pak->type);
  pak->type = 0;
  return_packet(pak);
  if (pak->graph_rep)
    {
      gh_broad(vec, pak->graph_rep);
      free(pak->graph_rep);
    }
  free_packet(cli);
  delete_plaction(vec, pak->player_id);
  if (cli->used)
    create_plaction(vec, cli, vec->slt);
  return (EXIT_SUCCESS);
}

int			delete_plaction(t_svr_vector *vec, int player_id)
{
  t_vector	*action;
  int		pos;

  action = vec->action;
  while ((pos = action->find_pos(action, &player_id, find_act_fct)) >= 0)
    {
      action->delete(action, pos);
    }
  return (EXIT_SUCCESS);
}

