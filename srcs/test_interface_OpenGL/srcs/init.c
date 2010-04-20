/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Tue Apr 20 14:37:51 2010 Florian Chanioux
*/

#include <sys/types.h>
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
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

#include "3dsloader.h"
#include "define.h"
#include "struct.h"
#include "proto.h"

static SDL_Surface	*load_window()
{
  SDL_Surface		*screen;
  Uint32		flags;

  flags= SDL_OPENGL;
  if (FULLSCREEN)
    flags |= SDL_FULLSCREEN;
  xSDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
  screen = xSDL_SetVideoMode(WIN_W, WIN_H,
			    WIN_COLOR, flags);
  SDL_WM_SetCaption("Zappy", NULL);
  return (screen);
}

void		init_map(t_game *game)
{
  int		y;
  int		x;
  int		temp;

  game->map.t_case= malloc(game->info.size_h * sizeof(*(game->map.t_case)));
  y = -1;
  while (++y < game->info.size_h)
  {
    game->map.t_case[y] = malloc(game->info.size_w * sizeof(t_case));
    x = -1;
    while (++x < game->info.size_w)
    {
      game->map.t_case[y][x].player = 0;
      temp = -1;
      while (++temp < 7)
	game->map.t_case[y][x].obj[temp] = 0;
    }
  }
}

void		init_game(t_game *game)
{
  game->screen = load_window();
  game->mouse.clicked = 0;
  game->video.text = 1;
  game->video.fog = 1;
  game->video.light = 0;
  game->texture.floor = loadtexture("images/lawn.jpg", 0);
  game->texture.side = loadtexture("images/side.jpg", 0);
  puts("coucou");
  Load3DS("3DS/totoro.3ds", &(game->model.trantorien));
  puts("byebye");
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
  init_map(game);
  SDL_ShowCursor(1);
}
