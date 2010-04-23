/*
** draw_floor.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Mon Apr 19 13:15:43 2010 Florian Chanioux
** Last update Sat Apr 24 03:23:06 2010 Florian Chanioux
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

void		clic_render()
{
  static int	i;

  glPushMatrix();
  glTranslatef(CASE_H / 2, CASE_W / 2, 0);
  glPushMatrix();
  i %= 360;
  glRotated((i+= 2), 0 ,0 ,1);
  glCallList(PICKING);
  glPopMatrix();
  glPopMatrix();
}

void		around(int h, int w, GLuint texture)
{
  side(w, texture);
  glPushMatrix();
  glTranslated(0, h * CASE_H, 0);
  side(w, texture);
  glPopMatrix();
  glPushMatrix();
  glRotated(90, 0, 0, 1);
  side(h, texture);
  glPushMatrix();
  glTranslated(0, -w * CASE_W, 0 );
  side(h, texture);
  glPopMatrix();
  glPopMatrix();
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
