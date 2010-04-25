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

static void	draw_trantorien(t_player *player, int ref, GLenum mode)
{
  glPushMatrix();
  glTranslated(player->pos.x * CASE_W, player->pos.y * CASE_H, 0);
  glPushMatrix();
  glTranslated((CASE_H / 2), (CASE_W / 2), 0);
  glPushMatrix();
  glTranslated(0, 0, .01);
  glCallList(TEAM);
  glPopMatrix();
  glRotated((player->sens + 1) * 90, 0 ,0 ,1);
  if (mode == GL_SELECT)
    glPushName(player->id  + ref);
  glCallList(TOTORO + player->lv);
  if (mode == GL_SELECT)
    glPopName();
  glPopMatrix();
  glPopMatrix();
}

void		draw_mob(t_game *game, GLenum mode)
{
  int		ref;
  t_player *temp;

  ref = game->map.h * game->map.w;
  temp = game->player;
 while (temp)
 {
   draw_trantorien(temp, ref, mode);
   clic_mob(game, temp, ref);
   temp = temp->next_pg;
 }
  clic_map(game);
}