/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Mon Apr 26 10:12:35 2010 pierre1 boutbel
*/
#include	<sys/types.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include	<sys/select.h>

#ifdef		__APPLE__
#include	"SDL.h"
#include	<GLUT/GLUT.h>
#else
#include	<SDL/SDL.h>
#include	<GL/glu.h>
#include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"


int		key_w(t_game *game)
{
  game->info.pos.y += 10;
  return (1);
}

int		key_s(t_game *game)
{
  game->info.pos.y -= 10;
  return (1);
}

int		key_a(t_game *game)
{
  game->info.pos.x -= 10;
  return (1);
}

int		key_d(t_game *game)
{
  game->info.pos.x += 10;
  return (1);
}

int		key_space(t_game *game)
{
  game->info.pos.x = 0;
  game->info.pos.y = 0;
  game->map.rot = 0;
  game->video.cam[3] = CAM_Z;
  return (1);
}
