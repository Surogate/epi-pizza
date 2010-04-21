/*
** draw_interfaces.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Wed Apr 21 18:05:56 2010 Florian Chanioux
** Last update Wed Apr 21 18:43:26 2010 Florian Chanioux
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
# include	<GL/freeglut_std.h>
#endif

static void	interface_up_with_transp()
{
  glBegin(GL_QUADS);
    glVertex3f(-0.6, 0.8, 0.5);
    glVertex3f(0.6, 0.8, 0.5);
    glVertex3f(0.6, 1, 0.5);
    glVertex3f(-0.6, 1, 0.5);
  glEnd();
}

static void	interface_up_without_transp()
{
  glBegin(GL_QUADS);
    glVertex3f(-0.6, 0.8, 0.5);
    glVertex3f(0.6, 0.8, 0.5);
    glVertex3f(0.6, 1, 0.5);
    glVertex3f(-0.6, 1, 0.5);
  glEnd();
}

static void	interface_down_left_with_transp()
{
  glBegin(GL_QUADS);
  glVertex3f(0.3, -0.6, 0.5);
  glVertex3f(1, -0.6, 0.5);
  glVertex3f(1, -1, 0.5);
  glVertex3f(0.3, -1, 0.5);
  glEnd();
}

static void	interface_down_left_without_transp()
{
  glBegin(GL_QUADS);
  glVertex3f(0.6, -0.8, 0.5);
  glVertex3f(1, -0.8, 0.5);
  glVertex3f(1, -1, 0.5);
  glVertex3f(0.6, -1, 0.5);
  glEnd();
}
void		draw_interface()
{
  glDisable(GL_TEXTURE_2D);
  glColor3ub(255,255, 255);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  interface_up_without_transp();
  interface_down_left_with_transp();
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);

}
