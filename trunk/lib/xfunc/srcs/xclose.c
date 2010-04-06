/*
** xclose.c for  in /u/epitech_2012s/chanio_f/cu/lib/my
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Mon Dec  7 13:54:21 2009 florian chanioux
** Last update Sat Apr  3 18:10:41 2010 Florian Chanioux
*/

#include <unistd.h>

#include "xfunc.h"

int		xclose(int d)
{
  int		i;

  i = close(d);
  if (i < 0)
    prt_err("close failed");
  return (i);
}
