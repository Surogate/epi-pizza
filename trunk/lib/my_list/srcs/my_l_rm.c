/*
** my_l_rm.c for  in /home/Ayden/Epitech/Projet/my_irc/lib/my_list
** 
** Made by Florian Chanioux
** Login   <Ayden@epitech.net>
** 
** Started on  Sat Mar 20 20:34:05 2010 Florian Chanioux
** Last update Sun Mar 21 00:46:04 2010 Florian Chanioux
*/

#include <stdlib.h>

#include "my_list.h"

static t_list	*delete_in_head(t_list *begin)
{
  t_list	*temp;

  temp = begin;
  begin = temp->next;
  free(temp);
  return (begin);
}

t_list		*my_l_rm(t_list *begin, void *data, int(*func)())
{
  t_list	*list;
  t_list	*temp;
  int		i;

  i = 0;
  if ((func(data, begin->data) == 0))
    begin = delete_in_head(begin);
  else
  {
    list = begin;
    while (list->next != NULL)
    {
      if (func(data, list->next->data) == 0)
      {
	temp = list->next;
	list->next = temp->next;
	free(temp);
	return (begin);
      }
      else
	list = list->next;
    }
  }
  return (begin);
}
