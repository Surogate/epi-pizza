/*
** initgl.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr 16 18:32:28 2010 Florian Chanioux
** Last update Sun Apr 18 15:47:18 2010 Florian Chanioux
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

void			initAttributes()
{
  int			value;

  value = 1;
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, value);
}

static void		Init(void)
{
/*
  static float ambient[]= {0.2, 0.2, 0.2, 1.0};
  static float diffuse[]= {1.0, 1.0, 1.0, 1.0};
  static float position[]= {0.0, 1.0, 0.0, 0.0};
  static float mat_shininess[]= {90.0};
  static float mat_specular[]= {0.8, 0.8, 0.8, 1.0};
  static float mat_diffuse[]= {0.46, 0.66, 0.795, 1.0};
  static float mat_ambient[]= {0.3, 0.4, 0.5, 1.0};
  static float lmodel_ambient[]= {0.4, 0.4, 0.4, 1.0};
  static float lmodel_localviewer[]= {0.0};
  GLfloat map1[4] = {0.0, 0.0, 0.0, 0.0};
  GLfloat map2[4] = {0.0, 0.0, 0.0, 0.0};
*/
}

static void		init_light(int light)
{
  static GLfloat	ambient[] = {0.15f, 0.15f, 0.15f, 1.0f};
  static GLfloat	diffuse[] = {0.5f, 0.5f, 0.5f, 1.0f};
  static GLfloat	light0_position [] = {0.0f, -10.0f, 0.0f, 0.0f};
  static GLfloat	specular_reflexion[] = {0.8f, 0.8f, 0.8f, 1.0f};
  static GLubyte	shiny_obj = 128;

  if (light)
  {
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
}

static void		init_fog(int fog)
{
  static float		fog_color[4] = {0.5, 0.5, 0.5, 1.0};
  GLint			fogmode;

  if (fog)
  {
    fogmode = GL_LINEAR;
    glEnable(GL_FOG);
    glFogi (GL_FOG_MODE, fogmode) ;
    glFogfv(GL_FOG_COLOR, fog_color) ;
    glFogf(GL_FOG_DENSITY, 0.3) ;
    glFogf(GL_FOG_START, 250.0) ;
    glFogf(GL_FOG_END, 450.0) ;
    glClearColor(0.5, 0.5, 0.5, 1.0);
  }
}

void initGL()
{
  Init();
  init_fog(1);
  init_light(1);
  Reshape();
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
}
