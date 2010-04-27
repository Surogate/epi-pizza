/*
** draw_ressource.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Tue Apr 20 12:41:25 2010 Florian Chanioux
** Last update Mon Apr 26 09:58:48 2010 pierre1 boutbel
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include	<sys/select.h>

#ifdef		__APPLE__
#include	"SDL.h"
#include	<GLUT/GLUT.h>
#else
#include	<SDL/SDL.h>
#include	<GL/glu.h>
#include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

void		draw_treasure(t_case cas, int num, int qte)
{
  qte %= 10;
  glPushMatrix();
  glTranslated(cas.obj[num][0], cas.obj[num][1], 0.5);
  glScalef(qte / 5, qte / 5, qte / 5);
  glCallList(RESS + num);
  glPopMatrix();
}

void		draw_ressource(t_game *game, GLenum mode)
{
  int		x;
  int		y;
  int		ress;
  int		qte;
  
  y = -1;
  while (++y < game->map.h)
    {
      x = -1;
      while (++x < game->map.w)
	{ 
	  ress = -1;
	  while (++ress != NBRESS)
	    {
	      if ((qte = game->map.t_case[y][x].obj[ress][2]))
		{
		  glPushMatrix();
		  glTranslated(x * CASE_H, y * CASE_W, 0);
		  draw_treasure(game->map.t_case[y][x], ress, qte);
		  glPopMatrix();
		}
	    }
	}
    }
}
