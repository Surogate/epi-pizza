/*
** draw_map.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 16:46:50 2010 Florian Chanioux
** Last update Thu Apr 22 21:42:21 2010 Florian Chanioux
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

/*
static void	picking_map(t_game *game)
{
  int		x;
  int		y;
  int		i;

  i = -1;
  x = -1;
  while (++x < game->map.w)
  {
    glPushName(++i);
    floor_picking_h(x, game->map.h);
    glPopName();
  }
  y = -1;
  while (++y < game->map.h)
  {
    glPushName(++i);
    floor_picking_w(y, game->map.w);
    glPopName();
  }
}
*/

static void     picking_map(t_game *game)
{
  int           x;
  int           y;
  int           i;

  i = -1;
  x = -1;
  while (++x < game->map.h)
  {
    y = -1;
    while (++y < game->map.w)
    {
      ++i;
      glPushName(i);
      floor_picking(y, x);
      glPopName();
    }
  }
}

static void	around(int h, int w, GLuint texture)
{
  side(w, texture);
  glPushMatrix();
  glTranslated(0, h * CASE_H, 0);
  side(w, texture);
  glPopMatrix();
  glPushMatrix();
  glRotated(90, 0, 0, 1);
  side(h, texture);
  glPushMatrix();
  glTranslated(0, -w * CASE_W, 0 );
  side(h, texture);
  glPopMatrix();
  glPopMatrix();
}

void		draw_map(t_game *game, GLenum mode)
{
  if (mode == GL_RENDER)
  {
    glEnable(GL_TEXTURE_2D);
    around(game->map.h, game->map.w, game->texture->side);
    floor_render(game->map.h, game->map.w, game->texture->floor);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    clic_map(game);
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
  }
  else
  picking_map(game);
}
