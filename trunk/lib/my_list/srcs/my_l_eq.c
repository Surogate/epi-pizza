/*
** my_find_elm_eq_in_list.c for my_find_elm_eq_in_list in /u/all/chanio_f/cu/rendu/piscine/Jour_11
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Wed Oct 21 14:19:36 2009 florian chanioux
** Last update Wed Oct 21 19:55:01 2009 florian chanioux
*/

void		*my_find_elm_eq_in_list(t_list *begin,
					void *data_ref,
					int (*cmp)())
{
  while (begin != 0)
    {
      if (cmp(begin->data, data_ref) == 0)
	return (begin->data);
      begin = begin->next;
    }
  return (0);
}
