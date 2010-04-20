/*
** llist_swap for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr 19 17:01:30 2010 francois1 ancel
** Last update Mon Apr 19 17:01:30 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "s_llist.h"
#include "s_vector.h"
#include "llist_new.h"

void		llist_swap(t_vector *from, t_vector *to, int at)
{
  void		*data;

  data = from->delete(from, at);
  if (data)
    to->insert(to, data, at);
}
