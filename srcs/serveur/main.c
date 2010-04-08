/*
** main for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr  5 18:15:36 2010 francois1 ancel
** Last update Thu Apr  8 15:45:39 2010 Florian Chanioux
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
  server->height = 2;
  server->width = 2;
  server->teamname = NULL;
  server->nb_client = 0 ;
  server->delay = 0;
}

t_game		*init_game()
{
  static t_game		game;

  init_server(&(game.server));
  init_map(&game);
  game.player = NULL;
  game.eggs = NULL;
  return (&game);
}

int main(int ac, char **av)
{
  t_game	*game;

  game = init_game();
  puts("phase de test");
  puts("fin de test");
  /* init map*/
  /* init server */
  /* attendre qu'il se passe quelque chose */
  /* recup la chose */
  /* conditionner & envoie dans la partie */
  /* recuperer la reponse et la renvoyer */
  /* envoyer la map a l'affichage */
  /* retourner a l'attente */
  return (EXIT_SUCCESS);
}
