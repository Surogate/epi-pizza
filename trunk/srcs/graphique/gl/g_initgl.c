/*
** initgl.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 18:32:28 2010 Florian Chanioux
** Last update Mon Apr 26 10:05:06 2010 pierre1 boutbel
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>
#include	<sys/select.h>

#ifdef		__APPLE__
# include	"SDL.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

void		init_doublebuffer()
{
  int value;

  value = 16;
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, value);

  value = 1;
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, value);
}

static void	init_light_suite()
{
  static float ambient[] = {0.2, 0.2, 0.2, 1.0};
  static float diffuse[] = {1.0, 1.0, 1.0, 1.0};
  static float position[] = {0.0, 10.0, 0.0, 0.0};
  static float mat_shininess[] = {90.0};
  static float mat_specular[] = {0.8, 0.8, 0.8, 1.0};
  static float mat_diffuse[] = {0.46, 0.66, 0.795, 1.0};
  static float mat_ambient[] = {0.3, 0.4, 0.5, 1.0};
  static float lmodel_ambient[] = {0.4, 0.4, 0.4, 1.0};
  static float lmodel_localviewer[] = {0.0};

  glFrontFace(GL_CCW);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, position);
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
  glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, lmodel_localviewer);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
  
}

static void	init_light(int light)
{
  if (light)
  {
    puts("LIGHT ON");
    init_light_suite();
  }
  else
    puts("LIGHT OFF");
}

void		initGL(t_game *game)
{
  init_doublebuffer();
  init_aliasing(game->video.aliasing);
  init_light(game->video.light);
  init_fog(game->video.fog, GL_LINEAR);
  init_camera(game);
  reshape();
  glEnable(GL_DEPTH_TEST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
}
