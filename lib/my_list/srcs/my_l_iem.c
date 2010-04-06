/*
** my_list_size.c for my_list_size in /u/epitech_2012s/chanio_f/cu/rendu/piscine/Jour_11
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Tue Oct 20 16:03:31 2009 florian chanioux
** Last update Sat Mar 20 17:57:43 2010 Florian Chanioux
*/

#include <stdlib.h>
#include <stdio.h>

#include "my_list.h"

void		*my_l_iem(t_list *begin, int iem)
{
  int		i;

  i = 0;
  while (begin != 0)
    {
      if ((i + 1) == iem)
        return (begin->data);
      i = i + 1;
      begin = begin->next;
    }
  printf("\n %i: incorrect value of iem.\n", iem);
  exit (1);
}
