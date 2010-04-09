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

#include "define.h"
#include "xfunc.h"
#include "my_list.h"
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
  slt_par->fd_max = sock;
  FD_ZERO(&(slt_par->fd_read));
  return (EXIT_SUCCESS);
}

int	select_loop(int svr_sock, t_select *slt_par, t_game *game)
{
  /* init svr_par */
  /* select(svr_par) */
  /* if svr_sock ISSRED
     add player*/
  game = game;
  slt_par = slt_par;
  svr_sock = svr_sock;
  return (0);
}

int			svr_start(t_game *game)
{
  int		svr_sock;
  int		result;
  int		slt_cont;
  t_select	slt_par;

  svr_sock = socket(PF_INET, SOCK_STREAM, 0);
  if (svr_sock > 0)
    {
      result = init_svr(svr_sock, &(game->server), &slt_par);
      if (result == EXIT_SUCCESS)
	{
	  slt_cont = 1;
	  while (slt_cont > 0)
	    {
	      slt_cont = select_loop(svr_sock, &slt_par, game);
	      if (slt_cont == -1)
		result = EXIT_FAILURE;
	    }
	}
      if (close(svr_sock) < 0)
	return (EXIT_FAILURE);
      return (result);
    }
  return (EXIT_FAILURE);
}

/* 
      if ((svr_sock = init_svr(&(game->server), &slt_par)) < 0)
	{
	  fprintf(stderr, "init server error\n");
	  if (svr_sock == -1)
	    return (result);
	}
      else
	slt_cont = 1;
      while (slt_cont > 0)
	{
	  slt_cont = select_loop(svr_sock, &slt_par, game);
	  if (slt_cont < 0)
	fprintf(stderr, "select loop error");
	}
      if (!slt_cont)
	result = EXIT_SUCCESS;
 */
