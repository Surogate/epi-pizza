/*
** llist_new.h for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Sun Mar 21 18:48:52 2010 francois1 ancel
** Last update Mon Mar 22 06:33:58 2010 lucas1 santamaria
*/

#ifndef		__LLIST_NEW_C_INCLUDED__
# define	__LLIST_NEW_C_INCLUDED__

t_llist		*llist_new(void *strct, t_llist *nxt, t_llist *prv);
void		llist_des(t_vector *vec, void strct_des());
void		llist_display(t_vector *vec, void (*disp)());

#endif		/*__LLIST_NEW_C_INCLUDED__*/
