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

void		mouse_move(SDL_Event *event, int *clicked, t_pos *pos, t_pos *move)
{
  if (*clicked)
    {
      pos->x += move->x - event->button.x;
      pos->y -= move->y - event->button.y;
      printf("drag : new pos is x = [%d], y = [%d].\n", pos->x, pos->y);
      move->x = event->button.x;
      move->y = event->button.y;
    }
}

void		mouse_up(SDL_Event *event, int *clicked, t_pos *pos)
{
  if (event->button.button == SDL_BUTTON_LEFT)
    {
      printf("release at x = [%d], y = [%d] pos.\n", pos->x, pos->y);
      *clicked = 0;
    }
}

void		mouse_down(SDL_Event *event, int *clicked, t_pos *pos, t_pos *move)
{
  if (event->button.button == SDL_BUTTON_LEFT)
    {
      printf("click\n");
      *clicked = 1;
      move->x = event->button.x;
      move->y = event->button.y;
    }
  else if (event->button.button == SDL_BUTTON_RIGHT)
    printf("case selected : x = [%d], y = [%d]\n",
	   pos->x + event->button.x,
	   pos->y + (MAP_CH * CASE_H - event->button.y));
}
