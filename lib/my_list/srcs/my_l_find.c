/*
** my_list_size.c for my_list_size in /u/epitech_2012s/chanio_f/cu/rendu/piscine/Jour_11
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Tue Oct 20 16:03:31 2009 florian chanioux
** Last update Fri Apr  9 14:41:20 2010 Florian Chanioux
*/

#include <stdlib.h>
#include <stdio.h>

#include "my_list.h"

void			*my_l_find(t_list *begin, void *ref, int (*func)())
{
  while (begin != 0)
    {
      if (func(ref, begin->data) == 0)
        return (begin->data);
      begin = begin->next;
    }
  printf("\n ref not found.\n");
  return (NULL);
}
