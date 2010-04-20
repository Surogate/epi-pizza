/*
** vector_new for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Mar 10 11:10:46 2010 francois1 ancel
** Last update Mon Mar 22 06:36:12 2010 lucas1 santamaria
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"s_llist.h"
#include	"s_vector.h"
#include	"llist_new.h"
#include	"llist_access.h"
#include	"llist_mod.h"
#include	"llist_sort.h"
#include	"llist_swap.h"

t_vector	*vector_new(void *strct)
{
  t_vector	*new;

  new = malloc(sizeof(*new));
  if (new)
    {
      if (strct != NULL)
	{
	  new->start = llist_new(strct, NULL, NULL);
	  new->size = 1;
	}
      else
	{
	  new->start = NULL;
	  new->size = 0;
	}
      new->gns = NULL;
      new->gns_pos = 0;
      vector_init(new);
    }
  return (new);
}

void		vector_init(t_vector *new)
{
  new->push_back = llist_push_back;
  new->push_front = llist_push_front;
  new->insert = llist_insert;
  new->at = llist_at;
  new->destruc = llist_des;
  new->getnxts = llist_getnxts;
  new->erase = llist_erase;
  new->delete = llist_del;
  new->insert_sort = llist_insert_sort;
  new->find_pos = llist_find_pos;
  new->swap = llist_swap;
}
