/*
** clic_mode.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Thu Apr 22 18:56:29 2010 Florian Chanioux
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

void		clic_mob(t_game *game, t_player *player, int ref)
{
  int		x;
  int		y;

  if (game->map.select_p - ref == player->id)
  {
    x = player->pos.x;
    y = player->pos.y;
    glPushMatrix();
    glTranslatef(x * CASE_H, y * CASE_W, 0.2);
    clic_render(PSELECT);
    glPopMatrix();
  }
}

void		clic_map(t_game *game)
{
  int		x;
  int		y;

  if (game->map.select_c >= 0)
  {
    x = game->map.select_c % game->map.w;
    y = game->map.select_c / game->map.w;
    glPushMatrix();
    glTranslatef(x * CASE_H, y * CASE_W, 0.2);
    clic_render(PICKING);
    glPopMatrix();
  }
}
