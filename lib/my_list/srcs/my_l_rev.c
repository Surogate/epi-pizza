/*
** my_rev_list.c for my_rev_list in /u/epitech_2012s/chanio_f/cu/rendu/piscine/Jour_11
**
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
**
** Started on  Tue Oct 20 16:33:27 2009 florian chanioux
** Last update Tue Dec  1 12:06:24 2009 florian chanioux
*/

#include "my_list.h"

static void		my_l_rev_rec(t_list *cur_node,
				     t_list *next_node,
				     t_list **begin)
{
  if (next_node == 0)
    {
      *begin = cur_node;
      (*begin)->next = next_node;
    }
  else
    {
      my_l_rev_rec(cur_node->next, next_node->next, begin);
      cur_node->next = next_node->next;
      next_node->next = cur_node;
    }
}

int		my_l_rev(t_list **begin)
{
  my_l_rev_rec(*begin, (*begin)->next, begin);
  return (0);
}
