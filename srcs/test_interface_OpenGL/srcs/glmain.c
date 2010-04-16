/*
** glmain.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Wed Apr 14 14:36:35 2010 Florian Chanioux
** Last update Thu Apr 15 23:31:29 2010 Florian Chanioux
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

#include	"../includes/define.h"
#include	"../includes/struct.h"
#include	"../includes/proto.h"

#define WIDTH 800
#define HEIGTH 600

void		printAttributes()
{
  int		nAttr;
  int		i;
  int		attr[] = {SDL_GL_RED_SIZE, SDL_GL_BLUE_SIZE,
			  SDL_GL_GREEN_SIZE, SDL_GL_ALPHA_SIZE,
			  SDL_GL_BUFFER_SIZE, SDL_GL_DEPTH_SIZE };
  char		*desc[] = {"Red size: %d bits\n",
			   "Blue size: %d bits\n",
			   "Green size: %d bits\n",
			   "Alpha size: %d bits\n",
			   "Color buffer size: %d bits\n",
			   "Depth bufer size: %d bits\n"};
  int		value;

  nAttr = sizeof(attr) / sizeof(int);
  i = -1;
  while (++i < nAttr)
  {
    SDL_GL_GetAttribute(attr[i], &value);
    printf(desc[i], value);
  }
}
void		initAttributes()
{
  int		value;

  value = 1;
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, value);
}

void Init( void)
{

  static float ambient[]= {0.2, 0.2, 0.2, 1.0};
  static float diffuse[]= {1.0, 1.0, 1.0, 1.0};
  static float position[]= {0.0, 1.0, 0.0, 0.0};
  static float mat_shininess[]= {90.0};
  static float mat_specular[]= {0.8, 0.8, 0.8, 1.0};
  static float mat_diffuse[]= {0.46, 0.66, 0.795, 1.0};
  static float mat_ambient[]= {0.3, 0.4, 0.5, 1.0};
  static float lmodel_ambient[]= {0.4, 0.4, 0.4, 1.0};
  static float lmodel_localviewer[]= {0.0};
  /*GLfloat map1[4] = {0.0, 0.0, 0.0, 0.0};
    GLfloat map2[4] = {0.0, 0.0, 0.0, 0.0};*/
  static float fog_color[]= {0.0, 0.5, 0.9, 1.0};
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
  glEnable( GL_FOG);
  glFogi(GL_FOG_MODE, GL_EXP);
  glFogf(GL_FOG_DENSITY, 0.0000025);
  glFogfv(GL_FOG_COLOR, fog_color);
  glClearColor(0.0, 0.5, 0.9, 1.0);

}

void Reshape( int w, int h)
{
  glViewport( 0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective( 70.0, (GLfloat) w/ (GLfloat) h, 1, 300000.0);
  glMatrixMode( GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);  
}

void initGL()
{
  Init();
  Reshape(WIDTH, HEIGTH);
}


void camera( int cx, int cy, int cz, int px, int py, int pz, int *mvt)
{
  gluLookAt( mvt[0]+cx, mvt[1]+cy, cz,
	     mvt[0]+px, mvt[1]+py, pz,
	     0, 0, 1);
}

void draw_map(int *table, t_game *game)
{
  int cx, cy, cz, px, py, pz;
  int	h;
  int	w;

  h = game->info.pos.y / CASE_H + game->info.pos.y % CASE_H;
  w = game->info.pos.x / CASE_W + game->info.pos.x % CASE_W;
  cx = h;
  cy = w;
  cz = 70;
  px = h + CASE_H * 2;
  py = w + CASE_W * 2;
  pz = 0;
  glMatrixMode( GL_MODELVIEW);
  glLoadIdentity();
  camera(cx, cy, cz, px, py, pz, table);
  /*
    
    code map a faire
  */
  h = -2;
  while (++h < MAP_CH)
  {
    w = -2;
    while (++w < MAP_CW)
    {
      glBegin(GL_QUADS);
      glColor3ub(255,255, 255);
      glVertex2d(w * CASE_W, h * CASE_H); /*(0, 0)*/
      glColor3ub(0, 0, 255);
      glVertex2d(w *  CASE_W, h * CASE_H + CASE_H);/* (0, 1)*/
      glColor3ub(255,255, 255);
      glVertex2d(w *  CASE_W + CASE_W, h * CASE_H + CASE_H);/*(1, 1)*/
      glColor3ub(0, 0, 0);
      glVertex2d(w *  CASE_W + CASE_W, h * CASE_H);/*(1, 0)*/
      glEnd();
    }
  }
  
  glFlush();
}

void draw_mob()
{
  /*
    code  POUR LES MOB
  */
}

void mainloop(t_game *game)
{
  int move[7] = { 0, 0, 0, 0, 0, 0, 0};
  int done = 0;
  int fps = 25;
  int delay= 1000 / fps;
  int thenTicks = -1;
  int nowTicks;

  SDL_EnableKeyRepeat(100, 20);
  while (!done)
  {
    done = interaction(move, game);
    glClear( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT) ;
    draw_map(move, game);
    draw_mob();
    SDL_GL_SwapBuffers();
  }
}
