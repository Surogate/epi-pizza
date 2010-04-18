/*
** mainloop.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr 16 18:24:06 2010 Florian Chanioux
** Last update Sun Apr 18 21:29:51 2010 Florian Chanioux
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

void mainloop(t_game *game)
{
  int exit;
  float Light1Pos[4] = {CAM_O_X, CAM_O_Y, CAM_O_Z, 1};

  exit = 1;
  SDL_EnableKeyRepeat(100, 20);
  make_calllistes(game);
  while (exit)
  {
    exit = interaction(game);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera();
    glLightfv(GL_LIGHT0, GL_POSITION, Light1Pos);
    draw_gl(game);
    glFlush();
    SDL_GL_SwapBuffers();
  }
}

