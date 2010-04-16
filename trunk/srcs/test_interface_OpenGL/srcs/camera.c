/*
** camera.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr 16 18:30:49 2010 Florian Chanioux
** Last update Fri Apr 16 18:33:23 2010 Florian Chanioux
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef __APPLE__
#include "SDL.h"
#include <GLUT/GLUT.h>
#else
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

#include	"define.h"
#include	"struct.h"
#include	"proto.h"

void Reshape()
{
  glViewport(0, 0, WIN_W, WIN_H);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0, (GLfloat)WIN_W / (GLfloat)WIN_H, 1, 300000.0);
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);
}

void camera( int cx, int cy, int cz, int px, int py, int pz, int *mvt)
{
  gluLookAt( mvt[0]+cx, mvt[1]+cy, cz,
	     mvt[0]+px, mvt[1]+py, pz,
	     0, 0, 1);
}
