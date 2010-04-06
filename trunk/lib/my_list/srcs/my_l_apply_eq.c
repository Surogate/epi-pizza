/*
** my_apply_on_eq_in_list.c for my_apply_on_eq_in_list in /u/all/chanio_f/cu/rendu/piscine/Jour_11
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Wed Oct 21 14:08:07 2009 florian chanioux
** Last update Wed Oct 21 18:12:10 2009 florian chanioux
*/

int		my_apply_on_eq_in_list(t_list *begin,
				       int (*f)(),
				       void *data_ref,
				       int (*cmp)())
{
  while (begin != 0)
    {
      if (cmp(begin->data, data_ref) == 0)
	f(begin->data);
      begin = begin->next;
    }
  return (0);
}
