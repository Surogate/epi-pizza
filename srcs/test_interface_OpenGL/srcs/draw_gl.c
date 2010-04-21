/*
** draw_gl.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Sat Apr 17 19:43:59 2010 Florian Chanioux
** Last update Thu Apr 22 01:13:32 2010 Florian Chanioux
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

void		draw_gl(t_game *game, GLenum mode)
{
  int		x;
  int		y;
  static int	i = 0;

  x = game->info.pos.x;
  y = game->info.pos.y;
/*  i %= 360;
    glRotated((i+= 4), 0 ,0 ,1);*/
  glPushMatrix();
  glTranslated(x, y, 0);
  glPushMatrix();
  draw_map(game, mode);
 draw_mob(game, mode);
  draw_ressource(game, mode);
  glPopMatrix();
  glPopMatrix();
}
