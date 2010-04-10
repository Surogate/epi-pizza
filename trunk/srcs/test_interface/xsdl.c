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
