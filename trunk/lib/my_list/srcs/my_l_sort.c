/*
** my_sort_list.c for my_sort_list in /u/epitech_2012s/chanio_f/cu/rendu/piscine/Jour_11
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Wed Oct 21 16:40:07 2009 florian chanioux
** Last update Mon Nov 30 14:22:03 2009 florian chanioux
*/

#include "my_list.h"

int		my_l_sort(t_list **begin,int (*cmp)())
{
  t_list	*tmp;
  t_list	*ref;
  int		swap;

  swap = 1;
  while (swap != 0)
    {
      swap = 0;
      tmp = *begin;
      while (tmp->next != 0)
	{
	  if (cmp(tmp->next->data, (*begin)->data) == 0)
	    {
	      ref = tmp->next;
	      tmp->next = ref->next;
	      ref->next = *begin;
	      *begin = ref;
	      swap = 1;
	    }
	  tmp = tmp->next;
	}
    }
  return (0);
}
