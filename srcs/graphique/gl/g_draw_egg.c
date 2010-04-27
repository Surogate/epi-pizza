/*
** draw_mob.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 17:10:54 2010 Florian Chanioux
** Last update Mon Apr 26 09:57:33 2010 pierre1 boutbel
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

static void	draw_eggs_onmap(t_egg *player)
{
  glPushMatrix();
  glTranslated(player->pos.x * CASE_W, player->pos.y * CASE_H, 0);
  glPushMatrix();
  glTranslated((CASE_H / 2), (CASE_W / 2) , 6);
  glCallList(EGG);
  glPopMatrix();
  glPopMatrix();
}

void		draw_eggs(t_game *game)
{
  t_egg		*temp;

  temp = game->egg;
  while (temp)
    {
      draw_eggs_onmap(temp);
      temp = temp->next;
    }
}
