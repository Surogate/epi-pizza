/*
** my_aff_err.c for  in /u/epitech_2012s/chanio_f/cu/lib/my
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Tue Dec  1 21:52:43 2009 florian chanioux
** Last update Sat Apr  3 18:10:20 2010 Florian Chanioux
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void		my_error(char *str)
{
  fprintf(stderr, "%s %s\n", str, strerror(errno));
}

void		prt_err(char *str)
{
  my_error(str);
  exit(EXIT_FAILURE);
}
