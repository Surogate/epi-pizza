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
#define		PI	3.14159265

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

void		calc_move(t_game *game)
{
  t_pos		temp;
  t_pos		temp2;
  t_pos		mouse_vector;

  temp.x = game->event.button.x;
  temp.y = (CASE_H * MAP_CH) - game->event.button.y;
/*   printf("original vector : y = [%f], x = [%f]\n", temp.y - game->mouse.move.y, temp.x - game->mouse.move.x); */
  mouse_vector.y = temp.y - game->mouse.move.y;
  temp.y += mouse_vector.y;
 /*  printf("modified vector : y = [%f], x = [%f]\n", temp.y - game->mouse.move.y, temp.x - game->mouse.move.x); */
  temp2.x = (temp.x - game->mouse.move.x) * cos(-PI/4) - (temp.y - game->mouse.move.y) * sin(-PI/4) + game->mouse.move.x;
  temp2.y = (temp.x - game->mouse.move.x) * sin(-PI/4) + (temp.y - game->mouse.move.y) * cos(-PI/4) + game->mouse.move.y;
  mouse_vector.x = temp2.x - game->mouse.move.x;
  mouse_vector.y = temp2.y - game->mouse.move.y;
 /*  printf("\033[37mfinal vector y = [%f], x = [%f]\033[00m\n", mouse_vector.x, mouse_vector.y); */
   game->info.pos.x -= mouse_vector.x;
   game->info.pos.y -= mouse_vector.y;
}

void		mouse_move(t_game *game)
{
  float		decl_x;
  float		decl_y;
  float		decl_ox;
  float		decl_oy;

  if (game->mouse.clicked)
    {
      calc_move(game);
      /*
      decl_ox = (game->mouse.move.x - (MAP_CW / 2) * CASE_W - CASE_W / 2) * cos(PI/4) - (game->mouse.move.y + CASE_H) * sin(PI/4) + game->mouse.move.x;
      decl_x = (game->event.button.x - (MAP_CW / 2) * CASE_W - CASE_W / 2) * cos(PI/4) - (game->event.button.y + CASE_H) * sin(PI/4) + game->event.button.x;
      decl_oy = (game->mouse.move.x - (MAP_CW / 2) * CASE_W - CASE_W / 2) * sin(PI/4) + (game->mouse.move.y + CASE_H) * cos(PI/4) + game->mouse.move.y;
      decl_y = (game->event.button.x - (MAP_CW / 2) * CASE_W - CASE_W / 2) * sin(PI/4) + (game->event.button.y + CASE_H) * cos(PI/4) + game->event.button.y;
-*
    printf("x [%f], y [%f]\n",
	   - decl_x + decl_ox,
	   decl_y - decl_oy);

      if ((- decl_x + decl_ox > 0 && decl_y - decl_oy > 0) ||
	  (- decl_x + decl_ox < 0 && decl_y - decl_oy < 0))
	{
	  game->info.pos.x -= (decl_x - decl_ox);
	/*   game->info.pos.y += (decl_y - decl_oy) / 2; */
/* 	  printf("decalage x\n"); */
/* 	} */
/*       else if ((- decl_x + decl_ox > 0 && decl_y - decl_oy < 0) || */
/* 	       (- decl_x + decl_ox < 0 && decl_y - decl_oy > 0)) */
/* 	{ */
/* /\* 	  game->info.pos.x -= (decl_x - decl_ox) / 2; *\/ */
/* 	  game->info.pos.y += (decl_y - decl_oy) / 2; */
/* 	/\*   printf("decalage y\n"); *\/ */
/* 	} */
/*       else */
/* 	{ */
/* 	  game->info.pos.x -= (decl_x - decl_ox); */
/* 	  game->info.pos.y += (decl_y - decl_oy); */
/* 	} */

      if (game->info.pos.x < 0)
	game->info.pos.x = CASE_W * game->info.size_w + (int)game->info.pos.x;
      if (game->info.pos.y < 0)
	game->info.pos.y = CASE_H * game->info.size_h + (int)game->info.pos.y;
      if (game->info.pos.x >= CASE_W * game->info.size_w)
	game->info.pos.x = (float)((int)game->info.pos.x % (CASE_W * game->info.size_w));
      if (game->info.pos.y >= CASE_H * game->info.size_h)
	game->info.pos.y = (float)((int)game->info.pos.y % (CASE_H * game->info.size_h));
      game->mouse.move.x = game->event.button.x;
      game->mouse.move.y = (CASE_H * MAP_CH) - game->event.button.y;
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
      game->mouse.move.y = (MAP_CH * CASE_H) - game->event.button.y;
      printf("pose move start : y = [%f], x = [%f]\n", game->mouse.move.y, game->mouse.move.x);
    }
  else if (game->event.button.button == SDL_BUTTON_RIGHT)
    printf("case selected : x = [%d], y = [%d]\n",
	   (int)(game->info.pos.x + game->event.button.x) / CASE_W,
	   (int)(game->info.pos.y + (MAP_CH * CASE_H - game->event.button.y)) / CASE_H);
}
