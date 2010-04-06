/*
** my_find_node_eq_in_list.c for my_find_node_eq_in_list in /u/epitech_2012s/chanio_f/cu/rendu/piscine/test_jour11
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Wed Oct 21 19:56:41 2009 florian chanioux
** Last update Wed Oct 21 20:01:43 2009 florian chanioux
*/

t_list		*my_find_node_eq_in_list(t_list *begin,
					void *data_ref,
					int (*cmp)())
{
  while (begin != 0)
    {
      if (cmp(begin->data, data_ref) == 0)
	return (begin);
      begin = begin->next;
    }
  return (0);
}
