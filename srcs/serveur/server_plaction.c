/*
** server_plaction for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Apr 17 10:23:48 2010 francois1 ancel
** Last update Sat Apr 17 14:28:34 2010 pierre1 boutbel
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
#include "s_cbuf.h"
#include "cbuf_io.h"
#include "s_vector.h"
#include "t_packet.h"
#include "t_struct.h"
#include "t_svr_stc.h"
#include "server_action.h"
#include "server_fct.h"
#include "server_debug.h"
#include "instruction.h"
#include "client_fct.h"
#include "time_fct.h"
#include "server_plaction.h"

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

  pak = cli->packet + cli->cons;
  if (pak->duration)
    {
      action = vec->action;
      gettimeofday(&(pak->time), NULL);
      timeend(&(pak->end), &(pak->time), &(slt->delay), pak->duration);
      action->insert_sort(action, pak, sort_duration);
      /* llist_display(vec->action, debug_packet); */
      printf("=>  action create  <=\n");
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
  printf("==> action execute\n");
  return_packet(pak);
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
      fprintf(stderr, "=>>> delete kick at %i\n", pos);
      action->delete(action, pos);
    }
  return (EXIT_SUCCESS);
}
