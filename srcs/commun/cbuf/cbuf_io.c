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
#include	<sys/socket.h>
#include	<sys/types.h>
#include	"cbuf_define.h"
#include	"s_cbuf.h"
#include	"cbuf_debug.h"
#include	"cbuf_io.h"

char		*cbuf_read(t_cbuf *cbuf, int (*check_read)())
{
  static char	result[CBUFSIZ];
  int		cmd;

  memset(result, 0, CBUFSIZ);
  if (cbuf->use == 0)
    return (NULL);
  else if (cbuf->prod > cbuf->cons)
    strncpy(result, cbuf->buf + cbuf->cons, cbuf->prod - cbuf->cons);
  else
    {
      strncpy(result, cbuf->buf + cbuf->cons, CBUFSIZ - cbuf->cons);
      strncpy(result + (CBUFSIZ - cbuf->cons), cbuf->buf, cbuf->prod);
    }
  if ((cmd = check_read(result)) != 0)
    {
      cbuf->cons = (cbuf->cons + cmd + 1) % CBUFSIZ;
      cbuf->use -= cmd;
      result[cmd] = '\0';
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
      result = send(sock, from, strlen(from), 0);
      if (result < 0)
	{
	  perror("sock send\n");
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
    perror("sock recv\n");
  return (result);
}

int		cbuf_write(t_cbuf *cbuf, int sock)
{
  int		total;

  if (cbuf->use > CBUFSIZ)
    cbuf_init(cbuf);
  if (cbuf->prod >= cbuf->cons)
    {
      total = sock_read(sock, cbuf->buf + cbuf->prod, CBUFSIZ - cbuf->prod);
      if (total == -1)
	return (EXIT_FAILURE);
    }
  if (cbuf->prod < cbuf->cons)
    {
      total = sock_read(sock, cbuf->buf + cbuf->prod, cbuf->cons - cbuf->prod);
      if (total == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  cbuf->prod = (cbuf->prod + total) % (CBUFSIZ);
  cbuf->use += total;
  if (total == 0)
    return (EXPIPE);
  return (EXIT_SUCCESS);
}
