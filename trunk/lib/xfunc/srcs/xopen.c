/*
** xopen.c for  in /u/epitech_2012s/chanio_f/cu/lib/my
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Mon Dec  7 13:31:13 2009 florian chanioux
** Last update Sat Apr  3 18:11:39 2010 Florian Chanioux
*/

#include <fcntl.h>
#include <stdarg.h>

#include "xfunc.h"

int		xopen(char *path, int flags, ...)
{
  va_list	ag;
  int		i;
  int		mode;

  va_start(ag, flags);
  mode = va_arg(ag, int);
  va_end(ag);
  if (mode <= 0777 && mode >= 0)
    i = open(path, flags, mode);
  else
    i = open(path, flags);
  if (i < 0)
    prt_err("open failed");
  return (i);
}
