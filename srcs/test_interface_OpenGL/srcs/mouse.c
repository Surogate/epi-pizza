/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Mon Apr 19 19:31:57 2010 Florian Chanioux
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef __APPLE__
#include "SDL.h"
#include "SDL_ttf.h"
#include <GLUT/GLUT.h>
#else
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/freeglut_std.h>
#endif

#include	"define.h"
#include	"struct.h"
# define SIZE	512


void		display_mouse(t_game *game)
{
  unsigned int	co;
  SDL_Rect	pos;
  int		x;
  int		y;

  SDL_GetMouseState(&x,&y);
  pos.x = x;
  pos.y = y;
  co = SDL_MapRGB(game->screen->format, 255, 0, 0);
  SDL_SetColorKey(game->mouse.img[game->mouse.clicked],
		  SDL_RLEACCEL | SDL_SRCCOLORKEY, co);
  SDL_BlitSurface(game->mouse.img[game->mouse.clicked],
		  NULL, game->screen, &pos);
}

int		mouse_move(t_game *game)
{
  if (game->mouse.clicked)
    {
      game->info.pos.x += game->mouse.move.x - game->event.button.x;
      game->info.pos.y -= game->mouse.move.y - game->event.button.y;
/*
      if (game->info.pos.x < 0)
	game->info.pos.x = CASE_W * game->info.size_w + game->info.pos.x;
      if (game->info.pos.y < 0)
	game->info.pos.y = CASE_H * game->info.size_h + game->info.pos.y;
*/
      game->info.pos.x = game->info.pos.x % (CASE_W * game->info.size_w);
      game->info.pos.y = game->info.pos.y % (CASE_H * game->info.size_h);
      game->mouse.move.x = game->event.button.x;
      game->mouse.move.y = game->event.button.y;
    }
  return (1);
}

int		mouse_up(t_game *game)
{
  if (game->event.button.button == SDL_BUTTON_LEFT)
    {
      printf("release at x = [%d], y = [%d].\ncase current : x=[%d], y=[%d]\n",
	     game->info.pos.x,
	     game->info.pos.y,
	     game->info.pos.x / CASE_W,
	     game->info.pos.y / CASE_H);
      game->mouse.clicked = 0;
    }
  return (1);
}

int		mouse_down(t_game *game)
{
  if (game->event.button.button == SDL_BUTTON_LEFT)
  {
    printf("click\n");
    game->mouse.clicked = 1;
    /*  SDL_WarpMouse(MAP_CW * CASE_W / 2, MAP_CH * CASE_H / 2); */
    game->mouse.move.x = game->event.button.x;
    game->mouse.move.y = game->event.button.y;
  }
  else if (game->event.button.button == SDL_BUTTON_RIGHT)
  {
    printf("case selected : x = [%d], y = [%d]\n",
	   (game->info.pos.x + game->event.button.x),
	   (game->info.pos.y + (MAP_CH * CASE_H - game->event.button.y)));
     picking_mouse(game, game->event.button.x, game->event.button.y);
  }
  return (1);
}
