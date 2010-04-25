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

static void		show_info(t_game *game)
{
  pushwrite();
    dwrite("TEAM:", 800, 170, RED);
    dwrite("LVL:", 856, 140, RED);
    dwrite_int(0, 900, 140, GREEN);
    dwrite("nourriture:", 800, 120, RED);
    dwrite_int(0, 900, 120, GREEN);
    dwrite("linemate:", 816, 105, RED);
    dwrite_int(0, 900, 105, GREEN);
    dwrite("deraumere:", 808, 90, RED);
    dwrite_int(0, 900, 90, GREEN);
    dwrite("sibur:", 840, 75, RED);
    dwrite_int(0, 900, 75, GREEN);
    dwrite("phiras:", 832, 60, RED);
    dwrite_int(0, 900, 60, GREEN);
    dwrite("thystame:", 816, 45, RED);
    dwrite_int(0, 900, 45, GREEN);
      popwrite();
}

static void		show_info_val(t_game *game)
{

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
