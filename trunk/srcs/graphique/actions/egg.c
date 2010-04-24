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
# include	"SDL_ttf.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<SDL/SDL_ttf.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"
#include	"xfunc.h"

void		eggs_drop(t_game *game, char **av)
{
  t_egg		*new;
  t_egg		*cur;

  printf("Le joueur %i a termine de pondre l'oeuf %i\n", atoi(av[2]), 
	 atoi(av[1]));
  cur = game->egg;
  if (cur != NULL)
    while (cur->next != NULL)
      cur = cur->next;
  new = xmalloc(sizeof(t_egg));
  new->id = atoi(av[1]);
  cur->next = new;
}

void		eggs_ready(t_game *game, char **av)
{
  game = game;
  av = av;
}

void		eggs_to_player(t_game *game, char **av)
{
  game = game;
  av = av;
}

void		eggs_die(t_game *game, char **av)
{
  game = game;
  av = av;
}
