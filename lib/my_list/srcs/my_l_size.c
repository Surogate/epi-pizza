/*
** my_list_size.c for my_list_size in /u/epitech_2012s/chanio_f/cu/rendu/piscine/Jour_11
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Tue Oct 20 16:03:31 2009 florian chanioux
** Last update Tue Apr  6 18:05:46 2010 Florian Chanioux
*/

#include <stdlib.h>

#include "my_list.h"

int		my_l_size(t_list *begin)
{
  int		i;

  i = 0;
  while (begin->data != NULL)
    {
      i++;
      begin = begin->next;
    }
  return (i);
}
