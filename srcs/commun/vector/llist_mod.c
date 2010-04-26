/*
** llist_mod for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 19 14:27:58 2010 francois1 ancel
** Last update Mon Mar 22 06:30:19 2010 lucas1 santamaria
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"s_llist.h"
#include	"s_vector.h"
#include	"llist_new.h"
#include	"llist_access.h"

int		llist_push_back(t_vector *vec, void *strct)
{
  t_llist	*new;
  t_llist	*tmp;

  tmp = vec->start;
  if (tmp)
    while(tmp->nxt)
      tmp = tmp->nxt;
  else
    return (vec->push_front(vec, strct));
  new = llist_new(strct, NULL, tmp);
  if (new)
    {
      tmp->nxt = new;
      vec->size++;
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int		llist_push_front(t_vector *vec, void *strct)
{
  t_llist	*new;

  new = llist_new(strct, vec->start, NULL);
  if (new)
    {
      vec->start = new;
      if (new->nxt)
	(new->nxt)->prv = new;
      if (vec->gns_pos)
	++(vec->gns_pos);
      ++(vec->size);
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int		llist_insert(t_vector *vec, void *strct, int at)
{
  t_llist *tmp;
  t_llist *new;

  tmp = llist_goto(vec, at);
  if (tmp)
    {
      new = llist_new(strct, tmp->nxt, tmp);
      if (new)
	{
	  if (tmp->nxt)
	    (tmp->nxt)->prv = new;
	  if (at < vec->gns_pos)
	    ++(vec->gns_pos);
	  tmp->nxt = new;
	  vec->size++;
	  return (EXIT_SUCCESS);
	}
    }
  else
    vec->push_back(vec, strct);
  return (EXIT_FAILURE);
}
