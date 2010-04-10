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
#include	"define.h"
#include	"struct.h"

void		key_func(SDL_Event *event)
{
  if (event->key.keysym.sym == SDLK_LEFT)
    printf("Left rotation\n");
  else if (event->key.keysym.sym == SDLK_RIGHT)
    printf("Right rotation\n");
  else if (event->key.keysym.sym == SDLK_ESCAPE)
    exit(EXIT_SUCCESS);
}

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

void		mouse_up(SDL_Event *event, int *clicked, t_pos *pos, t_pos *move)
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

void		exit_func()
{
  exit(EXIT_SUCCESS);
}

/*-----------------------------*/

t_event		event_type[]=
{
  {SDL_QUIT, exit_func},
  {SDL_MOUSEBUTTONDOWN, mouse_down},
  {SDL_MOUSEBUTTONUP, mouse_up},
  {SDL_MOUSEMOTION, mouse_move},
  {SDL_KEYDOWN, key_func},
  {0,0}
};

void		xSDL_Flip(SDL_Surface *screen)
{
  if (SDL_Flip(screen) == -1)
    {
      fprintf(stderr, "Refresh fail\n");
      exit(EXIT_FAILURE);
    }
}

SDL_Surface	*load_window()
{
  SDL_Surface	*screen;

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    {
      fprintf(stderr, "Cant init sdl!\n");
      exit(EXIT_FAILURE);
    }
  screen = SDL_SetVideoMode(CASE_W * MAP_CW, CASE_H * MAP_CH,
			    WIN_COLOR, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (screen == NULL)
    {
      fprintf(stderr, "Window's create fail!\n");
      exit(EXIT_FAILURE);
    }
  SDL_WM_SetCaption("LemIPC", NULL);
  return (screen);
}

int		main(void)
{
  SDL_Event	event;
  SDL_Surface	*screen;
  t_pos		pos;
  t_pos		move;
  int		i;
  int		clicked;

  clicked = 0;
  pos.x = 0;
  pos.y = 0;
  screen = load_window();
  while (1)
    if (SDL_PollEvent(&event))
      {
	i = 0;
	while (event_type[i].type)
	  {
	    if (event.type == event_type[i].type)
	      event_type[i].func(&event, &clicked, &pos, &move);
	    i++;
	  }
      }
  return (EXIT_SUCCESS);
}
