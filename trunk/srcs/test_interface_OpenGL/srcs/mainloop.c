/*
** mainloop.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr 16 18:24:06 2010 Florian Chanioux
** Last update Fri Apr 16 18:25:04 2010 Florian Chanioux
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
    done = interaction(game);
    glClear( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    make_calllistes();
    draw_map(move, game);
    draw_mob();
    SDL_GL_SwapBuffers();
  }
}

