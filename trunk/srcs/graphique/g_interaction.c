/*
** interaction.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Wed Apr 14 14:50:42 2010 Florian Chanioux
** Last update Sat Apr 24 04:51:38 2010 Florian Chanioux
*/


#include	<stdio.h>
#include	<stdlib.h>
#include	<math.h>
#include	<sys/select.h>

#ifdef		__APPLE__
# include	"SDL.h"
# include	"SDL_ttf.h"
# include	<GLUT/GLUT.h>
#else
# include	<SDL/SDL.h>
# include	<SDL/SDL_ttf.h>
# include	<GL/glu.h>
# include	<GL/gl.h>
#endif

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

t_event		event_type[]=
{
  {SDL_QUIT, exit_func},
  {SDL_MOUSEBUTTONDOWN, mouse_down},
  {SDL_MOUSEBUTTONUP, mouse_up},
  {SDL_MOUSEMOTION, mouse_move},
  {SDL_KEYDOWN, key_func},
  {0,0}
};

int interaction(t_game *game)
{
  int		i;

  if (SDL_PollEvent(&(game->event)))
  {
    i = -1;
    while (event_type[++i].type)
      if (game->event.type == event_type[i].type)
	return (event_type[i].func(game));
  }
  return(1);
}
