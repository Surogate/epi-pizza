/*
** draw_ressource.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Tue Apr 20 12:41:25 2010 Florian Chanioux
** Last update Sat Apr 24 04:53:57 2010 Florian Chanioux
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

void		draw_treasure(t_case cas, int ref, GLenum mode, int num)
{

  /*
  glPushMatrix();
  glTranslated(player->pos.x * CASE_W, player->pos.y * CASE_H, 0);
  */

  glPushMatrix();
  glTranslated(cas.obj[num][0], cas.obj[num][1], -5);
  glPushMatrix();
  glTranslated(0, 0, .01);

  /* Je sais pas trop a quoi ca sert, ca pourrait etre utile ? 
  glCallList(TEAM);
  */

  glPopMatrix();
  glCallList(RESS + num);

  if (mode == GL_SELECT)
    glPopName();

  glPopMatrix();
}

void		draw_ressource(t_game *game, GLenum mode)
{
  int		ref;
  int		x;
  int		y;
  int		ress;  
  
  ref = game->map.h * game->map.w;
  x = -1;
  while (++x < game->map.h)
    {
      y = -1;
      while (++y < game->map.w)
	{ 
	  ress = -1;
	  
	  while (++ress != NBRESS)
	    {
	      glPushMatrix();
	      glTranslated(x * CASE_W, y * CASE_H, 0);
	  
	  /*glScalef(mesh->scale[0], mesh->scale[1], mesh->scale[2]);*/
	      
	      draw_treasure(game->map.t_case[x][y], ref, mode, ress);
	    }
	}
    }
}





/*
  glPushMatrix();
  glTranslated(y * CASE_H, x * CASE_W, 0);
  glPopMatrix();
*/

