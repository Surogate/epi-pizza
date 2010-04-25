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
#include	"graphique/proto_actions.h"
#include	"xfunc.h"

void		eggs_drop(t_game *game, char **av)
{
  t_player	*player;
  t_egg		*new;
  t_egg		*cur;
  int		i;

  printf("Le joueur %i a termine de pondre l'oeuf %i\n",
	 atoi(av[2]), atoi(av[1]));
  cur = game->egg;
  new = xmalloc(sizeof(*new));
  if (cur != NULL)
    {
      while (cur->next != NULL)
	cur = cur->next;
      cur->next = new;
    }
  else
    game->egg = new;
  new->id = atoi(av[1]);
  player = find_player(game, atoi(av[2]));
  i = -1;
  while (player->team)
    new->team = player->team;
  new->pos = player->pos;
  new->next = NULL;
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

void		eggs_die(t_game *game, char **av, int ac)
{
  t_egg		*prec;
  t_egg		*cur;

  if (ac > 1)
    {
      prec = 0;
      cur = game->egg;
      while (cur)
	if (cur->id == atoi(av[1]))
	  {
	    if (prec)
	      prec->next = cur->next;
	    else
	      game->egg = cur->next;
	    prec = cur->next;
	    free(cur);
	    cur = prec;
	    prec = 0;
	    /*anime?*/
	  }
	else
	  {
	    prec = cur;
	    cur = cur->next;
	  }
    }
}
