/*
** llist_mod.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Fri Mar 19 14:54:00 2010 francois1 ancel
** Last update Mon Mar 22 06:30:59 2010 lucas1 santamaria
*/

#ifndef		__LLIST_MOD_C_INCLUDED__
# define	__LLIST_MOD_C_INCLUDED__

int		llist_push_back(t_vector *vec, void *strct);
int		llist_push_front(t_vector *vec, void *strct);
int		llist_insert(t_vector *vec, void *strct, int at);
void		llist_erase(t_vector *vec, int at, void (*destruct)());

#endif		/*__LLIST_MOD_C_INCLUDED__*/
