/*
** CallList.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Sat Apr 24 02:51:07 2010 Florian Chanioux
** Last update Sat Apr 24 04:51:38 2010 Florian Chanioux
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
#include	"graphique/struct.h"
#include	"graphique/proto.h"

void		make_calllistes_picking(t_game *game)
{
  glNewList(PICKING, GL_COMPILE);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glTranslatef(-CASE_H / 2, -CASE_W /2, 0);
  glBindTexture(GL_TEXTURE_2D, game->texture->floor_s);
  glBegin(GL_QUADS);
  glTexCoord2f(0, 0);
  glVertex2d(0, 0);
  glTexCoord2f(0,1);
  glVertex2d(0, CASE_W);
  glTexCoord2f(1, 1);
  glVertex2d(CASE_H, CASE_W);
  glTexCoord2f(1, 0);
  glVertex2d(CASE_H, 0);
  glEnd();
  glDisable(GL_BLEND);
  glDisable(GL_TEXTURE_2D);
  glEndList();
}

void		make_calllistes_trantorien(t_game *game)
{
  glNewList(TOTORO, GL_COMPILE);
  glEnable(GL_TEXTURE_2D);
  draw_mesh(game->model.trantorien);
  glDisable(GL_TEXTURE_2D);
  glEndList();
}

void		make_calllistes_terrain(t_game *game)
{
  glNewList(TERRAIN, GL_COMPILE);
  glEnable(GL_TEXTURE_2D);
  around(game->map.h, game->map.w, game->texture->side);
  floor_render(game->map.h, game->map.w, game->texture->floor);
  glDisable(GL_TEXTURE_2D);
  glEndList();
}

void		make_calllistes_interface(t_game *game)
{
  glNewList(INTER, GL_COMPILE);

  glEnable(GL_TEXTURE_2D);
  interface_up(game->texture->inter_u);
  interface_down(game->texture->inter_d);
  glDisable(GL_TEXTURE_2D);
  glEndList();
}
