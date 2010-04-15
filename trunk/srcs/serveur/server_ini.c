/*
** server_ini for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr 12 11:24:31 2010 francois1 ancel
** Last update Wed Apr 14 17:23:38 2010 pierre1 boutbel
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

#include "define.h"
#include "xfunc.h"
#include "my_list.h"
#include "s_cbuf.h"
#include "cbuf_define.h"
#include "s_vector.h"
#include "t_packet.h"
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
  slt_par->time = NULL;
  return (EXIT_SUCCESS);
}

int			init_svr_par(t_select *slt_par,
				     t_vector *client, int svr_sock)
{
  t_client		*tmp;
  struct timeval	ac_time;

  gettimeofday(&ac_time, NULL);
  FD_SET(svr_sock, &(slt_par->fd_read));
  slt_par->fd_max = svr_sock;
  while ((tmp = (t_client *)client->getnxts(client)) != NULL)
    {
      FD_SET(tmp->sock, &(slt_par->fd_read));
      if (tmp->sock > slt_par->fd_max)
	slt_par->fd_max = tmp->sock;
    }
  ++(slt_par->fd_max);
  return (EXIT_SUCCESS);
}

void		init_timeout(t_svr_vector *vec, t_select *slt)
{
  t_vector *action;
  t_packet *pak;

  action = vec->action;
  slt->timeout.tv_sec = 0;
  slt->timeout.tv_usec = 0;
  slt->time = NULL;
  while ((pak = action->getnxts(action)) != NULL)
    {
      if (slt->time == NULL)
	{
	  slt->timeout.tv_sec = pak->time.tv_sec;
	  slt->time = &(slt->timeout);
	}
      else if (pak->time.tv_sec <= slt->timeout.tv_sec)
	slt->timeout.tv_sec = pak->time.tv_sec;
    }
}
