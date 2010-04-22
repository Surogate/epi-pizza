/*
** server_graph for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr 19 17:41:10 2010 francois1 ancel
** Last update Mon Apr 19 17:41:10 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/time.h>

#include "define.h"
#include "my_list.h"
#include "s_cbuf.h"
#include "cbuf_define.h"
#include "cbuf_io.h"
#include "s_vector.h"
#include "t_packet.h"
#include "t_struct.h"
#include "t_svr_stc.h"
#include "communication.h"

static int	find_player(int *player_id, t_player *pla)
{
  if (pla->player_id == *player_id)
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
  str = malloc(sizeof(char));
  str[0] = '\0';
  if (str && pla)
    {
      str = fct(str, pla, game);
      gh_broad(vec, str);
      free(str);
    }
}
