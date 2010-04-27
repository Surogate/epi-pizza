/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Sat Apr 24 05:19:05 2010 Florian Chanioux
*/

#include	<sys/types.h>
#include	<sys/time.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include	<sys/select.h>
#include	<time.h>

#ifdef		__APPLE__
#include	"SDL.h"
#include	<GLUT/GLUT.h>
#else
#include	<SDL/SDL.h>
#include	<GL/glut.h>
#include	<GL/glu.h>
#include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"
#include	"xfunc.h"

void		init_3dsmodel_ress(t_game *game)
{
  obj_type	*ress;
  char		*path;
  int		i;

  i = -1;
  path = strdup("3DS/ressX.bmp");
  while (++i != 7)
    {
      path[8] = i + '1';
      ress = malloc(sizeof(obj_type));
      ress->scale[0] = 4.0f;
      ress->scale[1] = 4.0f;
      ress->scale[2] = 4.0f;
      ress->id_texture = loadtexture(path);
      if (i == 0)
	Load3DS(ress,"3DS/sphere.3ds");
      else
	Load3DS(ress,"3DS/diamond.3ds");
      game->model.ressource[i] = ress;
    }
  free(path);
}

void		init_3dsmodel(t_game *game)
{
  obj_type	*trantorien;
  char		*path;
  int		i;

  i = -1;
  path = strdup("3DS/totoroX.bmp");
  while (++i != 8)
    {
      path[10] = i + '1';
      trantorien = xmalloc(sizeof(obj_type));
      trantorien->scale[0] = (5.0f) + i;
      trantorien->scale[1] = (5.0f) + i;
      trantorien->scale[2] = (8.0f) + i;
      trantorien->id_texture = loadtexture(path);
      Load3DS(trantorien,"3DS/totoro.3ds");
      game->model.trantorien[i] = trantorien;
    }
  free(path);
  game->model.eggs = xmalloc(sizeof(obj_type));
  game->model.eggs->scale[0] = 3.0f;
  game->model.eggs->scale[1] = 3.0f;
  game->model.eggs->scale[2] = 8.0f;
  game->model.eggs->id_texture = loadtexture("3DS/egg.bmp");
  Load3DS(game->model.eggs, "3DS/sphere.3ds");
  init_3dsmodel_ress(game);
}

void		init_texture(t_game *game)
{
  if (game->video.text)
  {
    puts("TEXTURE ON");
    srandom(time(NULL));
    game->texture = xmalloc(sizeof(t_texture));
    game->texture->team = loadtexture("images/team-sphere.png");
    game->texture->inter_d = loadtexture("images/interface_down.png");
    game->texture->inter_u = loadtexture("images/interface_up.png");
    game->texture->floor = loadtexture("images/lawn.jpg");
    game->texture->side = loadtexture("images/side.jpg");
    game->texture->floor_s = loadtexture("images/Circle.png");
    game->texture->select = loadtexture("images/select_pl.png");
    game->texture->faq = loadtexture("images/faq.bmp");
    game->texture->faq2= loadtexture("images/faq2.jpg");
    game->texture->legend= loadtexture("images/legend.jpg");
    game->texture->bonjour = loadtexture("images/bnojour.jpg");
    game->texture->ending = loadtexture("images/ending.jpg");
    if (random() % 2)
      game->texture->intro = loadtexture("images/totoro_intro1.jpg");
    else
      game->texture->intro = loadtexture("images/totoro_intro2.jpg");
  }
  else
    puts("TEXTURE OFF");
}

void		init_video(t_game *game)
{
  game->video.text = 1;
  game->video.fog = 0;
  game->video.light = 1;
  game->video.aliasing = 0;
}


void		init_CallList(t_game *game)
{
  make_calllistes_trantorien(game);
  make_calllistes_picking(TEAM, game->texture->team);
  make_calllistes_picking(PICKING, game->texture->floor_s);
  make_calllistes_picking(PSELECT, game->texture->select);
  make_calllistes_interface(game);
  make_calllistes_terrain(game);
  make_calllistes_ressources(game);
}

