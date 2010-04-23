/*
** clic_mode.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
** 
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Thu Apr 22 18:56:29 2010 Florian Chanioux
** Last update Thu Apr 22 19:22:49 2010 Florian Chanioux
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
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

#include	"3dsloader.h"
#include	"define.h"
#include	"struct.h"
#include	"proto.h"

void		clic_mob(t_game *game)
{
  int		x;
  int		y;

  if (game->map.h * game->map.w <= game->map.select)
  {
    x = game->map.select % game->map.w;
    y = game->map.select / game->map.w;
    glPushMatrix();
    glTranslatef(x * CASE_H, y * CASE_W, 0.1);
    clic_render(game->texture->floor_s);
    glPopMatrix();
  }
}

void		clic_map(t_game *game)
{
  int		x;
  int		y;

  if ((game->map.h * game->map.w) > game->map.select)
  {
    x = game->map.select % game->map.w;
    y = game->map.select / game->map.w;
    glPushMatrix();
    glTranslatef(x * CASE_H, y * CASE_W, 0.1);
    clic_render(game->texture->floor_s);
    glPopMatrix();
  }
}
