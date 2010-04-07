/*
** main for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr  5 18:15:36 2010 francois1 ancel
** Last update Wed Apr  7 19:37:26 2010 Florian Chanioux
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "define.h"
#include "my_list.h"
#include "t_struct.h"
#include "serveur.h"

void		init_server(t_server *server)
{
  server->port = 0;
  server->height = 10;
  server->width = 10;
  server->teamname = NULL;
  server->nb_client = 0 ;
  server->delay = 0;
}

t_game		*init_game()
{
  static t_game		game;

  init_server(&(game.server));
  puts("erterter");
  init_map(&game);
  puts("sdfsdf");
  game.player = NULL;
  game.eggs = NULL;
  return (&game);
}

int main(int ac, char **av)
{
  t_game	*game;

  game = init_game();

  test_map(game->map);

/* init map*/
  /* init server */
  /* attendre qu'il se passe quelque chose */
  /* recup la chose */
  /* conditionner & envoie dans la partie */
  /* recuperer la reponse et la renvoyer */
  /* envoyer la map a l'affichage */
  /* retourner a l'attente */
  printf("hello world !\n");
  return (EXIT_SUCCESS);
}
