/*
** server_kick for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Thu Apr 15 15:39:16 2010 francois1 ancel
** Last update Thu Apr 15 15:39:16 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>

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
#include "server_kick.h"

int		find_kick_fct(t_packet *in, int *player_id)
{
  if ((in->type == 1) && (in->player_id == *player_id))
    return (1);
  return (0);
}

int		create_kick(t_svr_vector *vec, int player_id)
{
  t_packet	*pak;
  t_vector	*action;

  action = vec->action;
  pak = malloc(sizeof(*pak));
  if (pak)
    {
      pak->player_id = player_id;
      pak->type = 1;
      gettimeofday(&(pak->time), NULL);
      pak->duration = 3;
      action->insert_sort(action, pak, sort_duration);
      return (EXIT_SUCCESS);
    }
  fprintf(stderr, "kick create fail\n");
  return (EXIT_FAILURE);
}

int		server_kick(t_svr_vector *vec, t_select *slt_par, int player_id)
{
  t_vector	*client;
  int		pos;

  client = vec->client;
  pos = client->find_pos(client, &player_id, player_id_find);
  if (pos >= 0)
    {
      sock_write(player_id, "You have been kicked\n");
      printf("player %i ass kicked\n", player_id);
      FD_CLR(player_id, &(slt_par->fd_read));
      client->erase(client, pos, free_client);
      delete_kick(vec, player_id);
      return (EXIT_SUCCESS);
    }
  fprintf(stderr, "player %i unknow", player_id);
  return (EXIT_FAILURE);
}

void		delete_kick(t_svr_vector *vec, int player_id)
{
  t_vector	*action;
  int		pos;

  action = vec->action;
  while ((pos = action->find_pos(action, &player_id, find_kick_fct)) >= 0)
    action->erase(action, pos, free);
}
