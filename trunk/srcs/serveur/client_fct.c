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
#include <sys/time.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

static int		parse_word(char *str, t_packet *pak)
{
  char			*strstk;
  int			i;

  strstk = malloc(strlen(str) * sizeof(*strstk));
  if (strstk)
    {
      strncpy(strstk, str, strlen(str));
      pak->av[0] = strstk;
      pak->ac = 1;
      i = -1;
      while (strstk[++i] && (strstk[++i] != '\n') && (strstk[++i] == ' '));
      if (strstk[i] == ' ')
	{
	  strstk[i] = '\0';
	  pak->av[1] = strstk + i + 1;
	  pak->ac = 2;
	  while (strstk[++i] && (strstk[++i] != '\n'));
	}
      if (strstk[i] == '\n')
	strstk[i] = '\0';
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int			client_parse_instr(char *str, t_client *cli)
{
  t_packet		*pak;

  if (cli->used >= 10)
    return (EXIT_FAILURE);
  pak = cli->packet + ((cli->cons + cli->used) % 10);
  if (gettimeofday(&(pak->time), NULL) < 0)
    return (EXIT_FAILURE);
  if (parse_word(str, pak) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  pak->player_id = cli->sock;
  ++(cli->used);
  return (EXIT_SUCCESS);
}

void			free_packet(t_client *cli)
{
  free(cli->packet[cli->cons].av[0]);
  --(cli->used);
  cli->cons = (cli->cons + 1) % 10;
}
