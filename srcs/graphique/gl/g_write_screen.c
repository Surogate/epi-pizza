/*
** g_write_screen.c for  in /home/Ayden/Epitech/Projet/Zappy
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Sat Apr 24 13:21:36 2010 Florian Chanioux
** Last update Sat Apr 24 13:22:36 2010 Florian Chanioux
*/

#include	<sys/select.h>
#include	<sys/time.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<math.h>

#ifdef		__APPLE__
#include	"SDL.h"
#include	"SDL_ttf.h"
#include	<GLUT/GLUT.h>
#else
#include	<SDL/SDL.h>
#include	<SDL/SDL_ttf.h>
#include	<GL/glu.h>
#include	<GL/gl.h>
# include	<GL/freeglut_std.h>
#endif

void DrawStr(const char *str)
{
  GLint i;

  i = -1;
  if(!str)
    return ;
  while(str[++i])
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
}
