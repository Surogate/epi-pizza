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
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include	<sys/select.h>

#ifdef		__APPLE__
#include	"SDL.h"
#include	"SDL_ttf.h"
#include	<GLUT/GLUT.h>
#else
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	<GL/glut.h>
#include	<GL/glu.h>
#include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

static int	load_textureBMP(const char *path, unsigned int *textureId)
{
  SDL_Surface*	TextureSurface = NULL;
  TextureSurface = SDL_LoadBMP(path);

  if (TextureSurface != NULL)
  {
    glGenTextures(1, textureId);
    glBindTexture(GL_TEXTURE_2D, *textureId);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TextureSurface->w,
		 TextureSurface->h, 0, GL_BGR, GL_UNSIGNED_BYTE,
		 TextureSurface->pixels);
    SDL_FreeSurface(TextureSurface);
    return (1);
  }
  return (0);
}

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
      ress->scale[0] = 5.0f;
      ress->scale[1] = 5.0f;
      ress->scale[2] = 8.0f;
      ress->id_texture = loadtexture(path);
      if (i == 0)
	Load3DS(ress,"3DS/Tore.3ds");
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
      trantorien = malloc(sizeof(obj_type));
      trantorien->scale[0] = (5.0f) + i;
      trantorien->scale[1] = (5.0f) + i;
      trantorien->scale[2] = (8.0f) + i;
      /*load_textureBMP("3DS/totoro3.bmp", &trantorien->id_texture);*/
      trantorien->id_texture = loadtexture(path);
      Load3DS(trantorien,"3DS/totoro.3ds");
      game->model.trantorien[i] = trantorien;
    }
  free(path);
  init_3dsmodel_ress(game);
}

void		init_texture(t_game *game)
{
  if (game->video.text)
  {
    puts("TEXTURE ON");
    game->texture = malloc(sizeof(t_texture));
    game->texture->team = loadtexture("images/team-sphere.png");
    game->texture->inter_d = loadtexture("images/interface_down.png");
    game->texture->inter_u = loadtexture("images/interface_up.png");
    game->texture->floor = loadtexture("images/lawn.jpg");
    game->texture->side = loadtexture("images/side.jpg");
    game->texture->floor_s = loadtexture("images/Circle.png");
  }
  else
    puts("TEXTURE OFF");
}

void		init_video(t_game *game)
{
  game->video.text = 1;
  game->video.fog = 1;
  game->video.light = 1;
  game->video.aliasing = 1;
}
