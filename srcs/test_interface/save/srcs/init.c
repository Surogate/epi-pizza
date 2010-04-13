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
#include	"../includes/proto.h"
# define	FONT_DIR	"./font/MONACO.ttf"
# define	MFONT_SIZE	7

SDL_Surface	*load_window()
{
  SDL_Surface	*screen;

  xSDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
  screen = xSDL_SetVideoMode(CASE_W * MAP_CW, CASE_H * MAP_CH,
			    WIN_COLOR, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("LemIPC", NULL);
  return (screen);
}

SDL_Surface	*img_load(char *path)
{
  SDL_Surface	*img;
  SDL_Surface	*tmp;

  tmp = SDL_LoadBMP(path);
  if (tmp)
    {
      img = SDL_DisplayFormat(tmp);
      SDL_FreeSurface(tmp);
      return (img);
    }
  return (NULL);
}

void		init_map(t_game *game)
{
  int		y;
  int		x;
  int		temp;

  game->map.t_case= malloc(game->info.size_h * sizeof(*(game->map.t_case)));
  y = 0;
  while (y < game->info.size_h)
    {
      game->map.t_case[y] = malloc(game->info.size_w * sizeof(t_case));
      x = 0;
      while (x < game->info.size_w)
	{
	  game->map.t_case[y][x].player = 0;
	  temp = 0;
	  while (temp < 7)
	    {
	      game->map.t_case[y][x].obj[temp] = 0;
	      temp++;
	    }
	  x++;
	}
      y++;
    }
}

void		init_game(t_game *game)
{
  game->screen = load_window();
  game->mouse.clicked = 0;
  game->mouse.img[0] = img_load("images/main_ouverte.bmp");
  game->mouse.img[1] = img_load("images/main_fermer.bmp");
  game->map.fond = img_load("images/fond_map.bmp");
  if (TTF_Init() < 0)
    {
      fprintf(stderr, "TTF error : %s", TTF_GetError());
      exit(EXIT_FAILURE);
    }
  game->font = TTF_OpenFont(FONT_DIR, MFONT_SIZE);
  printf("[%d]\n",game->font);
  game->info.pos.x = 0;
  game->info.pos.y = 0;
  game->info.size_h = 100;
  game->info.size_w = 100;
  init_map(game);
  SDL_ShowCursor(0);
}
