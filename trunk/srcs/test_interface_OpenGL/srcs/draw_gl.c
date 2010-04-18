/*
** draw_gl.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Sat Apr 17 19:43:59 2010 Florian Chanioux
** Last update Sun Apr 18 15:36:16 2010 Florian Chanioux
*/

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
#include <GL/glu.h>
#include <GL/gl.h>
#endif

#include "define.h"
#include "struct.h"
#include "proto.h"

void		draw_gl(t_game *game)
{
  int		x;
  int		y;

  x = game->info.pos.x * 0.2;
  y = game->info.pos.y * 0.5;
  printf("val x=%i\n   y=%i\n", game->event.button.x, game->event.button.y);
  make_calllistes(game);
  glPushMatrix();
  glTranslated(-x, -y, 0);
  glPushMatrix();
  /* glRotated(45, 0, 0, 1); */
  draw_map(game);
  draw_mob();
  glPopMatrix();
  glPopMatrix();
}
