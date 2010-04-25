/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Wed Apr 21 22:51:24 2010 Florian Chanioux
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef __APPLE__
#include "SDL.h"
#include <GLUT/GLUT.h>
#else
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

void		sdlerror()
{
  if (fprintf(stderr, "SDL Error : %s\n", SDL_GetError()) == -1)
    fprintf(stderr, "SDL error failed, it's really anoying :/");
  exit(EXIT_FAILURE);
}

void		xSDL_Flip(SDL_Surface *screen)
{
  if (SDL_Flip(screen) == -1)
    {
      fprintf(stderr, "Refresh fail\n");
      exit(EXIT_FAILURE);
    }
}

int		xSDL_Init(Uint32 flags)
{
  int		retour;

  retour = SDL_Init(flags);
  if (retour < 0)
    {
      fprintf(stderr, "Cant init sdl!\n");
      exit(EXIT_FAILURE);
    }
  return (retour);
}

SDL_Surface	*xSDL_SetVideoMode(int width, int height, int bpp, Uint32 flags)
{
  SDL_Surface	*screen;

  screen = SDL_SetVideoMode(width, height, bpp, flags);
  if (screen == NULL)
    {
      fprintf(stderr, "Window's create fail!\n");
      exit(EXIT_FAILURE);
    }
  return (screen);
}

void		xSDL_BlitSurface(SDL_Surface *src, SDL_Rect *srcrect,
				 SDL_Surface *dst, SDL_Rect *dstrect)
{
  if (SDL_BlitSurface(src, srcrect, dst, dstrect) == -1)
    sdlerror();
}


SDL_Surface		*xSDL_CreateRGBSurface(Uint32 flags, int width,
					      int height, int bitsperpixel,
					      Uint32 rmask, Uint32 gmask,
					      Uint32 bmask, Uint32 amask)
{
  SDL_Surface		*surface;

  if ((surface = SDL_CreateRGBSurface(flags, width, height, bitsperpixel,
				      rmask, gmask, bmask, amask)) == NULL)
    sdlerror();
  return (surface);
}
