/*
** draw_mob.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 17:10:54 2010 Florian Chanioux
** Last update Sat Apr 24 04:53:05 2010 Florian Chanioux
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

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

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
/*
static void	picking_mob(t_game *game)
{
  int		x;
  int		y;
  int		i;

  i = -1;
  x = -1;
  while (++x < game->map.h)
  {
    y = -1;
    while (++y < game->map.w)
    {
      ++i;
      glPushName(i);
      mod_picking(y, x);
      glPopName();
    }
  }
}
*/
/*
void		draw_mod(t_game *game, GLenum mode)
{
  if (mode == GL_RENDER)
  {
    glEnable(GL_TEXTURE_2D);
    floor_render(game->map.h, game->map.w, game->texture->floor);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    clic_mod(game);
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
  }
  else
    picking_mod(game);
}
*/


static void	draw_trantorien(int name, GLenum mode)
{
  glPushMatrix();
  glTranslated((CASE_H / 2), (CASE_W / 2), 0);
  if (mode == GL_SELECT)
    glPushName(name);
  glCallList(TOTORO);
  if (mode == GL_SELECT)
    glPopName();
  glPopMatrix();
}

void		draw_mob(t_game *game, GLenum mode)
{
  int		x;
  int		y;
  int		name;

  name = game->map.h * game->map.w;
  x = -1;
  while (++x < game->map.h)
  {
    y = -1;
    while (++y < game->map.w)
    {
      glPushMatrix();
      glTranslated(y * CASE_H, x * CASE_W, 0);
      draw_trantorien(name++, mode);
      glPopMatrix();
    }
  }
}
