/*
** camera.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr 16 18:30:49 2010 Florian Chanioux
** Last update Fri Apr 16 20:08:20 2010 Florian Chanioux
*/

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
  gluPerspective(70.0, (GLfloat)(WIN_W / WIN_H), 1, 1000.0);
}

void camera(t_game *game)
{
  int x;
  int y;
  int z;
  int px;
  int py;
  int pz;

  x = game->info.pos.y / CASE_H + game->info.pos.y % CASE_H;
  y = game->info.pos.x / CASE_W + game->info.pos.x % CASE_W;
  z = 80;
  px = x + CASE_H * 2;
  py = y + CASE_W * 2;
  pz = 0;
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(x, y, z, px, py, pz, 0, 0, 1);
}
