/*
** draw_floor.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Mon Apr 19 13:15:43 2010 Florian Chanioux
** Last update Thu Apr 22 15:23:37 2010 Florian Chanioux
*/


#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include	<sys/select.h>

#ifdef		__APPLE__
# include	"SDL.h"
# include	"SDL_ttf.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<SDL/SDL_ttf.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
#endif

#include	"3dsloader.h"
#include	"define.h"
#include	"struct.h"
#include	"proto.h"

void		floor_picking(int x, int y)
{
  glBegin(GL_QUADS);
  glColor3ub(255, 255, 255);
  glVertex2d(x * CASE_W, y * CASE_H);
  glColor3ub(255, 255, 255);
  glVertex2d(x * CASE_W, y * CASE_H + CASE_H);
  glColor3ub(255, 255, 255);
  glVertex2d(x * CASE_W + CASE_W, y * CASE_H + CASE_H);
  glColor3ub(255, 255, 255);
  glVertex2d(x * CASE_W + CASE_W, y * CASE_H);
  glEnd();
}

void		floor_clic(GLuint texture)
{
  glBindTexture(GL_TEXTURE_2D, texture);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);
  glVertex2d(0, 0);
  glTexCoord2f(0,1);
  glVertex2d(0, CASE_W);
  glTexCoord2f(1, 1);
  glVertex2d(CASE_H, CASE_W);
  glTexCoord2f(1, 0);
  glVertex2d(CASE_H, 0);
  glEnd();
}

void		floor_render(int h, int w, GLuint texture)
{
  glBindTexture(GL_TEXTURE_2D, texture);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);
  glVertex2d(0, 0);
  glTexCoord2f(0,h);
  glVertex2d(0, h * CASE_H);
  glTexCoord2f(w, h);
  glVertex2d(w * CASE_W, h * CASE_H);
  glTexCoord2f(w, 0);
  glVertex2d(w * CASE_W, 0);
  glEnd();
}

void		side(int x, GLuint texture)
{
  glBindTexture(GL_TEXTURE_2D, texture);
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0);
  glVertex3d(0, 0, 0);
  glTexCoord2f(x, 0);
  glVertex3d(x * CASE_W, 0, 0);
  glTexCoord2d(x, 1);
  glVertex3d(x * CASE_W, 0, -10);
  glTexCoord2d(0, 1);
  glVertex3d(0, 0, -10);
  glEnd();
}
