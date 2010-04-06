/*
** my_add_list_to_list.c for my_add_list_to_list in /u/epitech_2012s/chanio_f/cu/rendu/piscine/Jour_11
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Wed Oct 21 15:37:24 2009 florian chanioux
** Last update Mon Nov 30 14:21:32 2009 florian chanioux
*/

#include "my_list.h"

int		my_l_concat(t_list **begin1,t_list *begin2)
{
  t_list	*temp;

  if (begin1 == 0 || *begin1 == 0)
    {
      *begin1 = begin2;
      return (0);
    }
  temp = *begin1;
  while (temp->next != 0)
    temp = temp->next;
  temp->next = begin2;
  return (0);
}
