/*
** s_llist for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Mar 10 10:47:38 2010 francois1 ancel
** Last update Mon Mar 22 06:35:24 2010 lucas1 santamaria
*/

#ifndef			__S_LLIST_INCLUDED__
# define		__S_LLIST_INCLUDED__

typedef struct		s_llist
{
  void			*strct;
  struct s_llist	*nxt;
  struct s_llist	*prv;
}			t_llist;

#endif			/*__S_LLIST_INCLUDED__*/
