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
#include	"../includes/define.h"
#include	"../includes/struct.h"

void		mouse_move(t_game *game)
{
  if (game->mouse.clicked)
    {
      game->view.pos.x += game->mouse.move.x - game->event.button.x;
      game->view.pos.y -= game->mouse.move.y - game->event.button.y;
      if (game->view.pos.x < 0)
	game->view.pos.x = CASE_W * game->view.size_w - 1;
      if (game->view.pos.y < 0)
	game->view.pos.y = CASE_H * game->view.size_h - 1;
      game->view.pos.x = game->view.pos.x % (CASE_W * game->view.size_w);
      game->view.pos.y = game->view.pos.y % (CASE_H * game->view.size_h);
      printf("drag : new pos is x = [%d], y = [%d].\ncase current : x=[%d], y=[%d]\n",
	     game->view.pos.x,
	     game->view.pos.y,
	     game->view.pos.x / CASE_W,
	     game->view.pos.y / CASE_H);
      game->mouse.move.x = game->event.button.x;
      game->mouse.move.y = game->event.button.y;
    }
}

void		mouse_up(t_game *game)
{
  if (game->event.button.button == SDL_BUTTON_LEFT)
    {
      printf("release at x = [%d], y = [%d].\ncase current : x=[%d], y=[%d]\n",
	     game->view.pos.x,
	     game->view.pos.y,
	     game->view.pos.x / CASE_W,
	     game->view.pos.y / CASE_H);
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
	   (game->view.pos.x + game->event.button.x) / CASE_W,
	   (game->view.pos.y + (MAP_CH * CASE_H - game->event.button.y)) / CASE_H);
}
