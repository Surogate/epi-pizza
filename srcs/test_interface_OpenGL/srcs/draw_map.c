/*
** draw_map.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 16:46:50 2010 Florian Chanioux
** Last update Thu Apr 22 14:01:54 2010 Florian Chanioux
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


static void	picking_map(t_game *game)
{
  int		h;
  int		w;
  int		i;

  i = -1;
  h = -1;
  while (++h < game->map.h)
  {
    w = -1;
    while (++w < game->map.w)
    {
      ++i;
      glPushName(i);
      floor_picking(h, w);
      glPopName();
    }
  }
}

static void	around(int h, int w, GLuint texture)
{
  side(h, texture);
  glPushMatrix();
  glTranslated(0, w * CASE_W, 0);
  side(h, texture);
  glPopMatrix();
  glPushMatrix();
  glRotated(90, 0, 0, 1);
  side(w, texture);
  glPushMatrix();
  glTranslated(0, -h * CASE_H, 0 );
  side(w, texture);
  glPopMatrix();
  glPopMatrix();
}

static void	clic(t_game *game)
{
  static int	i;
  int		x;
  int		y;

  x = game->map.select % game->map.h;
  y = game->map.select / game->map.h;

  glPushMatrix();
  glTranslatef(y * CASE_H + (CASE_H / 2),
	       x * CASE_W + (CASE_W / 2), .1);
  glPushMatrix();
  i %= 360;
  glRotated((i+= 2), 0 ,0 ,1);
  glTranslatef(-CASE_H / 2, -CASE_W /2, 0);
  floor_clic(game->texture.floor_s);
  glPopMatrix();
  glPopMatrix();
}

void		draw_map(t_game *game, GLenum mode)
{
  if (game->video.text)
    glEnable(GL_TEXTURE_2D);
  if (mode == GL_RENDER)
  {
    floor_render(game->map.h, game->map.w, game->texture.floor);
    clic(game);
  }
  else
    picking_map(game);
  around(game->map.h, game->map.w, game->texture.side);
  glDisable(GL_TEXTURE_2D);
}
