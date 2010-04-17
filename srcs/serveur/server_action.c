/*
** server_action for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Apr 14 15:17:07 2010 francois1 ancel
** Last update Fri Apr 16 09:30:14 2010 pierre1 boutbel
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
#include "server_kick.h"
#include "server_eat.h"
#include "server_plaction.h"
#include "server_action.h"

int			sort_duration(t_packet *data, t_packet *strct)
{
  if (data->duration <= strct->duration)
    return (1);
  return (0);
}

int			player_id_find(t_packet *data, int *player_id)
{
  if (data->player_id == *player_id)
    return (1);
  return (0);
}

void			return_packet(t_packet *pak)
{
  int		i;

  i = -1;
  while (++i < pak->ac_rep)
    sock_write(pak->response[i].id_player, pak->response[i].mess);
}

void			delete_action(t_svr_vector *vec, int type, int pos)
{
  t_vector		*action;

  action = vec->action;
  if (!type)
    action->delete(action, pos);
  else
    action->erase(action, pos, free);
}

int			execute_action(t_svr_vector *vec, t_game *game,
				       t_select *slt_par)
{
  t_vector		*action;
  t_packet		*tmp;
  struct timeval	time;

  action = vec->action;
  gettimeofday(&time, NULL);
  game = game;
  while ((tmp = action->getnxts(action)) != NULL)
    {
      if ((tmp->time.tv_sec + tmp->duration) <= time.tv_sec)
	{
	  if (!tmp->type)
	    exec_plaction(vec, tmp, game);
	  if (tmp->type == 1)
	    server_kick(vec, slt_par, tmp->player_id);
	  if (tmp->type == 2)
	    server_eat(vec, slt_par, tmp->player_id, game);
	  delete_action(vec, tmp->type, action->gns_pos);
	}
    }
  return (EXIT_SUCCESS);
}
