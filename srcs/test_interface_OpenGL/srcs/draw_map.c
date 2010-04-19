/*
** draw_map.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr 16 16:46:50 2010 Florian Chanioux
** Last update Mon Apr 19 14:31:00 2010 Florian Chanioux
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

void		make_calllistes(t_game *game)
{
  glNewList(MAP_CASE,GL_COMPILE);
/*
  make_side(game);
  glPushMatrix();
  glTranslated(0, CASE_H, 0);
  make_side(game);
  glPopMatrix();
  glPushMatrix();
  glRotated(90, 0, 0 , 1);
  make_side(game);
  glPushMatrix();
  glTranslated(0, -CASE_H, 0);
  make_side(game);
  glPopMatrix();
  glPopMatrix();
*/
  floor_without_t(0, 0);
  glEndList();
}

void		draw_map(t_game *game)
{
  int		h;
  int		w;

  h = -1;
  while (++h < MAP_CH)
  {
    w = -1;
    while (++w < MAP_CW)
      floor_without_t(h, w);
/*      floor_with_t(game, h, w);*/
  }
}

 /*
void draw_map(t_game *game)
{
  int	h;
  int	w;

  h = -2;
  while (++h < MAP_CH)
  {
    w = -2;
    while (++w < MAP_CW)
    {
      glBegin(GL_QUADS);
      glColor3ub(255,255, 255);
      glVertex3d(w * CASE_W, h * CASE_H,0);
      glColor3ub(0, 0, 255);
      glVertex3d(w *  CASE_W, h * CASE_H + CASE_H,0);
      glColor3ub(255,255, 255);
      glVertex3d(w *  CASE_W + CASE_W, h * CASE_H + CASE_H,0);
      glColor3ub(0, 0, 0);
      glVertex3d(w *  CASE_W + CASE_W, h * CASE_H,0);
      glEnd();
    }
  }
}
*/
