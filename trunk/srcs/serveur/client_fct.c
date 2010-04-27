/*
** client_fct.c for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Apr 10 11:35:02 2010 francois1 ancel
** Last update Tue Apr 27 17:47:30 2010 pierre1 boutbel
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

#include "serveur/define.h"
#include "my_list.h"
#include "s_vector.h"
#include "s_cbuf.h"
#include "cbuf_io.h"
#include "serveur/t_packet.h"
#include "serveur/t_svr_stc.h"
#include "serveur/t_struct.h"
#include "serveur/server_kick.h"
#include "serveur/instruction.h"
#include "serveur/server_debug.h"

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

static int		parse_word(t_packet *pak)
{
  int			i;

  i = 0;
  printf("str recu : %s\n", pak->av[0]);
  if ((i = treatment_duration(pak)) == -1)
    {
      printf("mauvaise instruction\n");
      free(pak->av[0]);
      pak->ac = 0;
      return (EXIT_FAILURE);
    }
  printf("nbr instruct : %i\n", i);
  if ((i == 5) || (i == 6) || (i == 8))
    {
      printf("double arg\n");
      i = 0;
      while (pak->av[0][i] && pak->av[0][i] != ' ')
	i++;
      pak->av[0][i] = '\0';
      i++;
      pak->av[1] = strdup(pak->av[0] + i);
      if (pak->av[1])
	pak->ac = 2;
    }
  return (EXIT_SUCCESS);
}

int			client_parse_instr(char *str, t_client *cli)
{
  t_packet		*pak;

  if (cli->used >= 10) 
    return (EXIT_FAILURE);
  pak = cli->packet + ((cli->cons + cli->used) % 10);
  pak->av[0] = strdup(str);
  if (pak->av[0] == NULL)
    {
      perror("strdup");
      return (EXIT_FAILURE);
    }
  pak->ac = 1;
  pak->player_id = cli->sock;
  pak->player = cli;
  if (cli->team)
    {
      if (parse_word(pak) == EXIT_SUCCESS)
	++(cli->used);
    }
  else
    ++(cli->used);
  return (fill_pak(pak, str, cli));
}

void			free_packet(t_client *cli)
{
  int			i;
  t_packet		*pak;

  pak = cli->packet + cli->cons;
  i = 0;
  while (i < pak->ac)
    free(pak->av[i++]);
  pak->ac = 0;
  if (pak->ac_rep > 0)
    {
      i = 0;
      while (i < pak->ac_rep)
	free(pak->response[i++].mess);
      pak->ac_rep = 0;
    }
  if (pak->ac_rep == 0)
    free(pak->response);
  pak->ac_rep = -1;
  pak->end.tv_sec = 0;
  pak->end.tv_usec = 0;
  if (cli->used > 0)
    cli->used = cli->used - 1;
  cli->cons = (cli->cons + 1) % 10;
}
