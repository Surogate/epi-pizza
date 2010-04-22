/*
** draw_mob.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 17:10:54 2010 Florian Chanioux
** Last update Thu Apr 22 16:54:18 2010 Florian Chanioux
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

void		draw_mesh(obj_type *mesh)
{
  int		l_index;

  glBindTexture(GL_TEXTURE_2D, mesh->id_texture);
  glColor3f(1.0f, 1.0f, 1.0f);
  glPushMatrix();
  glScalef(mesh->scale[0], mesh->scale[1], mesh->scale[2]);
  glBegin(GL_TRIANGLES);
  l_index = -1;
  while (++l_index < mesh->polygons_qty)
  {
    glTexCoord2f(mesh->mapcoord[ mesh->polygon[l_index].a ].u,
		 mesh->mapcoord[ mesh->polygon[l_index].a ].v);
    glVertex3f(mesh->vertex[ mesh->polygon[l_index].a ].x,
	       mesh->vertex[ mesh->polygon[l_index].a ].y,
	       mesh->vertex[ mesh->polygon[l_index].a ].z);
    glTexCoord2f(mesh->mapcoord[ mesh->polygon[l_index].b ].u,
		 mesh->mapcoord[ mesh->polygon[l_index].b ].v);
    glVertex3f(mesh->vertex[ mesh->polygon[l_index].b ].x,
	       mesh->vertex[ mesh->polygon[l_index].b ].y,
	       mesh->vertex[ mesh->polygon[l_index].b ].z);
    glTexCoord2f(mesh->mapcoord[ mesh->polygon[l_index].c ].u,
		 mesh->mapcoord[ mesh->polygon[l_index].c ].v);
    glVertex3f(mesh->vertex[ mesh->polygon[l_index].c ].x,
	       mesh->vertex[ mesh->polygon[l_index].c ].y,
	       mesh->vertex[ mesh->polygon[l_index].c ].z);
  }
  glEnd();
  glPopMatrix();
}

void		draw_mob(t_game *game, GLenum mode)
{
  game = game;
  mode = mode;

  glEnable(GL_TEXTURE_2D);
  glPushMatrix();
  glRotated(180, 0, 0, 1);
  glTranslated(-(game->video.cam[0]), -(game->video.cam[1]), 0);
  draw_mesh(game->model.trantorien);
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}


