/*
** llist_del.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Mon Apr 26 14:18:08 2010 francois1 ancel
** Last update Mon Apr 26 14:18:08 2010 francois1 ancel
*/

#ifndef LLIST_DEL_C_INCLUDED
# define LLIST_DEL_C_INCLUDED

void		*llist_del(t_vector *vec, int at);
void		llist_erase(t_vector *vec, int at, void (*destruct)());

#endif
