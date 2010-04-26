/*
** mainloop.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 18:24:06 2010 Florian Chanioux
** Last update Sun Apr 25 02:18:40 2010 Florian Chanioux
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
#include	"cbuf_io.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"


/*include for select*/
#include	<sys/time.h>
#include	<sys/types.h>
#include	<unistd.h>

void		timedelay()
{
  static int	delay = 1000/ FPS;
  static int	thenTicks = -1;
  static int	nowTicks;

  nowTicks = SDL_GetTicks();
  delay += (1000 / FPS - (nowTicks - thenTicks));
  thenTicks = nowTicks;
  if (delay < 0)
    delay = 1000 / FPS;
  SDL_Delay(delay);
}

void		mainloop(t_game *game)
{
  int		exit;
  int		i;

  exit = 1;
  i = 0;
  SDL_EnableKeyRepeat(100, 20);
  while (exit)
  {
    search_msg(game);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera(game);
    draw_interface(game);
    draw_gl(game, GL_RENDER);
    glFlush();
    SDL_GL_SwapBuffers(); 
    exit = interaction(game);
  }
}

