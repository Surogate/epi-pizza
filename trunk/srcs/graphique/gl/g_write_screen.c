/*
** g_write_screen.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Sat Apr 24 13:21:36 2010 Florian Chanioux
** Last update Sat Apr 24 13:22:36 2010 Florian Chanioux
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

float   *initcolor(int color)
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
  if(!str)
    return ;
  while(str[++i])
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
}

void		dwrite(char *str, t_pos pos, int color)
{
  int   *tcolor;

  tcolor = initcolor(color);
  glColor3f(tcolor[0], tcolor[1], tcolor[2]);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(0, WIN_W, 0, WIN_H, -10.0, 10.0);
  glRasterPos2f(pos.x, pos.y);
  DrawStr(str);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glColor3f(1.0, 1.0, 1.0);
}


