/*
** camera.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 18:30:49 2010 Florian Chanioux
** Last update Tue Apr 20 14:30:56 2010 Florian Chanioux
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

void		reshape()
{
  glViewport(0, 0, WIN_W, WIN_H);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(WIN_FOC, (GLfloat)(WIN_W / WIN_H), WIN_NEAR, WIN_FAR);
}

void		camera()
{
  int x;
  int y;
  int z;
  int px;
  int py;
  int pz;

  px = CAM_O_X;
  py = CAM_O_Y;
  pz = CAM_O_Z;
  x = px;
  y = py + 200;
  z = CAM_Z;
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(x, y, z,
	    px, py, pz,
	    0, 0, 1);
}
