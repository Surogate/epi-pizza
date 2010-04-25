/*
** server_kick for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Thu Apr 15 15:39:16 2010 francois1 ancel
** Last update Sat Apr 24 05:49:10 2010 Florian Chanioux
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
      pak->ac = 0;
      pak->ac_rep = 0;
      action->insert_sort(action, pak, sort_duration);
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int		server_kick(t_svr_vector *vec, t_packet *pak, t_game *game)
{
  int		pos;
  t_select	*slt_par;

  slt_par = vec->slt;
  if (pak->player_id > 0)
    {
      pos = vec->client->find_pos(vec->client, &(pak->player_id), player_id_find);
      if (pos >= 0)
	{
	  sock_write(pak->player_id, "You have been kicked\n");
	  printf("player %i ass kicked\n", pak->player_id);
	  rm_player(game, pak->player_id);
	  vec->client->erase(vec->client, pos, free_client);
	  delete_kick(vec, pak->player_id);
	  delete_eat(vec, pak->player_id);
	  delete_plaction(vec, pak->player_id);
	  FD_CLR(pak->player_id, &(slt_par->fd_read));
	  return (EXIT_SUCCESS);
	}
      fprintf(stderr, "player %i unknow\n", pak->player_id);
    }
  else
    {
      delete_kick(vec, pak->player_id);
      delete_eat(vec, pak->player_id);
      rm_player(game, pak->player_id);
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
