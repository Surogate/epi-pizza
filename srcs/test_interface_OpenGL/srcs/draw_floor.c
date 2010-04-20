/*
** draw_floor.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Mon Apr 19 13:15:43 2010 Florian Chanioux
** Last update Tue Apr 20 14:31:28 2010 Florian Chanioux
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

#include "3dsloader.h"
#include "define.h"
#include "struct.h"
#include "proto.h"


void		floor_with_t(t_game *game, int x, int y)
{
  glBindTexture(GL_TEXTURE_2D, game->texture.floor);
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0);
  glVertex2d(x * CASE_W, y * CASE_H);
  glTexCoord2d(1, 0);
  glVertex2d(x * CASE_W, y * CASE_H + CASE_H);
  glTexCoord2d(1, 1);
  glVertex2d(x * CASE_W + CASE_W, y * CASE_H + CASE_H);
  glTexCoord2d(0, 1);
  glVertex2d(x * CASE_W + CASE_W, y * CASE_H);
  glEnd();
}

void		floor_without_t(int x, int y)
{
  glBegin(GL_QUADS);
  glColor3ub(255, 255, 255);
  glVertex2d(x * CASE_W, y * CASE_H);
  glColor3ub(255, 255, 255);
  glVertex2d(x * CASE_W, y * CASE_H + CASE_H);
  glColor3ub(255, 255, 255);
  glVertex2d(x * CASE_W + CASE_W, y * CASE_H + CASE_H);
  glColor3ub(255, 255, 255);
  glVertex2d(x * CASE_W + CASE_W, y * CASE_H);
  glEnd();
}


void		side_with_t(t_game *game, int x, int y)
{
  glBindTexture(GL_TEXTURE_2D, game->texture.side);
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0);
  glVertex3d(x * CASE_W, y * CASE_H, 0);
  glTexCoord2d(1, 0);
  glVertex3d(x * CASE_W + CASE_W, y * CASE_H, 0);
  glTexCoord2d(1, 1);
  glVertex3d(x * CASE_W + CASE_W, y * CASE_H, -10);
  glTexCoord2d(0, 1);
  glVertex3d(x * CASE_W, y * CASE_H, -10);
  glEnd();
}

void		side_without_t(int x, int y)
{
  glBegin(GL_QUADS);
  glColor3ub(255,255, 255);
  glVertex3d(x * CASE_W, 0, 0);
  glColor3ub(255,255, 255);
  glVertex3d(x * CASE_W + CASE_W, y * CASE_H, 0);
  glColor3ub(255,255, 255);
  glVertex3d(x * CASE_W + CASE_W, y * CASE_H, -10);
  glColor3ub(255,255, 255);
  glVertex3d(x * CASE_W, 0, -10);
  glEnd();
}
