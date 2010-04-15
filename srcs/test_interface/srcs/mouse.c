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
#include	<math.h>
#include	"../includes/define.h"
#include	"../includes/struct.h"

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

void		dir_mouse(t_game *game)
{
  t_pos		temp;

  temp.x = game->mouse.move.x - game->event.button.x;
  temp.y = game->event.button.y - game->mouse.move.y;
  if (!temp.x)
    {
      game->info.pos.x += temp.y;
      game->info.pos.y += temp.y;
    }
  if (!temp.y)
    {
      game->info.pos.x += temp.x;
      game->info.pos.y -= temp.x;
    }
  if ((temp.y < 0 && temp.x < 0) ||
      (temp.y > 0 && temp.y > 0))
    game->info.pos.x += (temp.x + temp.y);
  if ((temp.y < 0 && temp.x > 0) ||
      (temp.y > 0 && temp.x < 0))
    game->info.pos.y -= temp.x;
}

void		mouse_move(t_game *game)
{
  if (game->mouse.clicked)
    {
      dir_mouse(game);
      if (game->info.pos.x < 0)
	game->info.pos.x = CASE_W * game->info.size_w + game->info.pos.x;
      if (game->info.pos.y < 0)
	game->info.pos.y = CASE_H * game->info.size_h + game->info.pos.y;
      if (game->info.pos.x >= CASE_W * game->info.size_w)
	game->info.pos.x = game->info.pos.x % (CASE_W * game->info.size_w);
      if (game->info.pos.y >= CASE_H * game->info.size_h)
	game->info.pos.y = game->info.pos.y % (CASE_H * game->info.size_h);
      game->mouse.move.x = game->event.button.x;
      game->mouse.move.y = game->event.button.y;
     }
}

void		mouse_up(t_game *game)
{
  if (game->event.button.button == SDL_BUTTON_LEFT)
    {
      printf("release at x = [%d], y = [%d]\n",
	     (int)game->info.pos.y / CASE_H,
	     (int)game->info.pos.x / CASE_W);
      game->mouse.clicked = 0;
    }
}

void		mouse_down(t_game *game)
{
  if (game->event.button.button == SDL_BUTTON_LEFT)
    {
      printf("click\n");
      game->mouse.clicked = 1;
      game->mouse.move.x = game->event.button.x;
      game->mouse.move.y = game->event.button.y;
    }
  else if (game->event.button.button == SDL_BUTTON_RIGHT)
    printf("case selected : x = [%d], y = [%d]\n",
	   (int)(game->info.pos.x + game->event.button.x) / CASE_W,
	   (int)(game->info.pos.y + (MAP_CH * CASE_H - game->event.button.y)) / CASE_H);
}
