/*
** s_vector for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Wed Mar 10 11:07:55 2010 francois1 ancel
** Last update Mon Mar 22 06:35:47 2010 lucas1 santamaria
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

#ifndef		__S_VECTOR_INCLUDED__
# define	__S_VECTOR_INCLUDED__

typedef struct	s_vector
{
  t_llist	*start;
  int		size;
  t_llist	*gns;
  int		gns_pos;
  int		(*push_back)();
  int		(*push_front)();
  void		*(*at)();
  int		(*insert)();
  void		(*destruc)();
  void		*(*getnxts)();
  void		(*erase)();
}		t_vector;

t_vector	*vector_new();
void		vector_init(t_vector *new);

#endif		/*__S_VECTOR_INCLUDED__*/
