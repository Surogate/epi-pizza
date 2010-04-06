/*
** main for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Thu Mar 18 14:17:34 2010 francois1 ancel
** Last update Thu Mar 18 14:17:34 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "define.h"
#include "s_cbuf.h"
#include "cbuf_new.h"
#include "cbuf_io.h"

int main()
{
  int fd = open("test.txt", O_RDWR);
  t_cbuf *buf;
  char *readed;

  if (fd < 0)
    {
      perror("open fail :");
      return (EXIT_FAILURE);
    }
  buf = cbuf_new();
  if (!buf)
    {
      perror("buffer create :");
      return (EXIT_FAILURE);
    }
  printf("cbuf->cons : %i\n cbuf->prod : %i\n", buf->cons, buf->prod);
  if (cbuf_write(buf, fd) == EXIT_FAILURE)
    {
      perror("write error :");
      return (EXIT_FAILURE);
    }
  printf("on vient de write\ncbuf->cons : %i\n cbuf->prod : %i\n", buf->cons, buf->prod);
  readed = cbuf_read(buf, &strlen);
  if (readed)
    printf("=========\n%s\n", readed);
  else
    printf("=========\nnoting to read\n");
  printf("==========\napres le read\ncbuf->cons : %i\n cbuf->prod : %i\n", buf->cons, buf->prod);
  if (cbuf_write(buf, fd) == EXIT_FAILURE)
    {
      perror("write error :");
      return (EXIT_FAILURE);
    }
  printf("on vient de write\ncbuf->cons : %i\n cbuf->prod : %i\n", buf->cons, buf->prod);
  readed = cbuf_read(buf, &strlen);
  if (readed)
    printf("=========\n%s\n", readed);
  else
  printf("==========\nnoting to read\n");
  printf("=========\napres le read\ncbuf->cons : %i\n cbuf->prod : %i\n", buf->cons, buf->prod);
  if (cbuf_write(buf, fd) == EXIT_FAILURE)
    {
      perror("write error :");
      return (EXIT_FAILURE);
    }
  printf("on vient de write\ncbuf->cons : %i\n cbuf->prod : %i\n", buf->cons, buf->prod);
  readed = cbuf_read(buf, &strlen);
  if (readed)
    printf("=========\n%s\n", readed);
  else
  printf("==========\nnoting to read\n");
  printf("=========\napres le read\ncbuf->cons : %i\n cbuf->prod : %i\n", buf->cons, buf->prod);
  free(buf);
  close(fd);
  return (EXIT_SUCCESS);
}
