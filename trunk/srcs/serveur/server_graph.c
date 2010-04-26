/*
** server_graph for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr 19 17:41:10 2010 francois1 ancel
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
#include "serveur/server_fct.h"
#include "serveur/server_action.h"
#include "serveur/server_eat.h"
#include "serveur/server_plaction.h"
#include "serveur/server_insert_player.h"
#include "serveur/server_graph.h"
#include "serveur/communication.h"

static int	find_player(int *player_id, t_player *pla)
{
  if (pla && (pla->player_id == *player_id))
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

void		new_gh(t_svr_vector *vec, t_client *cli, t_game *game)
{
  char		*str;

  vec->client->swap(vec->client, vec->graph, vec->client->gns_pos);
  str = grp_connex_monit(game);
  sock_write(cli->sock, str);
  free(str);
}

void		gh_broad(t_svr_vector *vec, char *str)
{
  t_vector	*graph;
  t_client	*cli;

  graph = vec->graph;
  while ((cli = graph->getnxts(graph)) != NULL)
    sock_write(cli->sock, str);
}

void		gh_fct(t_svr_vector *vec, t_game *game, 
		       int player_id, char *(*fct)())
{
  char		*str;
  t_player	*pla;

  pla = my_l_find(game->player, &player_id, find_player);
  str = NULL;
  if (str && pla)
    {
      str = fct(str, pla, game);
      gh_broad(vec, str);
      free(str);
    }
}

int		graph_inst(t_client *cli, t_svr_vector *vec)
{
  char		*readed;

  if (FD_ISSET(cli->sock, &(vec->slt->fd_read)))
    {
      	if (cbuf_write(&cli->cbuf, cli->sock) == EXPIPE)
	  {
	    printf("le client graphique %i a un souci\n", cli->sock);
	    FD_CLR(cli->sock, &(vec->slt->fd_read));
	    vec->graph->erase(vec->graph, vec->graph->gns_pos, free_client);
	  }
	else if ((readed = cbuf_read(&(cli->cbuf), check_read)))
	  printf("readed : %s\n", readed);
    }
  return (EXIT_SUCCESS);
}
