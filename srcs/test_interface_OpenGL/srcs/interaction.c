/*
** interaction.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Wed Apr 14 14:50:42 2010 Florian Chanioux
** Last update Fri Apr 16 16:00:27 2010 Florian Chanioux
*/


#include <stdio.h>
#include <stdlib.h>
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

t_event		event_type[]=
{
  {SDL_QUIT, exit_func},
  {SDL_MOUSEBUTTONDOWN, mouse_down},
  {SDL_MOUSEBUTTONUP, mouse_up},
  {SDL_MOUSEMOTION, mouse_move},
  {SDL_KEYDOWN, key_func},
  {0,0}
};


int interaction(int * move, t_game *game)
{
  int		i;

  /* Check for events */
  if (SDL_PollEvent(&(game->event)))
  {
    i = 0;
    while (event_type[i].type)
    {
      if (game->event.type == event_type[i].type)
	event_type[i].func(game);
      i++;
    }
  }
  return(0);
}
