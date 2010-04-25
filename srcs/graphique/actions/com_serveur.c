/*
** player.c for zappy in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Sat Apr 24 04:55:27 2010 Florian Chanioux
*/

#include	<stdio.h>
#include	<errno.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/select.h>

#ifdef		__APPLE__
# include	"SDL.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"
#include	"xfunc.h"

void		time_unite(t_game *game, char **av)
{
  if (av[1])
    game->info.time = atoi(av[1]);
}

void		game_over(t_game *game, char **av)
{
  game = game;
  if (av[1])
    printf("GAME OVER!\nTEAM %s WIN!", av[1]);
}

void		server_msg(t_game *game, char **av)
{
  int		i;

  game = game;
  printf("serveur msg :");
  i = 1;
  while(av[i])
    printf("%s ", av[i++]);
  printf("\n");
}
