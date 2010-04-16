/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Fri Apr 16 18:17:30 2010 Florian Chanioux
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
#include <GL/glu.h>
#include <GL/gl.h>
#endif

#include	"define.h"
#include	"struct.h"

int		main(void)
{
  t_game	game;
  int		i;

  init_game(&game);
  initAttributes(&game);
  SDL_ShowCursor(1);
  /* createSurface(0); Create GL context */
  printAttributes();
  initGL();
  mainloop(&game);
  SDL_Quit();
  return (EXIT_SUCCESS);
}
