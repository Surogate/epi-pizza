/*
** mainloop.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 18:24:06 2010 Florian Chanioux
** Last update Wed Apr 21 15:18:55 2010 Florian Chanioux
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
#include	"graphique/struct.h"
#include	"graphique/proto.h"

/*include for select*/
#include	<sys/time.h>
#include	<sys/types.h>
#include	<unistd.h>

t_circle	*new_circ(int num)
{
  t_circle	*circ;

  circ = xmalloc(sizeof(*circ));
  circ->next = 0;
  circ->num = num;
  return (circ);
}

void		init_circ(t_game *game)
{
  init_buff(game->serv.circ.buff, BUFSIZE);
  game->serv.beg[0] = 0;
  game->serv.beg[1] = 0;
  game->serv.circ.cur = 0;
  game->serv.circ.num = 0;
  game->serv.circ.next = 0;
  game->serv.current = &game->serv.circ;
}

int		find_end(char *msg, int n)
{
  int		i;

  i = 0;
  while (msg[i] && msg[i] != '\n' && i < n)
    i++;
  return (i);
}

char		*circle_get(t_serv *serv)
{
  char		*res;
  t_circle	*circle;
  int		size;

  res = 0;
  circle = &serv->circ;
  while (circle->num != serv->beg[0])
    circle = circle->next;
  size = find_end(&circle->buff[serv->beg[1]], BUFSIZE - serv->beg[1]);
  if (size)
    {
      res = malloc((size + 1) * sizeof(*res));
      res[size] = 0;
      strncpy(res, &circle->buff[serv->beg[1]], size);
      serv->beg[1] += size + 1;
      if (serv->beg[1] == circle->cur)
	{
	  serv->current = &serv->circ;
	  serv->current->cur = 0;
	  serv->beg[1] = 0;
	  serv->beg[0] = 0;
	  init_buff(serv->current->buff, BUFSIZE);
	  printf("retour au debut du buffer\n");
	}
    }
  return (res);
}

void		circle_read(t_serv *serv)
{
  int		read_return;
  int		pos;

  pos = serv->current->cur;
  read_return = read(serv->socket, &(serv->current->buff[pos]), BUFSIZE - pos);
  if (read_return < 1)
    {
      perror("read fail");
      exit(EXIT_FAILURE);
    }
  serv->current->cur += read_return;
  if (serv->current->cur == BUFSIZE)
    {
      if (!serv->current->next)
	serv->current->next = new_circ(serv->current->num + 1);
      serv->current = serv->current->next;
      serv->current->cur = 0;
      init_buff(serv->current->buff, BUFSIZE);
    }
}
