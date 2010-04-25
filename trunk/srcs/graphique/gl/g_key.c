/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Sat Apr 24 04:52:28 2010 Florian Chanioux
*/
#include	<sys/types.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include	<sys/select.h>

#ifdef		__APPLE__
#include	"SDL.h"
#include	<GLUT/GLUT.h>
#else
#include	<SDL/SDL.h>
#include	<GL/glu.h>
#include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

int		key_func(t_game *game)
{
  if (game->event.key.keysym.sym == SDLK_LEFT)
    game->map.rot += 5;
  else if (game->event.key.keysym.sym == SDLK_RIGHT)
    game->map.rot -= 5;
  else if (game->event.key.keysym.sym == SDLK_UP)
    game->map.z += 5;
  else if (game->event.key.keysym.sym == SDLK_DOWN)
    game->map.z -= 5;
    else if (game->event.key.keysym.sym == SDLK_c)
      game->info.crazy++;
  else if (game->event.key.keysym.sym == SDLK_ESCAPE)
    return (0);
  game->info.crazy %= 2;
  game->map.rot %= 360;
  if (game->map.z < 100)
    game->map.z = 100;
  if (game->map.z > 400)
    game->map.z = 400;
  return (1);
}

int		exit_func(t_game *game)
{
  close(game->serv.socket);
  /*
    TTF_CloseFont(game->font);
    TTF_Quit();
  */
  return (0);
}

