/*
** my_l_free.c for  in /u/epitech_2012s/chanio_f/cu/lib/my_list
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Mon Nov 30 14:23:30 2009 florian chanioux
** Last update Sat Mar 20 17:55:49 2010 Florian Chanioux
*/

#include <stdlib.h>

#include "my_list.h"

void			my_l_free(t_list *list, void (*func)())
{
  t_list		*tmp;

  while (list != 0)
    {
      tmp = list->next;
      func(list->data);
      free(list);
      list = tmp;
    }
}
