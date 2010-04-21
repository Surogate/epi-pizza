/*
** server_hatch for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Apr 20 17:01:41 2010 francois1 ancel
** Last update Tue Apr 20 17:01:41 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

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
#include "server_hatch.h"

int		find_hatch_fct(t_packet *in, int *player_id)
{
  if ((in->type == 3) && (in->player_id == *player_id))
    return (1);
  return (0);
}

int	       	create_hatch(t_svr_vector *vec, int egg)
{
  t_vector     	*action;
  t_packet     	*pak;
  t_select     	*slt;

  printf("egg : %i\n", egg);
  pak = malloc(sizeof(*pak));
  if (pak)
    {
      printf("==> pak : %p\n", (void *)pak);
      slt = vec->slt;
      action = vec->action;
      timeend(&(pak->end), &(slt->delay), 600);
      pak->type = 3;
      pak->duration = 600;
      pak->player_id = egg;
      action->insert_sort(action, pak, sort_duration);
      llist_display(vec->action, debug_packet);
      printf("=>  hatch create  <=\n");
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int	       	server_hatch(t_svr_vector *vec, t_game *game, t_packet *pak)
{
  char		*str;

  printf("%i\n", pak->player_id);
  do_hatch(game, pak->player_id);
  delete_hatch(vec, pak->player_id);
  return (EXIT_SUCCESS);
}

void		delete_hatch(t_svr_vector *vec, int player_id)
{
  t_vector	*action;
  int		pos;

  action = vec->action;
  while ((pos = action->find_pos(action, &player_id, find_hatch_fct)) >= 0)
    {
      fprintf(stderr, "=>>> delete hatch at %i\n", pos);
      action->erase(action, pos, free);
    }
}
