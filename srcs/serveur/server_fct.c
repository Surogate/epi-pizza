/*
** server_fct for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sat Apr 10 15:11:57 2010 francois1 ancel
** Last update Sat Apr 24 05:49:11 2010 Florian Chanioux
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/time.h>

#include "serveur/define.h"
#include "my_list.h"
#include "s_cbuf.h"
#include "cbuf_define.h"
#include "cbuf_io.h"
#include "s_vector.h"
#include "serveur/t_packet.h"
#include "serveur/t_struct.h"
#include "serveur/t_svr_stc.h"
#include "serveur/client_fct.h"
#include "serveur/server_kick.h"
#include "serveur/instruction.h"
#include "serveur/server_action.h"
#include "serveur/server_eat.h"
#include "serveur/server_plaction.h"
#include "serveur/server_insert_player.h"
#include "serveur/server_graph.h"
#include "serveur/communication.h"

int		check_read(char *str)
{
  int		i;

  i = 0;
  while (str[i] && str[i] != '\n')
    i++;
  if (str[i] == '\n')
    return (i);
  return (0);
}

static void	instr_catch(char *str, t_client *cli, t_game *game,
			    t_svr_vector *vec)
{
  if (client_parse_instr(str, cli) == EXIT_SUCCESS)
    {
      if (!cli->team && cli->auth < 3)
	{
	  delete_kick(vec, cli->sock);
	  ++(cli->auth);
	  cli->team = authent(game, cli->packet + cli->cons);
	  if (!cli->team)
	    create_kick(vec, cli->sock, 3);
	  else if (cli->team == 1)
	    {
	      create_eat(vec, cli->sock);
	      gh_fct(vec, game, cli->sock, pnw);
	    }
	  else if (cli->team < 0)
	    new_gh(vec, cli, game);
	  return_packet(cli->packet + cli->cons);
	  free_packet(cli);
	}
      else if (cli->used)
	create_plaction(vec, cli, vec->slt);
    }
}

void		free_client(t_client *cli)
{
  close(cli->sock);
  while (cli->used)
    free_packet(cli);
  free (cli);
}

int		close_client(t_svr_vector *vec, t_select *slt_par)
{
  t_vector	*client;
  t_vector	*action;
  t_vector	*graph;
  t_client	*tmp;

  client = vec->client;
  action = vec->action;
  graph = vec->graph;
  while ((tmp = (t_client *)client->getnxts(client)) != NULL)
    FD_CLR(tmp->sock, &(slt_par->fd_read));
  client->destruc(client, free_client);
  action->destruc(action, free);
  graph->destruc(graph, free_client);
  return (EXIT_SUCCESS);
}

int		fetch_instr(t_svr_vector *vec, t_select *slt_par,
				 t_game *game)
{
  t_client	*tmp;
  char		*readed;
  t_vector	*client;

  client = vec->client;
  while ((tmp = (t_client *)client->getnxts(client)) != NULL)
    if (FD_ISSET(tmp->sock, &(slt_par->fd_read)))
      {
	if (cbuf_write(&tmp->cbuf, tmp->sock) == EXPIPE)
	  {
	    printf("client %i timeout\n", tmp->sock);
	    FD_CLR(tmp->sock, &(slt_par->fd_read));
	    delete_eat(vec, tmp->sock);
	    delete_plaction(vec, tmp->sock);
	    delete_kick(vec, tmp->sock);
	    gh_fct(vec, game, tmp->sock, pdi);
	    if (tmp->team > 0)
 	      rm_player(game, tmp->sock);
	    client->erase(client, client->gns_pos, free_client);
	  }
	else if ((readed = cbuf_read(&(tmp->cbuf), check_read)))
	  instr_catch(readed, tmp, game, vec);
      }
  while ((tmp = (t_client *)vec->graph->getnxts(vec->graph)) != NULL)
    graph_inst(tmp, vec);
  return (EXIT_SUCCESS);
}
