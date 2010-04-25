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

void		player_expulse(t_game *game, char **av)
{
  game = game;
  printf("Le joueur %i a expulse ses petits camarades\n", atoi(av[1]));
}

/*Broadcast*/
void		player_broadcast(t_game *game, char **av)
{
  int		i;

  game = game;
  printf("player %i broadcast :", atoi(av[1]));
  i = 1;
  while(av[i])
    printf("%s ", av[i++]);
  printf("\n");
}

void		incant(t_game *game, char **av)
{
  game = game;
  av = av;
}

void		end_incant(t_game *game, char **av)
{
  if (av[3][0] == '1')
    printf("L'incantation case %s %s a reussie\n", av[1], av[2]);
  else
    printf("L'incantation case %s %s a echoue\n", av[1], av[2]);

  game = game;
}

void		player_fork(t_game *game, char **av)
{
  game = game;
  printf("Le joueur %i commence a pondre\n", atoi(av[1]));
}
