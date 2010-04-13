/*
** main for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr  5 18:15:36 2010 francois1 ancel
** Last update Tue Apr 13 13:30:50 2010 Florian Chanioux
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>

#include "define.h"
#include "my_list.h"
#include "s_cbuf.h"
#include "t_struct.h"
#include "t_svr_stc.h"
#include "server.h"
#include "server_map.h"
#include "server_stt.h"

void		init_server(t_server *server)
{
  server->port = 1338;
  server->height = 2;
  server->width = 2;
  server->teamname = NULL;
  server->nb_client = 1;
  server->delay = 0;
}

t_game		*init_game(int ac, char **av)
{
  static t_game		game;

  /* check(ac, av, &(game.server)); */
  init_server(&(game.server));
  init_map(&game);
  game.player = NULL;
  game.eggs = NULL;
  return (&game);
}

int main(int ac, char **av)
{
  t_game	*game;

  game = init_game(ac, av);
  /* test_aff_map(game);
     test_map(game); */
  printf("server port : %i\n", game->server.port);
  if (svr_start(&(game->server)) == EXIT_FAILURE)
    perror("svr start error");
  free_map(game);
  return (EXIT_SUCCESS);
}
