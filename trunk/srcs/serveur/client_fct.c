/*
** client_fct.c for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Apr 10 11:35:02 2010 francois1 ancel
** Last update Sat Apr 10 11:35:02 2010 francois1 ancel
*/

#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "my_list.h"
#include "s_vector.h"
#include "s_cbuf.h"
#include "t_svr_stc.h"

t_client		*new_client(int s)
{
  struct sockaddr_in	sin;
  int			sin_len;
  t_client		*new;

  new = malloc(sizeof(*new));
  if (new)
    {
      sin_len = sizeof(sin);
      new->sock = accept(s, (struct sockaddr *)&sin,
			 (socklen_t *)&sin_len);
      if (new->sock < 0)
	{
	  perror("accept  error");
	  free(new);
	  return (NULL);
	}
      printf("new client : %i\n", new->sock);
      cbuf_init(&(new->cbuf));
      new->used = 0;
      new->cons = 0;
    }
  return (new);
}

int			add_client(t_vector *client, t_select *slt_par, 
				   int svr_sock)
{
  t_client		*tmp;

  tmp = new_client(svr_sock);
  if (tmp == NULL)
    return (EXIT_FAILURE);
  client->push_front(client, tmp);
  if (tmp->sock > slt_par->fd_max)
    slt_par->fd_max = tmp->sock;
  return (EXIT_SUCCESS);
}
