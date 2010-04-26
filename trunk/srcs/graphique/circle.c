/*
** mainloop.c for  in /home/Ayden/Epitech/Projet/Zappy/srcs/test_interface_OpenGL
**
** Made by Florian Chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Fri Apr 16 18:24:06 2010 Florian Chanioux
** Last update Sat Apr 24 04:41:49 2010 Florian Chanioux
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
#include	"graphique/struct.h"
#include	"graphique/proto.h"

/*include for select*/
#include	<sys/time.h>
#include	<sys/types.h>
#include	<unistd.h>

int		str_pos(char *str, char to_find)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == to_find)
	return (i);
      i++;
    }
  return (-1);
}

 void		circle_read(int socket, t_circle *circle)
{
  circle->nb = 0;
  if (circle->buf[circle->pos -1] == '\n')
    circle->deb = circle->pos;
  circle->nb = read(socket, &circle->buf[circle->pos], BUFSIZE - circle->pos);
  if (circle->pos + circle->nb == BUFSIZE)
    {
      circle->pos = 0;
      circle->nb = read(socket, circle->buf, BUFSIZE - circle->pos);
      circle->retour = 1;
    }
  circle->pos += circle->nb;
}

char		*get_cmd(t_circle *circle)
{
  int		size;
  char		*res;

  res = 0;
  if (circle->buf[circle->pos - 1] == '\n')
    {
      size = str_pos(&circle->buf[circle->deb], '\n');
      if (size == -1)
	size = BUFSIZE - circle->deb;
      res = malloc(size + 2);
      strncpy(res, &circle->buf[circle->deb], size + 1);
      res[size + 1] = 0;
      if (circle->retour)
	{
	  circle->retour = 0;
	  res = realloc(res, size + circle->nb + 1);
	  strncat(res, circle->buf, circle->nb);
	  res[size + circle->nb] = 0;
	}
    }
  return (res);
}

void		init_circ(t_circle *circle)
{
  init_buff(circle->buf, BUFSIZE);
  circle->deb = 0;
  circle->pos = 0;
  circle->retour = 0;
}
