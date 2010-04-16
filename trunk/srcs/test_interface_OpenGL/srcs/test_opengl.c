/*
** test_opengl.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Fri Apr 16 17:12:18 2010 Florian Chanioux
** Last update Fri Apr 16 17:12:32 2010 Florian Chanioux
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
