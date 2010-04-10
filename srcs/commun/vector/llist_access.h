/*
** llist_access.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Mar 10 12:00:03 2010 francois1 ancel
** Last update Mon Mar 22 06:29:58 2010 lucas1 santamaria
*/

#ifndef		__LLIST_ACCESS_C_INCLUDED__
# define	__LLIST_ACCESS_C_INCLUDED__

t_llist		*llist_goto(t_vector *vec, int at);
void		*llist_at(t_vector *vec, int at);
void		*llist_getnxts(t_vector *vec);

#endif		/*LLIST_ACCESS_C_INCLUDED__*/
