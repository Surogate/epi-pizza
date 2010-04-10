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

SDL_Surface	*load_window()
{
  SDL_Surface	*screen;

  xSDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
  screen = xSDL_SetVideoMode(CASE_W * MAP_CW, CASE_H * MAP_CH,
			    WIN_COLOR, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("LemIPC", NULL);
  return (screen);
}

void		init_game(t_game *game)
{
  game->mouse.clicked = 0;
  game->pos.x = 0;
  game->pos.y = 0;
  game->screen = load_window();
}
