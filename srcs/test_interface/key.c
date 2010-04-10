/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Mon Apr  5 00:06:03 2010 frederic1 pierronnet
*/
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	"includes/define.h"
#include	"includes/struct.h"
#include	"includes/proto.h"

void		key_func(t_game *game)
{
  if (game->event.key.keysym.sym == SDLK_LEFT)
    printf("Left rotation\n");
  else if (game->event.key.keysym.sym == SDLK_RIGHT)
    printf("Right rotation\n");
  else if (game->event.key.keysym.sym == SDLK_ESCAPE)
    exit(EXIT_SUCCESS);
}

void		exit_func()
{
  exit(EXIT_SUCCESS);
}

