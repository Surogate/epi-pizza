/*
** my_l_apply_iem.c for  in /u/epitech_2012s/chanio_f/cu/lib/my_list
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Wed Dec  2 04:58:59 2009 florian chanioux
** Last update Wed Dec  2 05:15:12 2009 florian chanioux
*/

#include "my_list.h"

int		my_l_apply_iem(t_list *begin, int iem, int (*f)())
{
  int		i;

  i = 0;
  while (begin != 0)
    {
      if (iem == i)
	{
	  f(begin->data);
	  return (0);
	}
      begin = begin->next;
      i++;
    }
  return (0);
}
