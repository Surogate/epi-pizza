/*
** llist_del for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr 26 14:14:57 2010 francois1 ancel
** Last update Mon Apr 26 14:14:57 2010 francois1 ancel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"s_llist.h"
#include	"s_vector.h"
#include	"llist_access.h"

static void	llist_check(t_vector *vec)
{
  if (vec->size == 0)
    {
      vec->start = NULL;
      vec->gns = NULL;
      vec->gns_pos = 0;
    }
}

void		*llist_del(t_vector *vec, int at)
{
  t_llist	*tmp;
  t_llist	*prv;
  void		*strct;

  tmp = llist_goto(vec, at);
  if ((at == vec->gns_pos) && vec->gns)
    vec->gns = (vec->gns)->prv;
  if (at <= vec->gns_pos)
    --vec->gns_pos;
  if (tmp)
    {
      prv = tmp->prv;
      if (at == 0)
	vec->start = tmp->nxt;
      if (tmp->nxt)
	(tmp->nxt)->prv = prv;
      if (prv)
	prv->nxt = tmp->nxt;
      strct = tmp->strct;
      free(tmp);
      vec->size--;
      llist_check(vec);
      return (strct);
    }
  return (NULL);
}

void		llist_erase(t_vector *vec, int at, void (*destruct)())
{
  void		*strct;

  strct = llist_del(vec, at);
  if (strct)
    destruct(strct);
}
