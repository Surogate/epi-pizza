/*
** draw_map.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr 16 16:46:50 2010 Florian Chanioux
** Last update Fri Apr 16 17:21:01 2010 Florian Chanioux
*/

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
#include	"proto.h"

void make_calllistes()
{
  glNewList(MAP_CASE,GL_COMPILE);
  glBegin(GL_QUADS);
  glColor3ub(255,255, 255);
  glVertex2d(0, 0);
  glColor3ub(0, 0, 255);
  glVertex2d(0, CASE_H);
  glColor3ub(255,255, 255);
  glVertex2d(CASE_W, CASE_H);
  glColor3ub(0, 0, 0);
  glVertex2d(CASE_W, 0);
  glEnd();
  glEndList();
}

void draw_map(int *table, t_game *game)
{
  int cx, cy, cz, px, py, pz;
  int	h;
  int	w;

  h = game->info.pos.y / CASE_H + game->info.pos.y % CASE_H;
  w = game->info.pos.x / CASE_W + game->info.pos.x % CASE_W;
  cx = h;
  cy = w;
  cz = 70;
  px = h + CASE_H * 2;
  py = w + CASE_W * 2;
  pz = 0;
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  camera(cx, cy, cz, px, py, pz, table);
  h = -2;
  while (++h < MAP_CH)
  {
    w = -2;
    while (++w < MAP_CW)
    {
      glPushMatrix();
      glTranslated(w * CASE_W, h *  CASE_H, 0);
      glCallList(MAP_CASE);
      glPopMatrix();
    }
  }
  glFlush();
}
