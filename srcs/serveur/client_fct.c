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

#include "define.h"
#include "my_list.h"
#include "s_vector.h"
#include "s_cbuf.h"
#include "cbuf_io.h"
#include "t_packet.h"
#include "t_svr_stc.h"
#include "t_struct.h"
#include "server_kick.h"
#include "instruction.h"

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
      new->team = 0;
      new->auth = 0;
    }
  return (new);
}

int			add_client(t_svr_vector *vec, t_select *slt_par,
				   int svr_sock)
{
  t_client		*tmp;
  t_vector		*client;

  client = vec->client;
  tmp = new_client(svr_sock);
  if (tmp == NULL)
    return (EXIT_FAILURE);
  client->push_front(vec->client, tmp);
  if (tmp->sock > slt_par->fd_max)
    slt_par->fd_max = tmp->sock;
  sock_write(tmp->sock, "BIENVENUE\n");
  create_kick(vec, tmp->sock, 3);
  return (EXIT_SUCCESS);
}

static int		parse_word(char *str, t_packet *pak)
{
  int			i;

  i = 0;
  if ((pak->av[0] = malloc(strlen(str) * sizeof(*(pak->av[0])))))
    {
      strncpy(pak->av[0], str, strlen(str));
      pak->ac = 1;
      while (pak->av[0][i] && (pak->av[0][i] != '\n') && (pak->av[0][i] != ' '))
	++i;
      if (pak->av[0][i] == ' ')
	{
	  pak->av[0][i] = '\0';
	  i++;
	  pak->av[1] = malloc((strlen(str) - i) * sizeof(*(pak->av[1])));
	  if (pak->av[1] && ((strlen(str) - i) > 0))
	    {
	      strncpy(pak->av[1], str + i, strlen(str + i));
	      pak->ac = 2;
	      pak->av[1][strlen(str)- i - 1] = '\0';
	    }
	}
      else
	pak->av[0][strlen(str)] = '\0';
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int			client_parse_instr(char *str, t_client *cli)
{
  t_packet		*pak;
  int			i;

  if (cli->used >= 10)
    return (EXIT_FAILURE);
  pak = cli->packet + ((cli->cons + cli->used) % 10);
  if (parse_word(str, pak) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (cli->team && (treatment_duration(pak) == EXIT_FAILURE))
    {
      i = -1;
      while (++i < pak->ac)
	free(pak->av[i]);
      return (EXIT_FAILURE);
    }
  pak->player_id = cli->sock;
  pak->player = cli;
  pak->type = 0;
  pak->ac_rep = 0;
  pak->graph_rep = NULL;
  ++(cli->used);
  return (EXIT_SUCCESS);
}

void			free_packet(t_client *cli)
{
  int			i;
  t_packet		*pak;

  pak = cli->packet + cli->cons;
  i = -1;
  while (++i < pak->ac)
    free(pak->av[i]);
  i = -1;
  while (++i < pak->ac_rep)
    free(pak->response[i].mess);
  free(pak->response);
  cli->used = cli->used - 1;
  cli->cons = (cli->cons + 1) % 10;
}
