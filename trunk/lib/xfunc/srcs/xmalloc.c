/*
** xmalloc.c for  in /u/epitech_2012s/chanio_f/cu/projc/minishell
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Wed Nov 18 11:53:09 2009 florian chanioux
** Last update Sat Apr  3 18:15:59 2010 Florian Chanioux
*/

#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#include "xfunc.h"

void		*xmalloc(size_t size)
{
  void		*mall;

  mall = malloc(size);
  if (mall == 0)
    prt_err("malloc failed");
  memset(mall, 0, size);
  return (mall);
}
