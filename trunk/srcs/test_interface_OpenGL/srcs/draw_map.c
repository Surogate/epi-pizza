/*
** draw_map.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 16:46:50 2010 Florian Chanioux
** Last update Thu Apr 22 01:09:25 2010 Florian Chanioux
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
  while (++h < MAP_CH)
  {
    w = -1;
    while (++w < MAP_CW)
    {
      ++i;
      glPushName(i);
      floor_picking(h, w);
      glPopName();
    }
  }
}

static void	around(t_game *game, int h, int w)
{
  side(game, h);
  glPushMatrix();
  glTranslated(0, w * CASE_W, 0);
  side(game, h);
  glPopMatrix();
  glPushMatrix();
  glRotated(90, 0, 0, 1);
  side(game, w);
  glPushMatrix();
  glTranslated(0, -h * CASE_H, 0 );
  side(game, w);
  glPopMatrix();
  glPopMatrix();
}

static void	clic(t_game *game)
{
  static int	i;
  int		x;
  int		y;

  x = game->map.select % MAP_CH;
  y = game->map.select / MAP_CH;

  glPushMatrix();
  glTranslatef(y * CASE_H, x * CASE_W, .06);
  floor_clic(game->texture.floor_s);
  glPopMatrix();
}

void		draw_map(t_game *game, GLenum mode)
{

  
  if (game->video.text)
    glEnable(GL_TEXTURE_2D);
  if (mode == GL_RENDER)
  {
    floor_render(MAP_CH, MAP_CW,
		 game->texture.floor);
    clic(game);
  }
  else
    picking_map(game);
  around(game, MAP_CH, MAP_CW);
  glDisable(GL_REPEAT);
}
