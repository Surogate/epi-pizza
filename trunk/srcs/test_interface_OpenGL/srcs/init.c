/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Fri Apr 16 16:00:07 2010 Florian Chanioux
*/
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<sys/types.h>

#include	"define.h"
#include	"struct.h"
#include	"proto.h"

# define	FONT_DIR	"./font/MONACO.ttf"
# define	MFONT_SIZE	7
# define	FULLSCREEN	0

SDL_Surface	*load_window()
{
  SDL_Surface	*screen;
  Uint32 flags= 0;

  flags= SDL_OPENGL;
  if (FULLSCREEN)
    flags|= SDL_FULLSCREEN;
  xSDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
  screen = xSDL_SetVideoMode(CASE_W * MAP_CW, CASE_H * MAP_CH,
			    WIN_COLOR, flags);
  SDL_WM_SetCaption("Zappy", NULL);
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
  game->map.fond = img_load("images/fond_losange.bmp");
  if (TTF_Init() < 0)
    {
      fprintf(stderr, "TTF error : %s", TTF_GetError());
      exit(EXIT_FAILURE);
    }
  game->font = TTF_OpenFont(FONT_DIR, MFONT_SIZE);
  game->info.pos.x = 0;
  game->info.pos.y = 0;
  game->info.size_h = 100;
  game->info.size_w = 100;
  game->ticks = SDL_GetTicks();
  printf("[%u]\n", game->ticks);
  init_map(game);
  SDL_ShowCursor(1);
}
