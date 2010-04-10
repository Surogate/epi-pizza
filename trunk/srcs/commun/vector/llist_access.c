/*
** llist_access for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Mar 10 11:30:50 2010 francois1 ancel
** Last update Mon Mar 22 06:34:26 2010 lucas1 santamaria
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"s_llist.h"
#include	"s_vector.h"
#include	"llist_access.h"

t_llist		*llist_goto(t_vector *vec, int at)
{
  int		i;
  t_llist	*tmp;

  tmp = vec->start;
  i = 0;
  while (tmp && (i < at))
    {
      tmp = tmp->nxt;
      i++;
    }
  return (tmp);
}

void		*llist_at(t_vector *vec, int at)
{
  t_llist	*tmp;

  tmp = llist_goto(vec, at);
  if (tmp)
    return (tmp->strct);
  return (NULL);
}

void			*llist_getnxts(t_vector *vec)
{
  if (!vec->gns)
    {
      vec->gns = vec->start;
      vec->gns_pos = 0;
    }
  else
    {
      vec->gns = (vec->gns)->nxt;
      vec->gns_pos++;
    }
  if (vec->gns)
    return ((vec->gns)->strct);
  return (vec->gns);
}
