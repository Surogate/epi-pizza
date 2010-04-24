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
/*
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

void		find_end2(int beg[2], int res[2], t_circle *circle)
{
  int		continuer;

  res[1] = beg[1];
  res[0] = beg[0];
  continuer = 1;
  while (continuer)
    {
      while (circle->buff[res[1]] && circle->buff[res[1]] != '\n' &&
	     res[1] < BUFSIZE)
	res[1]++;
      printf("res[0] : %d, res[1] : %d\n", res[0], res[1]);
      if (res[1] == BUFSIZE && circle->next)
	{
	  circle = circle->next;
	  res[0]++;
	}
      else
	{
	  if (circle->buff[res[1]] != '\n')
	    {
	      res[1] = beg[1];
	      res[0] = beg[0];
	    }
	  continuer = 0;
	}
    }
}

char		*extract_msg(t_serv *serv, int end[2], t_circle *circle)
{
  int		size;
  char		*res;

  size = end[1] - serv->beg[1]  + BUFSIZE * (end[0] - serv->beg[0]);
  printf("msg size : %d\n", size);
  res = xmalloc((size + 1) * sizeof(*res));
  init_buff(res, size + 1);
  strncpy(res, &circle->buff[serv->beg[1]], size);
  serv->beg[1] = end [1] + 1;
  serv->beg[0] = end[0];
  if (serv->beg[1] == circle->cur && !circle->buff[end[1] + 1])
    {
      serv->current = &serv->circ;
      serv->current->cur = 0;
      serv->beg[1] = 0;
      serv->beg[0] = 0;
      init_buff(serv->current->buff, BUFSIZE);
      printf("retour au debut du buffer\n");
    }
  return (res);
}

char		*circle_get(t_serv *serv)
{
  char		*res;
  t_circle	*circle;
  int		end[2];
  int		size;

  res = 0;
  circle = &serv->circ;
  while (circle->num != serv->beg[0])
    circle = circle->next;
  find_end2(serv->beg, end, circle);
  printf("beg : %d, %d\nend : %d, %d\n",
	 serv->beg[0], serv->beg[1], end[0], end[1]);
  if (serv->beg[0] != end[0] || serv->beg[1] != end[1])
    res = extract_msg(serv, end, circle);
  return (res);
}
*/
/*
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
*/
 /*
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
*/

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
