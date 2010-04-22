/*
** camera.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 18:30:49 2010 Florian Chanioux
** Last update Thu Apr 22 15:15:16 2010 Florian Chanioux
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

#include	"3dsloader.h"
#include	"define.h"
#include	"struct.h"
#include	"proto.h"

void		init_camera(t_game *game)
{
  game->video.cam[0] = (game->map.h * CASE_W) / 2;
  game->video.cam[1] = (game->map.h * CASE_H) / 2;
  game->video.cam[2] = 0;
  game->video.cam[3] = CAM_Z;
}

void		reshape()
{
  glViewport(0, 0, WIN_W, WIN_H);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(WIN_FOC, (GLfloat)(WIN_W / WIN_H), WIN_NEAR, WIN_FAR);
}

void		camera(t_game *game)
{
  int x;
  int y;
  int z;
  int px;
  int py;
  int pz;

  px = game->video.cam[0];
  py =  game->video.cam[1];
  pz = game->video.cam[2];
  x = px;
  y = py - game->video.cam[3];
  z = game->video.cam[3];
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(x, y, z, px, py, pz, 0, 0, 1);
}
