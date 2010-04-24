/*
** server_action for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Apr 14 15:17:07 2010 francois1 ancel
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
#include "s_cbuf.h"
#include "cbuf_io.h"
#include "s_vector.h"
#include "serveur/t_packet.h"
#include "serveur/t_struct.h"
#include "serveur/t_svr_stc.h"
#include "serveur/server_kick.h"
#include "serveur/server_eat.h"
#include "serveur/server_plaction.h"
#include "serveur/server_hatch.h"
#include "serveur/server_action.h"
#include "serveur/time_fct.h"

int			sort_duration(t_packet *data, t_packet *strct)
{
  if (data->duration <= strct->duration)
    return (1);
  return (0);
}

int			player_id_find(t_client *data, int *player_id)
{
  if (data->sock == *player_id)
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

int			execute_action(t_svr_vector *vec, t_game *game)
{
  t_vector		*action;
  t_packet		*tmp;
  struct timeval	time;

  action = vec->action;
  gettimeofday(&time, NULL);
  while ((tmp = action->getnxts(action)) != NULL)
    if (time_cmp(&time, &(tmp->end)) >= 0)
      {
	if (!tmp->type)
	  exec_plaction(vec, tmp, game);
	if (tmp->type == 1)
	  server_kick(vec, tmp->player_id, game);
	if (tmp->type == 2)
	  server_eat(vec, tmp->player_id, game);
	if (tmp->type == 3)
	  server_hatch(vec, tmp, game);
      }
  return (EXIT_SUCCESS);
}
