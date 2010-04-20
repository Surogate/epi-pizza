/*
** window.c for lemipc in /u/all/pierro_a/cu/rendu/c/lemipc/screen
**
** Made by frederic1 pierronnet
** Login   <pierro_a@epitech.net>
**
** Started on  Sun Apr  4 17:38:25 2010 frederic1 pierronnet
** Last update Wed Apr 21 00:33:54 2010 Florian Chanioux
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef __APPLE__
#include "SDL.h"
#include "SDL_ttf.h"
#include <GLUT/GLUT.h>
#else
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

#include "3dsloader.h"
#include "define.h"
#include "struct.h"
#include "proto.h"

void		init_3dsmodel(t_game *game)
{
  Load3DS(&(game->model.trantorien),"3DS/totoro.3ds");
}

void		init_texture(t_game *game)
{
  if (game->video.text)
  {
    puts("TEXTURE ON");
    game->texture.floor = loadtexture("images/lawn.jpg", 0);
    game->texture.side = loadtexture("images/side.jpg", 0);
  }
  else
    puts("TEXTURE OFF");
}

void		init_video(t_game *game)
{
  game->video.text = 0;
  game->video.fog = 0;
  game->video.light = 0;
  game->video.aliasing = 0;
}
