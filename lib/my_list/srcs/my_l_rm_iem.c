/*
** my_l_rm_iem.c for  in /u/epitech_2012s/chanio_f/cu/lib/my_list
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Wed Dec  2 03:20:32 2009 florian chanioux
** Last update Sat Mar 20 17:53:07 2010 Florian Chanioux
*/

#include <stdlib.h>

#include "my_list.h"

static void	delete_in_head(t_list **begin, void (*func)())
{
  t_list	*temp;

  temp = *begin ;
  *begin = temp->next;
  func(temp->data);
  free(temp);
}

int		my_l_rm_iem(t_list **begin, int iem,
				       void (*func)())
{
  t_list	*list;
  t_list	*temp;
  int		i;

  i = 0;
  if (i == 0)
    delete_in_head(begin, func);
  list = *begin;
  while (list->next != 0)
    {
      if (i == iem)
	{
	  temp = list->next;
	  list->next = temp->next;
	  func(temp->data);
	  free(temp);
	}
      else
	{
	  i++;
	  list = list->next;
	}
    }
  return (0);
}
