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

void		player_expulse(t_game *game, char **av)
{
  game = game;
  printf("Le joueur %i a expulse ses petits camarades\n", atoi(av[1]));
}

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

void		incant(t_game *game, char **av, int ac)
{
  t_player	*player;
  int		i;

  if (ac > 3)
  {
    i = 0;
    player = game->player;
    while (player && av[4 + i])
    {
      if (player->id == atoi(av[4 + i]))
      {
        player->incant = 1;
        player = game->player;
        i++;
      }
      player = player->next_pg;
    }
  }
}

void		end_incant(t_game *game, char **av, int ac)
{
  t_player	*player;

  if (ac > 2)
    if (IsNumeric(av[1]) && IsNumeric(av[2]))
      if (atoi(av[1]) < game->map.w && atoi(av[2]) < game->map.h)
	{
	  player = game->player;
	  while (player)
	    {
	      if (player->pos.x == atoi(av[1]) &&
		  player->pos.y == atoi(av[2]))
		player->incant = 0;
	      player = player->next_pg;
	    }
	  if (av[3][0] == '1')
	    printf("L'incantation case %s %s a reussie\n", av[1], av[2]);
	  else
	    printf("L'incantation case %s %s a echoue\n", av[1], av[2]);
	}
}

void		player_fork(t_game *game, char **av)
{
  game = game;
  printf("Le joueur %i commence a pondre\n", atoi(av[1]));
}
