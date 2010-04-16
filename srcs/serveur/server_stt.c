/*
** server_stt for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Apr  6 17:58:29 2010 francois1 ancel
** Last update Wed Apr 14 17:24:33 2010 pierre1 boutbel
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

#if defined (__FreeBSD__)
# include <sys/select.h>
#endif

#include "define.h"
#include "xfunc.h"
#include "my_list.h"
#include "s_cbuf.h"
#include "cbuf_define.h"
#include "cbuf_io.h"
#include "s_vector.h"
#include "t_struct.h"
#include "t_packet.h"
#include "t_svr_stc.h"
#include "server_fct.h"
#include "server_ini.h"
#include "client_fct.h"
#include "server_action.h"

static int		slt_cont;

void		signal_handler()
{
  slt_cont = 0;
}

static void		init_vector(t_svr_vector *vec)
{
  vec->client = vector_new(NULL);
  vec->action = vector_new(NULL);
}

static void	end_loop(t_svr_vector *vec, t_select *slt_par, 
			 t_game *game, int svr_sock)
{
  printf("######  select loop #######\n");
  execute_action(vec, game, slt_par);
  init_svr_par(slt_par, vec->client, svr_sock);
  init_timeout(vec, slt_par);
}

int		select_loop(int svr_sock, t_select *slt_par, t_game *game)
{
  t_svr_vector	vec;
  int		err;

  slt_cont = 1;
  init_vector(&vec);
  while (slt_cont)
    {
      err = select(slt_par->fd_max, &(slt_par->fd_read), NULL, NULL, slt_par->time);
      if (err < 0)
	{
	  if (errno == EINTR)
	    return (EXIT_SUCCESS);
	  return (EXIT_FAILURE);
	}
      if (err > 0)
	{
	  if (FD_ISSET(svr_sock, &(slt_par->fd_read)))
	    if (add_client(&vec, slt_par, svr_sock) == EXIT_FAILURE)
	      fprintf(stderr, "add client error");
	  fetch_instr(&vec, slt_par, game);
	}
      end_loop(&vec, slt_par, game, svr_sock);
    }
  close_client(vec.client, slt_par);
  return (EXIT_SUCCESS);}

int		svr_start(t_game *game)
{
  int		svr_sock;
  int		result;
  t_select	slt_par;

  /*svr_sock = socket(PF_INET, SOCK_STREAM, 0);*/
  svr_sock = socket(AF_INET, SOCK_STREAM, 0);

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
