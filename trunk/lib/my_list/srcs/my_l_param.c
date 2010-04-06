/*
** my_params_in_list.c for my_param_in_list.c in /u/epitech_2012s/chanio_f/cu/rendu/piscine/Jour_11
** 
** Made by florian chanioux
** Login   <chanio_f@epitech.net>
** 
** Started on  Tue Oct 20 15:22:10 2009 florian chanioux
** Last update Mon Nov 30 14:25:54 2009 florian chanioux
*/

#include "my_list.h"

t_list			*my_l_params(int ac,char **av)
{
  int			i;
  t_list		*res;

  i = 0;
  res = 0;
  while (i < ac)
    {
      res = my_l_insert(res, av[i]);
      i = i + 1;
    }
  return (res);
}
