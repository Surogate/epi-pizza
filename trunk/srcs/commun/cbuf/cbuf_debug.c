/*
** cbuf_debug for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sun Mar 21 04:28:58 2010 francois1 ancel
** Last update Mon Mar 22 06:25:20 2010 lucas1 santamaria
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"s_cbuf.h"

void		print_cbuf(t_cbuf *buf)
{
  printf("prod : %i\ncons : %i\nuse : %i\ncontenue : %s\n", 
	 buf->prod, buf->cons, buf->use, buf->buf);
  fflush(stdout);
}
