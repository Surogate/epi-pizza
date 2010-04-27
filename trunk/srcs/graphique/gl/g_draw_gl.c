/*
** draw_gl.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Sat Apr 17 19:43:59 2010 Florian Chanioux
** Last update Sat Apr 24 04:51:38 2010 Florian Chanioux
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include	<sys/select.h>

#ifdef		__APPLE__
# include	"SDL.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

void		draw_gl(t_game *game, GLenum mode)
{
  int		x;
  int		y;

  x = game->info.pos.x;
  y = game->info.pos.y;
  glPushMatrix();
  glTranslated(-x, -y, 0);
  glPushMatrix();
  glRotated(game->map.rot, 0, 0, 1);
  glTranslated(-game->map.h * CASE_H / 2, -game->map.w * CASE_W / 2, 0);
  glPushMatrix();
  draw_map(game, mode);
  if (game->info.crazy == MOD_OK)
  {
    draw_ressource(game, mode);
    draw_mob(game, mode);
    draw_eggs(game, mode);
  }
  else if (game->info.crazy == MOD_CRAZY)
    crazy_mod(game);
  else
    draw_picture(game, game->info.crazy);
  glPopMatrix();
  glPopMatrix();
  glPopMatrix();
}
