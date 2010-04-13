/*
** server_ini for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr 12 11:24:31 2010 francois1 ancel
** Last update Mon Apr 12 11:24:31 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "define.h"
#include "xfunc.h"
#include "my_list.h"
#include "s_cbuf.h"
#include "cbuf_define.h"
#include "s_vector.h"
#include "t_struct.h"
#include "t_svr_stc.h"

int			init_svr(int sock, t_server *svr, t_select *slt_par)
{
  struct sockaddr_in	sin;

  sin.sin_family = AF_INET;
  sin.sin_port = htons(svr->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(sock, (struct sockaddr *)&sin, (socklen_t)sizeof(sin)) < 0)
    return (EXIT_FAILURE);
  if (listen(sock, 42) < 0)
    return (EXIT_FAILURE);
  slt_par->fd_max = sock + 1;
  FD_ZERO(&(slt_par->fd_read));
  FD_SET(sock, &(slt_par->fd_read));
  slt_par->timeval = NULL;
  return (EXIT_SUCCESS);
}

void			gen_counterback(t_select *slt_par, t_client *tmp,
					struct timeval *ac_time)
{
  t_packet		*pak;
  int			counterback;

  pak = tmp->packet + tmp->cons;
  counterback = pak->time.tv_sec + pak->duration - ac_time->tv_sec;
  if (!counterback)
    {
      /* execute action !!!! */
    }
  if (!slt_par->timeout.tv_sec)
    {
      slt_par->timeout.tv_sec = counterback;
      slt_par->timeval = &(slt_par->timeout);
    }
  else if (slt_par->timeout.tv_sec >= counterback)
    slt_par->timeout.tv_sec = counterback;
}

int			init_svr_par(t_select *slt_par,
				     t_vector *client, int svr_sock)
{
  t_client		*tmp;
  struct timeval	ac_time;

  gettimeofday(&ac_time, NULL);
  FD_SET(svr_sock, &(slt_par->fd_read));
  slt_par->fd_max = svr_sock;
  slt_par->timeout.tv_sec = 0;
  slt_par->timeout.tv_usec = 0;
  slt_par->timeval = NULL;
  while ((tmp = (t_client *)client->getnxts(client)) != NULL)
    {
      FD_SET(tmp->sock, &(slt_par->fd_read));
      if (tmp->sock > slt_par->fd_max)
	slt_par->fd_max = tmp->sock;
      if (tmp->used)
	gen_counterback(slt_par, tmp, &ac_time);
    }
  ++(slt_par->fd_max);
  return (EXIT_SUCCESS);
}
