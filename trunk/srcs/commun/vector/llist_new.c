/*
** llist_new for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Mar 10 10:51:23 2010 francois1 ancel
** Last update Mon Mar 22 06:31:21 2010 lucas1 santamaria
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"s_llist.h"
#include	"s_vector.h"
#include	"llist_access.h"

t_llist		*llist_new(void *strct, t_llist *nxt, t_llist *prv)
{
  t_llist	*new;

  new = malloc(sizeof(*new));
  if (new)
    {
      new->strct = strct;
      new->nxt = nxt;
      new->prv = prv;
    }
  return (new);
}

void		llist_des(t_vector *vec, void strct_des())
{
  t_llist	*nxttmp;
  t_llist	*start;

  start = vec->start;
  while (start)
    {
      nxttmp = start->nxt;
      if (start->strct)
	strct_des(start->strct);
      free(start);
      start = nxttmp;
    }
  vec->start = NULL;
  vec->size = 0;
  free(vec);
}

void		llist_display(t_vector *vec, void (*disp)())
{
  t_llist	*tmp;
  int		i;
  FILE		*debug;

  tmp = vec->start;
  i = 0;
  debug = fopen("vector_debug.log", "a");
  if (!debug)
    return ;
  fprintf(debug, "==== Start display =====\n");
  fprintf(debug, "taille : %i\nposition du gns : %i\n", 
	  vec->size, vec->gns_pos);
  while (tmp)
  {
    i++;
    fprintf(debug, "num : %i\nprv : %p, nxt : %p\n", i, 
	   (void *)tmp->prv, (void *)tmp->nxt);
    if (tmp->strct && disp)
      disp(tmp->strct, NULL);
    else
      fprintf(debug, "no struct in");
    tmp = tmp->nxt;
  }
  fprintf(debug, "==== End display =====\n");
  fclose(debug);
}
