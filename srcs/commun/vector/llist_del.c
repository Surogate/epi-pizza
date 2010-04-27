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

void		llist_detach(t_vector *vec, t_llist *to_det)
{
  t_llist	*prv;

  if (to_det)
    {
      prv = to_det->prv;
      if (!prv)
	vec->start = vec->start->nxt;
      if (to_det->nxt)
	(to_det->nxt)->prv = prv;
      if (prv)
	prv->nxt = to_det->nxt;
    }
}

void		*llist_del(t_vector *vec, int at)
{
  t_llist	*tmp;
  void		*strct;

  tmp = llist_goto(vec, at);
  if ((at == vec->gns_pos) && vec->gns)
    vec->gns = (vec->gns)->prv;
  if (at <= vec->gns_pos)
    --vec->gns_pos;
  if (tmp)
    {
      llist_detach(vec, tmp);
      strct = tmp->strct;
      free(tmp);
      vec->size--;
      llist_check(vec);
      return (strct);
    }
  return (NULL);
}

void			*llist_del_by(t_vector *vec, void *strct, 
				      int (*find_fct)())
{
  static t_llist	*tmp;
  t_llist		*to_del;
  void			*cont;

  if (!tmp)
    tmp = vec->start;
  while (tmp)
    {
      if (tmp->strct && find_fct(tmp->strct, strct))
	{
	  to_del = tmp;
	  tmp = tmp->nxt;
	  llist_detach(vec, to_del);
	  cont = to_del->strct;
	  free(to_del);
	  return (cont);
	}
      else
	tmp = tmp->nxt;
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
