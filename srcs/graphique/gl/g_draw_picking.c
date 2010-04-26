/*
** draw_picking.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Thu Apr 22 21:44:39 2010 Florian Chanioux
** Last update Mon Apr 26 10:04:34 2010 pierre1 boutbel
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include	<sys/select.h>

#ifdef		__APPLE__
# include	"SDL.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>

# include	<GL/glu.h>
# include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

void		floor_picking_h(int x, int h)
{
  glColor3f(0, 0, 0);
  glBegin(GL_QUADS);
  glVertex2d((x * CASE_W), 0);
  glVertex2d((x * CASE_W) + CASE_W, 0);
  glVertex2d((x * CASE_W) + CASE_W, (h * CASE_H));
  glVertex2d((x * CASE_W), (h * CASE_H));
  glEnd();
}

void		floor_picking_w(int y, int w)
{
  glColor3f(0, 0, 0);
  glBegin(GL_QUADS);
  glVertex2d(0, (y * CASE_H));
  glVertex2d((w * CASE_W), (y * CASE_H));
  glVertex2d((w * CASE_W), (y * CASE_H) + CASE_H);
  glVertex2d(0, (y * CASE_H) + CASE_H);
  glEnd();
}

void		floor_picking(int x, int y)
{
  glBegin(GL_QUADS);
  glVertex3d(x * CASE_W, y * CASE_H, 1);
  glVertex3d(x * CASE_W, y * CASE_H + CASE_H, 1);
  glVertex3d(x * CASE_W + CASE_W, y * CASE_H + CASE_H, 1);
  glVertex3d(x * CASE_W + CASE_W, y * CASE_H, 1);
  glEnd();
}
