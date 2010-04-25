/*
** server_ini for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr 12 11:24:31 2010 francois1 ancel
** Last update Sat Apr 24 05:49:10 2010 Florian Chanioux
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>

#if defined (__FreeBSD__)
# include <sys/select.h>
#endif

#include "serveur/define.h"
#include "xfunc.h"
#include "my_list.h"
#include "s_cbuf.h"
#include "cbuf_define.h"
#include "s_vector.h"
#include "serveur/t_packet.h"
#include "serveur/t_struct.h"
#include "serveur/t_svr_stc.h"
#include "serveur/server_debug.h"
#include "serveur/time_fct.h"

int			init_svr(int sock, t_server *svr, t_select *slt_par)
{
  struct sockaddr_in	sin;
  int			value;

  value = 1;
  sin.sin_family = AF_INET;
  sin.sin_port = htons(svr->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(value)) < 0)
    return (EXIT_FAILURE);
  if (bind(sock, (struct sockaddr *)&sin, (socklen_t)sizeof(sin)) < 0)
    return (EXIT_FAILURE);
  if (listen(sock, 42) < 0)
    return (EXIT_FAILURE);
  slt_par->fd_max = sock + 1;
  FD_ZERO(&(slt_par->fd_read));
  FD_SET(sock, &(slt_par->fd_read));
  slt_par->time = NULL;
  gen_delay(&(slt_par->delay), svr->delay);
  return (EXIT_SUCCESS);
}

int			init_svr_par(t_select *slt_par,
				     t_svr_vector *vec, int svr_sock)
{
  t_client		*tmp;

  FD_SET(svr_sock, &(slt_par->fd_read));
  slt_par->fd_max = svr_sock;
  while ((tmp = (t_client *)vec->client->getnxts(vec->client)) != NULL)
    {
      FD_SET(tmp->sock, &(slt_par->fd_read));
      if (tmp->sock > slt_par->fd_max)
	slt_par->fd_max = tmp->sock;
    }
  while ((tmp = (t_client *)vec->graph->getnxts(vec->graph)) != NULL)
    {
      FD_SET(tmp->sock, &(slt_par->fd_read));
      if (tmp->sock > (slt_par->fd_max))
	slt_par->fd_max = tmp->sock;
    }
  ++(slt_par->fd_max);
  return (EXIT_SUCCESS);
}

void			init_timeout(t_svr_vector *vec, t_select *slt)
{
  t_vector		*action;
  t_packet		*pak;
  struct timeval	ac_time;
  struct timeval	tmp;

  gettimeofday(&ac_time, NULL);
  action = vec->action;
  slt->time = NULL;
  while ((pak = action->getnxts(action)) != NULL)
    {
      if ((slt->time == NULL) && 
	  (timeminus(&(slt->timeout), &(pak->end), &ac_time) == EXIT_SUCCESS))
	{
	  timeminus(&(slt->timeout), &(pak->end), &ac_time);
	  slt->time = &(slt->timeout);
	}
      else if ((timeminus(&tmp, &(pak->end), &ac_time) == EXIT_SUCCESS) &&
	       (time_cmp(&(slt->timeout), &tmp) > 0))
	timeminus(&(slt->timeout), &(pak->end), &ac_time);
    }
  if (slt->time)
    printf("timeout\n=> sec : %i\n=>usec : %i\n", (int)slt->time->tv_sec, (int)slt->time->tv_usec);
  else
    printf("timeout unlimited\n");
}
