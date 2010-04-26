/*
** draw_interfaces.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Wed Apr 21 18:05:56 2010 Florian Chanioux
** Last update Mon Apr 26 10:10:20 2010 pierre1 boutbel
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

static void		show_info_val(t_player *player, char team)
{
  pushwrite();
  dwrite(team, 800, 170, RED);
  dwrite("LVL:", 856, 140, RED);
  dwrite_int(player->lv, 900, 140, GREEN);
  dwrite("nourriture:", 800, 120, RED);
  dwrite_int(player->inventaire[0], 900, 120, GREEN);
  dwrite("linemate:", 816, 105, RED);
  dwrite_int(player->inventaire[1], 900, 105, GREEN);
  dwrite("deraumere:", 808, 90, RED);
  dwrite_int(player->inventaire[2], 900, 90, GREEN);
  dwrite("sibur:", 840, 75, RED);
  dwrite_int(player->inventaire[3], 900, 75, GREEN);
  dwrite("phiras:", 832, 60, RED);
  dwrite_int(player->inventaire[4], 900, 60, GREEN);
  dwrite("thystame:", 816, 45, RED);
  dwrite_int(player->inventaire[5], 900, 45, GREEN);
  popwrite();
}

/*
  t_player *player;
  if (game->map.select_p > game->map.h * game->map.w)
  {
      show_info_val(player);
  }
*/
static void		show_info(t_game *game)
{
}

void		draw_interface(t_game *game)
{
  glDisable(GL_LIGHTING);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  glCallList(INTER);
  show_info(game);
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_LIGHTING);
}
