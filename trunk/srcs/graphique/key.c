/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Wed Apr 21 15:17:20 2010 Florian Chanioux
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
#include	"SDL_ttf.h"
#include	<GLUT/GLUT.h>
#else
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	<GL/glu.h>
#include	<GL/gl.h>
#endif

#include "graphique/3dsloader.h"
#include "graphique/define.h"
#include "graphique/struct.h"
#include "graphique/proto.h"

int		key_func(t_game *game)
{
  if (game->event.key.keysym.sym == SDLK_LEFT)
    printf("Left rotation\n");
  else if (game->event.key.keysym.sym == SDLK_RIGHT)
    printf("Right rotation\n");
  else if (game->event.key.keysym.sym == SDLK_UP)
    printf("UP rotation\n");
  else if (game->event.key.keysym.sym == SDLK_DOWN)
    printf("down rotation\n");
  else if (game->event.key.keysym.sym == SDLK_ESCAPE)
    return (exit_func(game));
  return (1);
}

int		exit_func(t_game *game)
{
/*   t_circle	*current; */
/*   t_circle	*next; */

/*   printf("\033[31mEXITING\033[00m\n"); */
/*   current = game->serv.circ.next; */
/*   if (current) */
/*     { */
/*       next = current->next; */
/*       free(current); */
/*     } */
/*   else */
/*     next = 0; */
/*   while (next) */
/*     { */
/*       current = next; */
/*       next = current->next; */
/*       free(current); */
/*     } */
/*     TTF_CloseFont(game->font); */
/*     TTF_Quit(); */
  return (0);
}

