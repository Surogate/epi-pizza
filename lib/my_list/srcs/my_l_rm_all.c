/*
** my_rm_all_eq_from_list.c for my_rm_all_eq_from_list in /u/epitech_2012s/chanio_f/cu/rendu/piscine/Jour_11
**
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Wed Oct 21 14:56:53 2009 florian chanioux
** Last update Sat Mar 20 17:54:12 2010 Florian Chanioux
*/

#include <stdlib.h>

#include "my_list.h"

void		delete_in_head(t_list **begin)
{
  t_list	*temp;

  temp = *begin ;
  *begin = temp->next;
  free(temp);
}

int		my_l_rm_all(t_list **begin, void *data_ref,
				       int (*cmp)())
{
  t_list	*list;
  t_list	*temp;

  while (cmp((*begin)->data, data_ref) == 0)
    delete_in_head(begin);
  list = *begin;
  while (list->next != 0)
    {
      if (cmp(list->next->data, data_ref) == 0)
	{
	  temp = list->next;
	  list->next = temp->next;
	  free(temp);
	}
      else
	list = list->next;
    }
  return (0);
}
