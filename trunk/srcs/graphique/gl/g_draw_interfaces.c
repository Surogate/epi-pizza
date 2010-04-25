/*
** draw_interfaces.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Wed Apr 21 18:05:56 2010 Florian Chanioux
** Last update Sat Apr 24 13:26:34 2010 Florian Chanioux
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

void	interface_up(GLuint texture)
{
  glBindTexture(GL_TEXTURE_2D, texture);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);
  glVertex3f(-0.4, 0.85, 0.5);
  glTexCoord2f(1, 0);
  glVertex3f(0.4, 0.85, 0.5);
  glTexCoord2f(1, 1);
  glVertex3f(0.4, 1, 0.5);
  glTexCoord2f(0, 1);
  glVertex3f(-0.4, 1, 0.5);
  glEnd();
}

void	interface_down(GLuint texture)
{
  glBindTexture(GL_TEXTURE_2D, texture);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);
  glVertex3f(0.45, -0.45, 0.9);
  glTexCoord2f(0, 1);
  glVertex3f(1, -0.45, 0.9);
  glTexCoord2f(1, 1);
  glVertex3f(1, -1, 0.9);
  glTexCoord2f(1, 0);
  glVertex3f(0.45, -1, 0.9);
  glEnd();
}

void		show_info(t_game *game)
{
  t_pos pos;
  
  pos.x = 50;
  pos.y = 50;
  dwrite("COUCOU", pos, RED);
}

void		draw_interface(t_game *game)
{
  t_pos pos;
  
  pos.x = 10;
  pos.y = 10;
  game = game;
  glDisable(GL_LIGHTING);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  glCallList(INTER);
  show_info(game);
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_LIGHTING);
}
