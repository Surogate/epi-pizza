/*
** llist_sort.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Apr 14 14:19:49 2010 francois1 ancel
** Last update Wed Apr 14 14:19:49 2010 francois1 ancel
*/

#ifndef LLIST_SORT_C_INCLUDED
# define LLIST_SORT_C_INCLUDED

void		llist_insert_sort(t_vector *vec, void *strct, int (*sort_fct)());
int		llist_find_pos(t_vector *vec, void *strct, int (*find_fct)());
void		*llist_find_by(t_vector *vec, void *strct, int (*find_fct)());
#endif
