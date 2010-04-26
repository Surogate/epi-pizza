/*
** draw_gl.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Sat Apr 17 19:43:59 2010 Florian Chanioux
** Last update Sat Apr 24 04:51:38 2010 Florian Chanioux
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

void		draw_picture(t_game *game, int etat)
{
  if (etat == MOD_FAQ)
    glBindTexture(GL_TEXTURE_2D, game->texture->faq);
  else if (etat == MOD_BEGIN)
    {
      puts("Je suis dedans");
      glBindTexture(GL_TEXTURE_2D, game->texture->intro);
    }
  
  glDisable(GL_LIGHTING);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  glEnable(GL_TEXTURE_2D);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);
  glVertex2f(-1, -1);
  glTexCoord2f(1, 0);
  glVertex2f(1, -1);
  glTexCoord2f(1, 1);
  glVertex2f(1, 1);
  glTexCoord2f(0, 1);
  glVertex2f(-1, 1);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  
  
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_LIGHTING);

  sleep(2);

}
