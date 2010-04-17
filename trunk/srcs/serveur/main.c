/*
** main for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr  5 18:15:36 2010 francois1 ancel
** Last update Sat Apr 17 15:03:26 2010 pierre1 boutbel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>

#if defined (__FreeBSD__)
# include <sys/select.h>
#endif

#include "define.h"
#include "my_list.h"
#include "s_vector.h"
#include "s_cbuf.h"
#include "t_struct.h"
#include "t_packet.h"
#include "t_svr_stc.h"
#include "server.h"
#include "server_map.h"
#include "server_stt.h"
#include "pars_main.h"

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

  check(ac, av, &(game.server));
  init_map(&game);
  game.player = my_l_init();
  game.eggs = my_l_init();
  game.state = -1;
  return (&game);
}

int		power_up(void *data)
{
  t_player	*pl;

  pl = (t_player*)data;
  pl->level = 8;
}

int main(int ac, char **av)
{
  t_game	*game;
  t_map	*cas;

  game = init_game(ac, av);
  if (game->server.debug)
  {
    test_aff_map(game);
    test_map(game);
    cas = &(game->map[0][0]);
    pathfinding(cas);
    test_pathfinding_map(game);
    reset_pathfinding(game);
    test_pathfinding_map(game);

    /*
    init_player(game, 1594, 1);
    init_player(game, 11594, 1);
    init_player(game, 31594, 1);
    init_player(game, 152394, 1);
    init_player(game, 5954, 1);
    init_player(game, 2159314, 1);
    printf("Il y a %i joueurs\n", my_l_size(game->player));
    rm_player(game, 1594);
    printf("Il y a %i joueurs\n", my_l_size(game->player));
    */

    printf("server port : %i\n", game->server.port);
  }
  if (svr_start(&(game->server)) == EXIT_FAILURE)
    perror("svr start error");
  free_map(game);
  return (EXIT_SUCCESS);
}
