/*
** cirbuf_new for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Mar 10 13:08:30 2010 francois1 ancel
** Last update Mon Mar 22 06:28:00 2010 lucas1 santamaria
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"cbuf_define.h"
#include	"s_cbuf.h"

t_cbuf		*cbuf_new(void)
{
  t_cbuf	*new;

  new = malloc(sizeof(*new));
  if (new)
    cbuf_init(new);
  return (new);
}

void		cbuf_init(t_cbuf *cbuf)
{
  cbuf->cons = 0;
  cbuf->prod = 0;
  cbuf->use = 0;
  memset(cbuf->buf, 0, 1024);
}
