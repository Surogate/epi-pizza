/*
** llist_sort for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Apr 14 12:48:36 2010 francois1 ancel
** Last update Wed Apr 14 12:48:36 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "s_llist.h"
#include "s_vector.h"
#include "llist_new.h"

void		llist_insert_sort(t_vector *vec, void *strct, int (*sort_fct)())
{
  t_llist	*tmp;
  t_llist	*new;
  int		i;

  tmp = vec->start;
  i = 0;
  while (tmp && (tmp->strct) && sort_fct(tmp->strct, strct))
    {
      tmp = tmp->nxt;
      ++i;
    }
  if (!i)
    vec->push_front(vec, strct);
  else if (tmp)
    {
      if ((new = llist_new(strct, tmp, tmp->prv)))
	{
	  if (tmp->prv)
	    (tmp->prv)->nxt = new;
	  tmp->prv = new;
	  vec->size++;
	}
    }
  else
    vec->push_back(vec, strct);
}

int		llist_find_pos(t_vector *vec, void *strct, int (*find_fct)())
{
  t_llist	*tmp;
  int		i;

  tmp = vec->start;
  i = 0;
  while (tmp && (tmp->strct) && !find_fct(tmp->strct, strct))
    {
      tmp = tmp->nxt;
      ++i;
    }
  if (tmp)
    return (i);
  return (-1);
}
