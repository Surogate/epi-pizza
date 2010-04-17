/*
** draw_map.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr 16 16:46:50 2010 Florian Chanioux
** Last update Fri Apr 16 20:01:50 2010 Florian Chanioux
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
      glPushMatrix();
      glTranslated(w * CASE_W, h *  CASE_H, 0);
      glCallList(MAP_CASE);
      glPopMatrix();
    }
  }
  glFlush();
}
