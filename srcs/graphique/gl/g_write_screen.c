/*
** g_write_screen.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Sat Apr 24 13:21:36 2010 Florian Chanioux
** Last update Mon Apr 26 10:11:24 2010 pierre1 boutbel
*/

#include	<sys/select.h>
#include	<sys/time.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>

#ifdef		__APPLE__
#include	"SDL.h"
#include	<GLUT/GLUT.h>
#else
#include	<SDL/SDL.h>
#include	<GL/glu.h>
#include	<GL/gl.h>
# include	<GL/freeglut_std.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

float		*initcolor(int color)
{
  static float tcolor[9][3] =
{
	{1.0, 1.0, 0.0},
	{1.0, 0.0, 0.0},
	{0.0, 1.0, 0.0},
	{1.0, 0.4, 1.0},
	{1.0, 1.0, 0.0},
	{1.0, 0.0, 0.0},
	{0.0, 0.0, 0.0},
	{1.0, 1.0, 1.0},
	{1.0, 1.0, 0.0}
};

return (tcolor[color]);
}

void		DrawStr(const char *str)
{
  GLint i;

  i = -1;
  if (!str)
    return ;
  while (str[++i])
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, str[i]);
}

void		pushwrite()
{
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, WIN_W, 0, WIN_H, -10.0, 10.0);
}

void		dwrite_int(int nbr, int posx, int posy, int color)
{
  int		*tcolor;
  char		res[10];

  tcolor = initcolor(color);
  glColor3f(tcolor[0], tcolor[1], tcolor[2]);
  glRasterPos2f(posx, posy);
  sprintf(res, "%d", nbr);
  DrawStr(res);
  glColor3f(1.0, 1.0, 1.0);
}

void		dwrite(char *str, int posx, int posy, int color)
{
  int   *tcolor;

  tcolor = initcolor(color);
  glColor3f(tcolor[0], tcolor[1], tcolor[2]);
  glRasterPos2f(posx, posy);
  DrawStr(str);
  glColor3f(1.0, 1.0, 1.0);
}


void		popwrite()
{
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}


/*
void		dwrite(char *str, int posx, int posy, int color)
{
  int   *tcolor;

  tcolor = initcolor(color);
  glColor3f(tcolor[0], tcolor[1], tcolor[2]);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, WIN_W, 0, WIN_H, -10.0, 10.0);
  glRasterPos2f(posx, posy);
  DrawStr(str);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glColor3f(1.0, 1.0, 1.0);
}
*/

