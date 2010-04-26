/*
** CallList.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Sat Apr 24 02:51:07 2010 Florian Chanioux
** Last update Mon Apr 26 09:56:10 2010 pierre1 boutbel
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

void		make_calllistes_picking(int name, GLuint texture)
{
  glNewList(name, GL_COMPILE);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glTranslatef(-CASE_H / 2, -CASE_W / 2, 0);
  glBindTexture(GL_TEXTURE_2D, texture);
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
  int		i;
  
  i = -1;
  while (++i < LVLMAX)
  {
    printf("loading totoro: %i\n", i);
    glNewList(TOTORO + i, GL_COMPILE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_NORMALIZE);
    draw_mesh(game->model.trantorien[i]);
    glDisable(GL_NORMALIZE);
    glDisable(GL_TEXTURE_2D);
    glEndList();
    printf("loading totoro: %i - done\n", i);
  }
}

void		make_calllistes_terrain(t_game *game)
{
  puts("load map");
  glNewList(TERRAIN, GL_COMPILE);
  glEnable(GL_TEXTURE_2D);
  around(game->map.h, game->map.w, game->texture->side);
  floor_render(game->map.h, game->map.w, game->texture->floor);
  glDisable(GL_TEXTURE_2D);
  glEndList();
  puts("load map - done");
  puts("load map_picking");
  glNewList(TERRAIN + 1, GL_COMPILE);
  glInitNames();
  picking_map(game);
  glEndList();
  puts("load map_picking - done");
}

void		make_calllistes_interface(t_game *game)
{
  puts("load interface");
  glNewList(INTER, GL_COMPILE);
  glEnable(GL_TEXTURE_2D);
  interface_up(game->texture->inter_u);
  interface_down(game->texture->inter_d);
  glDisable(GL_TEXTURE_2D);
  glEndList();
  puts("load interface - done");
  
}

void		make_calllistes_ressources(t_game *game)
{
  int		i;

  i = -1;
  while (++i < NBRESS)
  {
    printf("loading ressource : %i\n", i);
    glNewList(RESS + i, GL_COMPILE);
    if (i == 0)
      glTranslatef(0, 0, 1);
    else
      glTranslatef(0, 0, 0.5);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_NORMALIZE);
    draw_mesh(game->model.ressource[i]);
    glDisable(GL_NORMALIZE);
    glDisable(GL_TEXTURE_2D);
    glEndList();
    printf("loading ressource : %i - done\n", i);
  }
}
