/*
** initgl.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr 16 18:32:28 2010 Florian Chanioux
** Last update Fri Apr 16 18:32:30 2010 Florian Chanioux
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

void		initAttributes()
{
  int		value;

  value = 1;
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, value);
}

void Init( void)
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
  GLfloat map2[4] = {0.0, 0.0, 0.0, 0.0};*/
  /*
  glFrontFace( GL_CCW);
  glDepthFunc( GL_LESS);
  glEnable( GL_DEPTH_TEST);
  glLightfv( GL_LIGHT0, GL_AMBIENT, ambient);
  glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuse);
  glLightfv( GL_LIGHT0, GL_POSITION, position);
  glLightModelfv( GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
  glLightModelfv( GL_LIGHT_MODEL_LOCAL_VIEWER, lmodel_localviewer);
  glEnable( GL_LIGHTING);
  glEnable( GL_LIGHT0);
  glMaterialfv( GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
  glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
  glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
  glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
*/
}

void init_fog()
{
  static float fog_color[4] = {0.5, 0.5, 0.5, 1.0};
  GLint fogmode;

  fogmode = GL_EXP;
  glEnable(GL_FOG);
  glFogi (GL_FOG_MODE, fogmode) ;
  glFogfv(GL_FOG_COLOR, fog_color) ;
  glFogf(GL_FOG_DENSITY, 0.01) ;
  glFogf(GL_FOG_START, 1.0) ;
  glFogf(GL_FOG_END, 5.0) ;
  glClearColor(0.5, 0.5, 0.5, 1.0);
}

void initGL()
{
  Init();
  init_fog();
  Reshape();
}
