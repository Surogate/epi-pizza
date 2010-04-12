/*
** my_apply_on_list.c for my_apply_on_list in /u/all/chanio_f/cu/rendu/piscine/Jour_11
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Wed Oct 21 13:55:42 2009 florian chanioux
** Last update Mon Apr 12 19:08:54 2010 Florian Chanioux
*/

#include "my_list.h"

int		my_l_apply(t_list *begin, int (*f)())
{
  while (begin->data != 0)
    {
      f(begin->data);
      begin = begin->next;
    }
  return (0);
}
