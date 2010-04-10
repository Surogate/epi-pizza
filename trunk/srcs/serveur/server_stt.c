/*
** server_stt for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Apr  6 17:58:29 2010 francois1 ancel
** Last update Tue Apr  6 17:58:29 2010 francois1 ancel
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>

#include "define.h"
#include "xfunc.h"
#include "my_list.h"
#include "s_cbuf.h"
#include "cbuf_define.h"
#include "cbuf_io.h"
#include "s_vector.h"
#include "t_struct.h"
#include "t_svr_stc.h"
#include "client_fct.h"
#include "server_fct.h"

static int		slt_cont;

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
  return (EXIT_SUCCESS);
}

int		init_svr_par(t_select *slt_par, t_vector *client, int svr_sock)
{
  t_client	*tmp;

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

void		signal_handler()
{
  slt_cont = 0;
}

int		select_loop(int svr_sock, t_select *slt_par, t_game *game)
{
  t_vector	*client;
  int		err;

  slt_cont = 1;
  client = vector_new(NULL);
  while (slt_cont)
    {
      err = select(slt_par->fd_max, &(slt_par->fd_read), NULL, NULL, NULL);
      if (err < 0)
	{
	  if (errno == EINTR)
	    return (EXIT_SUCCESS);
	  return (EXIT_FAILURE);
	}
      if (err > 0)
	{
	  if (FD_ISSET(svr_sock, &(slt_par->fd_read)))
	    if (add_client(client, slt_par, svr_sock) == EXIT_FAILURE)
	      return (EXIT_FAILURE);
	  execute_order_66(client, slt_par, game);
	}
      init_svr_par(slt_par, client, svr_sock);
    }
  return (EXIT_SUCCESS);
}

int		svr_start(t_game *game)
{
  int		svr_sock;
  int		result;
  t_select	slt_par;

  svr_sock = socket(PF_INET, SOCK_STREAM, 0);
  if (svr_sock > 0)
    {
      signal(SIGINT, signal_handler);
      result = init_svr(svr_sock, &(game->server), &slt_par);
      if (result == EXIT_SUCCESS)
	result = select_loop(svr_sock, &slt_par, game);
      else
	fprintf(stderr, "init server error\n");
      if (close(svr_sock) < 0)
	{
	  fprintf(stderr, "close svr sock error\n");
	  return (EXIT_FAILURE);
	}
      return (result);
    }
  fprintf(stderr, "socket creation error\n");
  return (EXIT_FAILURE);
}
