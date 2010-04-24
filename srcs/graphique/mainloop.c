/*
** mainloop.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 18:24:06 2010 Florian Chanioux
** Last update Sun Apr 25 01:50:27 2010 Florian Chanioux
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

#include	"graphique/3dsloader.h"
#include	"graphique/define.h"
#include	"s_cbuf.h"
#include	"graphique/struct.h"
#include	"graphique/proto.h"

/*include for select*/
#include	<sys/time.h>
#include	<sys/types.h>
#include	<unistd.h>

void		init_buff(char *buff, int size)
{
  int		i;

  i = 0;
  while (i < size)
    buff[i++] = 0;
}

int		check_next_end(char *str)
{
  int		i;

  i = 0;
  while (str[i] && str[i] != '\n')
    i++;
  if (!str[i])
    return (0);
  else
    return (i);
}

void		my_recv(t_game *game)
{
  char		*msg;
  char		**temp;

  cbuf_write(game->serv.cbuf, game->serv.socket);
  do
    {
      msg = cbuf_read(game->serv.cbuf, check_next_end);
      if (msg)
	{
	  printf("msg : %s\n", msg);
	  temp = split(msg, ' ');
	  printf("func : %s\n", temp[0]);
	  traitement(game, temp);
	  if (!strncmp(temp[0], "msz", 3))
	    {
	      printf("taille de la map : %d, %d\n", game->map.h, game->map.w);
	      create_map(game);
	      printf("fin init map\n");
	    }
	}
    }while (msg);
}

void		search_msg(t_game *game)
{
  int		ready;

  FD_ZERO(&game->serv.fd_read);
  FD_ZERO(&game->serv.fd_write);
  FD_SET(game->serv.socket, &game->serv.fd_read);
  FD_SET(game->serv.socket, &game->serv.fd_write);
  ready = select(game->serv.socket + 1, &game->serv.fd_read,
		 &game->serv.fd_write, NULL, NULL);
  if (ready > 0)
    {
      if (FD_ISSET(game->serv.socket, &game->serv.fd_read))
	{
	  my_recv(game);
	}
    }
  if (ready < 0)
    {
      printf("serveur has gone away...\n");
      exit(EXIT_FAILURE);
    }
}

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
  SDL_EnableKeyRepeat(100, 20);
  i = 0;
  while (exit)
  {
    exit = interaction(game);
    if (i % 3)
      {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	camera(game);
	draw_interface(game);
	draw_gl(game, GL_RENDER);
	/* 	  timedelay(); */
	glFlush();
	SDL_GL_SwapBuffers();
      }
    i++;
  }
}

