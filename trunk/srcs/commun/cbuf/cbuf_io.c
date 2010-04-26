/*
** cirbuf_io.c for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Mar 10 15:05:42 2010 francois1 ancel
** Last update Mon Mar 22 06:27:06 2010 lucas1 santamaria
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<errno.h>
#include	<sys/socket.h>
#include	<sys/types.h>
#include	"cbuf_define.h"
#include	"s_cbuf.h"
#include	"cbuf_debug.h"
#include	"cbuf_io.h"
#include	"xfunc.h"

char		*cbuf_read(t_cbuf *cbuf, int (*check_read)())
{
  static char	result[CBUFSIZ];
  int		cmd;

  memset(result, 0, CBUFSIZ);
  if (cbuf->use <= 0)
    {
      cbuf->use = 0;
      return (NULL);
    }
  if (cbuf->buf[cbuf->cons] == END_CHAR)
    ++(cbuf->cons);
  if (cbuf->prod > cbuf->cons)
    strncpy(result, cbuf->buf + cbuf->cons, cbuf->prod - cbuf->cons);
  else
    {
      strncpy(result, cbuf->buf + cbuf->cons, CBUFSIZ - cbuf->cons);
      strncpy(result + (CBUFSIZ - cbuf->cons), cbuf->buf, cbuf->prod);
    }
  if ((cmd = check_read(result)) > 0)
    {
      printf("======== read =======\nlen : %i\nuse : %i\ncons : %i\n", cmd, cbuf->use, cbuf->cons);
      cbuf->cons = (cbuf->cons + cmd + 1) % CBUFSIZ;
      cbuf->use -= (cmd - 1);
      result[cmd] = '\0';
      /* memset(&cbuf->buf[cbuf->cons - cmd], 0 , cmd); */
      printf("======== readed =======\nlen : %i\nuse : %i\ncons : %i\n",
	     cmd, cbuf->use, cbuf->cons);
      printf("len : %i\nresult : %s\n", cmd, result);
      return (result);
    }
  return (NULL);
}

int		sock_write(int sock, char *from)
{
  int		result;
  unsigned int	total;

  total = 0;
  if (!from)
    return (EXIT_SUCCESS);
  while (total < strlen(from))
    {
      result = send(sock, from + total, xstrlen(from + total), 0);
      if (result < 0)
	{
	  perror("sock send");
	  return (EXIT_FAILURE);
	}
      total += result;
    }
  return (EXIT_SUCCESS);
}

int		sock_read(int sock, char *to, int limit)
{
  int		result;

  result = recv(sock, to, limit, 0);
  if (result < 0)
    perror("sock recv");
  return (result);
}

int		cbuf_write(t_cbuf *cbuf, int sock)
{
  int		total;

  if (cbuf->use > CBUFSIZ)
    cbuf_init(cbuf);
  total = 0;
  printf("====== write ======\ntotal : %i\nuse : %i\nprod : %i\n",total, cbuf->use, cbuf->prod);
  if (cbuf->prod >= cbuf->cons)
    {
      total = sock_read(sock, cbuf->buf + cbuf->prod, CBUFSIZ - cbuf->prod);
      if (total == -1)
	return (EXIT_FAILURE);
      cbuf->prod = (cbuf->prod + total) % (CBUFSIZ);
      cbuf->use += total;
    }
  if (cbuf->prod < cbuf->cons)
    {
      total += sock_read(sock, cbuf->buf + cbuf->prod, cbuf->cons - cbuf->prod);
      if (total == -1)
	return (EXIT_FAILURE);
      cbuf->prod = (cbuf->prod + total) % (CBUFSIZ);
      cbuf->use += total;
    }
  printf("====== writed ======\ntotal : %i\nuse : %i\nprod : %i\n",total, cbuf->use, cbuf->prod);
  if (total == 0)
    return (EXPIPE);
  return (EXIT_SUCCESS);
}
