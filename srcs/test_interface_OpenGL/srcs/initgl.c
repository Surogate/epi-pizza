/*
** initgl.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr 16 18:32:28 2010 Florian Chanioux
** Last update Mon Apr 19 17:33:01 2010 Florian Chanioux
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

#include "define.h"
#include "struct.h"
#include "proto.h"

void		init_doublebuffer()
{
  int value;

  value = 1;
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, value);
}

static void		init_light(int light)
{
  static GLfloat	ambient[] = {0.15f, 0.15f, 0.15f, 1.0f};
  static GLfloat	diffuse[] = {0.5f, 0.5f, 0.5f, 1.0f};
  static GLfloat	light0_position [] = {0, 0, 100, 0.0f};
  static GLfloat	specular_reflexion[] = {0.8f, 0.8f, 0.8f, 1.0f};
  static GLubyte	shiny_obj = 128;

  if (light)
  {
    puts("LIGHT ON");
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_reflexion);
    glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, shiny_obj);
    glEnable(GL_NORMALIZE);
  }
  else
    puts("LIGHT OFF");
}

static void		init_fog(int fog, GLint fogmode)
{
  static float		fog_color[4] = {0, 0, 0, 1.0};

  if (fog == 1)
  {
    puts("FOG ON");
    glEnable(GL_FOG);
    glFogi (GL_FOG_MODE, fogmode) ;
    glFogfv(GL_FOG_COLOR, fog_color) ;
    glFogf(GL_FOG_DENSITY, 0.3) ;
    glFogf(GL_FOG_START, 580.0) ;
    glFogf(GL_FOG_END, 700.0) ;
    glClearColor(0,0,0,1);
  }
  else
    puts("FOG OFF");
}

void initGL(t_game *game)
{
  init_doublebuffer();
  init_fog(game->video.fog, GL_LINEAR);
  init_light(game->video.light);
  reshape();
  glEnable(GL_DEPTH_TEST);
}
