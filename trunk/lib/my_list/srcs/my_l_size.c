/*
** my_list_size.c for my_list_size in /u/epitech_2012s/chanio_f/cu/rendu/piscine/Jour_11
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Tue Oct 20 16:03:31 2009 florian chanioux
** Last update Mon Nov 30 14:21:17 2009 florian chanioux
*/

#include "my_list.h"

int		my_l_size(t_list *begin)
{
  int		i;

  i = 0;
  while (begin != 0)
    {
      i = i + 1;
      begin = begin->next;
    }
  return (i);
}
