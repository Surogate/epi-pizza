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

void		my_recv(t_game *game)
{
  char		*msg;
  char		**temp;

  printf("\033[31mmsg recv!\033[00m\n");
  cbuf_write(game->serv.cbuf, game->serv.socket);
  do
    {
      msg = cbuf_read(game->serv.cbuf, check_next_end);
      printf("Msg : %p\n", msg);
      if (msg)
	{
	  temp = split(msg, ' ');
	  printf("\033[31mFUNC : %s\033[00m\n", temp[0]);
	  traitement(game, temp);
	  if (!strncmp(temp[0], "msz", 3))
	    {
	      printf("taille de la map : %d, %d\n", game->map.h, game->map.w);
	      create_map(game);
	      printf("fin init map\n");
	    }
	  free_2d_tab(temp);
	}
    } while (msg);
  printf("test\n");
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
	my_recv(game);
    }
  if (ready < 0)
    {
      printf("serveur has gone away...\n");
      exit(EXIT_FAILURE);
    }
}
